#include "ray_tracer.h"

static t_vector calc_normal(t_tval point, t_objects *objs, t_ray ray)
{
	t_vector	normal;
	t_sp_list	sphere;
	t_pl_list	plane;
	t_cy_list	cylinder;

	if (point.obj_type == SPHERE)
	{
		sphere = *objs->sp_head;
		while(sphere.i != point.obj_i)
			sphere = *sphere.next;
		normal = get_sphere_normal(sphere, point, ray);
	}
	else if (point.obj_type == PLANE)
	{
		plane = *objs->pl_head;
		while(plane.i != point.obj_i)
			plane = *plane.next;
		normal = get_plane_normal(plane, ray);
	}
	else
	{
		cylinder = *objs->cy_head;
		while(cylinder.i != point.obj_i)
			cylinder = *cylinder.next;
		normal = get_cylinder_normal(cylinder, point, ray);
	}
	return (normal);
}

static int	init_shading(t_tval point, t_ray ray, t_objects *objs)
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
	else
	a = vec_dot(normal, light_dir) * 255.999;
	// else if (in_shadow() == false)
		// a = 0;
	return (a);
}

static int	min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

/**
 * @brief  convertes rgb-values into a hex representation
 * @note   0xRRGGBBAA
 * @param  rgb: color struct from an object
 * @retval color in hex representation in int
 */
static int	get_color(t_color rgb, t_amb_light *amb, t_dir_light *dir)
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

/**
 * @brief  creates a ray corresponding to x and y screen position of pixel
 * @param  *screen: mlx data struct
 * @param  *cam: camera object struct
 * @param  x: x-value of pixel on screen
 * @param  y: y-value of pixel on screen
 * @retval ray struct
 */
static t_ray	create_ray(t_screen *screen, t_camera *cam, float x, float y)
{
	t_ray	ray;
	float	fov;

	fov = tanf((cam->fov * M_PI / 180.0) / 2.0);
  
	/*--------------	ORTHOGONAL	--------------*/
	// ray.og.x = x * (2.0 * fov / (float)screen->width) + cam->pos.x - fov;
	// ray.og.y = fov - y * (2.0 * fov / (float)screen->height) + cam->pos.y;
	// ray.og.z = cam->dir.z;
	// ray.dir = vec_copy(cam->dir);

	/*--------------	PINEHOLE	--------------*/
	// x += 0.5;
	// y += 0.5;
	ray.og = vec_copy(cam->pos);
	ray.dir.x = x * (2.0 * fov / (float)screen->width) + cam->pos.x - fov;
	ray.dir.y = fov - y * (2.0 * fov / (float)screen->height) + cam->pos.y;
	ray.dir.z = cam->dir.z;
	ray.dir = vec_norm(ray.dir);

	ray.t_min = 0.1;
	ray.t_max = 1000.0;
	return (ray);
}

/**
 * @brief  calls the object loops and determines the object closest to screen
 * @param  ray: ray to calculate the intersections with
 * @param  *objs: objects data struct
 * @retval informations to the object closest to screen
 */
static t_tval	intersection(t_ray ray, t_objects *objs)
{
	t_tval	sp_tval;
	t_tval	pl_tval;
	t_tval	cy_tval;
	t_tval	result;

	sp_tval.t = 1.0 / 0.0;
	pl_tval.t = 1.0 / 0.0;
	cy_tval.t = 1.0 / 0.0;
	result.t = 1.0 / 0.0;
	if (objs->sp_head != NULL)
		sp_tval = sphere_loop(ray, objs);
	if (sp_tval.t < result.t)
		result = sp_tval;
	if (objs->pl_head != NULL)
		pl_tval = plane_loop(ray, objs);
	if (pl_tval.t < result.t)
		result = pl_tval;
	if (objs->cy_head != NULL)
		cy_tval = cylinder_loop(ray, objs);
	if (cy_tval.t < result.t)
		result = cy_tval;
	if (result.t != 1.0 / 0.0)
		result.rgb.a = init_shading(result, ray, objs);
	return (result);
}

/**
 * @brief  Loops through every pixel and calculates their color with ray tracing
 * @param  *screen: mlx data struct
 * @param  *objs: objects data struct
 */
void	ray_tracing(t_screen *screen, t_objects *objs)
{
	int		x;
	int		y;
	t_ray	ray;
	t_tval	tval;

	y = 0;
	while (y < screen->height)
	{
		x = 0;
		while (x < screen->width)
		{
			ray = create_ray(screen, objs->cam, x, y);
			tval = intersection(ray, objs);
			if (tval.t != 1.0 / 0.0)
				mlx_put_pixel(screen->img, x, y, get_color(tval.rgb, objs->amb_l, objs->dir_l));
			else
				mlx_put_pixel(screen->img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}
