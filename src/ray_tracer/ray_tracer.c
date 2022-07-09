#include "ray_tracer.h"

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

static t_ray	create_ray(t_screen *screen, t_camera *cam, float x, float y)
{
	t_ray	ray;
	float	fov;

	fov = tanf((cam->fov * M_PI / 180.0) / 2.0);
	ray.origin.x = x * (2.0 * fov / (float)screen->width) + cam->position.x - fov;
	ray.origin.y = fov - y * (2.0 * fov / (float)screen->height) + cam->position.y;
	ray.origin.z = cam->direction.z;
	ray.direction = vector_copy(cam->direction);
	ray.t_min = T_MIN;
	ray.t_max = T_MAX;
	return (ray);
}

static t_tval	intersection(t_ray ray, t_objects *objs)
{
	t_tval	tval;

	tval = sphere_loop(ray, objs);
	return (tval);
}

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
				mlx_put_pixel(screen->img, x, y, get_color(tval.rgb));
			else
				mlx_put_pixel(screen->img, x, y, 0x0000FF);
			x++;
		}
		y++;
	}
}
