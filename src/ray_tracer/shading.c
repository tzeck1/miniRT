#include "ray_tracer.h"

static bool	in_shadow(t_objects *objs, t_vector hit_point)
{
	t_ray	ray;
	t_tval	result;

	ray.og = hit_point;
	ray.dir = vec_norm(vec_sub(objs->dir_l->pos, hit_point));
	ray.t_min = 0.01;
	ray.t_max = vec_len(vec_sub(hit_point, objs->dir_l->pos));
	result = intersection(ray, objs, false);
	if (result.t == 1.0 / 0.0)
		return (true);
	else
		return (false);
}

static t_vector	calc_normal(t_tval point, t_objects *objs, t_ray ray)
{
	t_sp_list	sphere;
	t_pl_list	plane;
	t_cy_list	cylinder;

	if (point.obj_type == SPHERE)
	{
		sphere = *objs->sp_head;
		while (sphere.i != point.obj_i)
			sphere = *sphere.next;
		return (get_sphere_normal(sphere, point, ray));
	}
	else if (point.obj_type == PLANE)
	{
		plane = *objs->pl_head;
		while (plane.i != point.obj_i)
			plane = *plane.next;
		return (get_plane_normal(plane, ray));
	}
	else
	{
		cylinder = *objs->cy_head;
		while (cylinder.i != point.obj_i)
			cylinder = *cylinder.next;
		return (get_cylinder_normal(cylinder, point, ray));
	}
}

int	init_shading(t_tval point, t_ray ray, t_objects *objs)
{
	int			a;
	t_vector	normal;
	t_vector	light_dir;

	if (objs->dir_l == NULL)
		return (0);
	point.hit_point = vec_add(ray.og, vec_scale(ray.dir, point.t));
	normal = calc_normal(point, objs, ray);
	light_dir = vec_norm(vec_sub(objs->dir_l->pos, point.hit_point));
	if (vec_dot(normal, light_dir) < 0)
		a = 0;
	else if (in_shadow(objs, point.hit_point) == false)
		a = 0;
	else
		a = vec_dot(normal, light_dir) * 255.999;
	return (a);
}

/**
 * @brief  convertes rgb-values into a hex representation
 * @note   0xRRGGBBAA
 * @param  rgb: color struct from an object
 * @retval color in hex representation in int
 */
int	get_color(t_color rgb, t_amb_light *amb, t_dir_light *dir)
{
	int				red;
	int				green;
	int				blue;
	int				a;
	uint32_t		res;

	red = min(rgb.red + (amb->rgb.red * amb->ratio), 255) << 24;
	green = min(rgb.green + (amb->rgb.green * amb->ratio), 255) << 16;
	blue = min(rgb.blue + (amb->rgb.blue * amb->ratio), 255) << 8;
	a = min((rgb.a * dir->ratio) + (255 * amb->ratio), 255);
	res = red | green | blue | a;
	return (res);
}
