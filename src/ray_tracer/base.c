#include "../../includes/miniRT.h"

static int	count_spheres(t_sp_list *sp_head)
{
	t_sp_list	*tmp;
	int			count;

	if (sp_head->i == sp_head->next->i)
		return (1);
	tmp = sp_head->prev;
	count = 0;
	while (sp_head != tmp)
	{
		sp_head = sp_head->next;
		count++;
	}
	sp_head = sp_head->next;
	return (count + 1);
}

static int	get_color(t_color rgb)
{
	int	red;
	int	green;
	int	blue;
	int	a;

	red = rgb.red << 24;
	green = rgb.green << 16;
	blue = rgb.blue << 8;
	a = 255;
	return (red | green | blue | a);
}

static float	ray_sphere(t_ray ray, t_sp_list *sphere)
{
	float	a;
	float	b;
	float	c;
	float	dist;

	a = vector_dot(ray.direction, ray.direction);
	b = 2.0 * vector_dot(ray.direction, vector_sub(ray.origin, sphere->center));
	c = powf(vector_length(vector_sub(ray.origin, sphere->center)), 2.0) - powf(sphere->radius, 2.0);
	dist = b * b - 4.0f * a * c;
	if (dist > 0)
	{
		if ((-b + sqrtf(dist)) / (2 * a) < (-b - sqrtf(dist)) / (2 * a))
			return ((-b + sqrtf(dist)) / (2 * a));
		else
			return ((-b - sqrtf(dist)) / (2 * a));
	}
	else if (dist == 0)
		return ((-b + sqrtf(dist)) / (2 * a));
	else
		return (1.0 / 0.0);
}

static t_ray	create_ray(t_screen *screen, t_camera *cam, float x, float y)
{
	t_ray	ray;
	float	fov;
	fov = cam->fov * M_PI / 180.0;
	ray.origin.x = x * (2.0 * tanf(fov / 2.0) / (float)screen->width) + cam->position.x - tanf(fov / 2);
	ray.origin.y =  tanf(fov / 2) - y * (2.0 * tanf(fov / 2.0) / (float)screen->height) + cam->position.y;
	ray.origin.z = cam->direction.z;
	ray.direction = vector_copy(cam->direction);
	ray.t_min = T_MIN;
	ray.t_max = T_MAX;
	return (ray);
}

static t_tval	intersection(t_ray ray, t_objects *objs)
{
	t_tval	tval;
	int		sp_last_i;
	int		i;
	float	t;

	i = 0;
	tval.t = 1.0 / 0.0;
	sp_last_i = count_spheres(objs->sp_head);
	while (i != sp_last_i)
	{
		t = ray_sphere(ray, objs->sp_head);
		if (t < tval.t)
		{
			tval.t = t;
			tval.rgb = objs->sp_head->rgb;
		}
		objs->sp_head = objs->sp_head->next;
		i++;
	}
	return (tval);
}

void	basic_ray(t_screen *screen, t_objects *objs)
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
				mlx_put_pixel(screen->img, x, y, get_color(tval.rgb));
			else
				mlx_put_pixel(screen->img, x, y, 0x0000FF);
			x++;
		}
		y++;
	}
}
