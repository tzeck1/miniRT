#include "ray_tracer.h"

/**
 * @brief  convertes rgb-values into a hex representation
 * @note   0xRRGGBBAA
 * @param  rgb: color struct from an object
 * @retval color in hex representation in int
 */
static int	get_color(t_color rgb)
{
	int	red;
	int	green;
	int	blue;
	unsigned int a;
	uint32_t		res;

	red = 255 << 24;
	green = 255 << 16;
	blue = 255 << 8;
	a = rgb.a;
	// printf("red %d, green %d, blue %d, a %f\n", red, green, blue, a);
	res = red | green | blue | a;
	// printf("Color: %X\n", res);
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

	// ray.og.x = x * (2.0 * fov / (float)screen->width) + cam->pos.x - fov;
	// ray.og.y = fov - y * (2.0 * fov / (float)screen->height) + cam->pos.y;
	// ray.og.z = cam->dir.z;
	// ray.dir = vec_copy(cam->dir);

	ray.og = vec_copy(cam->pos);
	ray.dir.x = x * (2.0 * fov / (float)screen->width) + cam->pos.x - fov;
	ray.dir.y = fov - y * (2.0 * fov / (float)screen->height) + cam->pos.y;
	ray.dir.z = cam->dir.z;
	ray.dir = vec_norm(ray.dir);

	ray.t_min = T_MIN;
	ray.t_max = T_MAX;
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

	sp_tval.t = 1.0 / 0.0;
	pl_tval.t = 1.0 / 0.0;
	cy_tval.t = 1.0 / 0.0;
	if (objs->sp_head != NULL)
		sp_tval = sphere_loop(ray, objs);
	if (objs->pl_head != NULL)
		pl_tval = plane_loop(ray, objs);
	if (objs->cy_head != NULL)
		cy_tval = cylinder_loop(ray, objs);
	// if (sp_tval.t < pl_tval.t)
	// 	return (sp_tval);
	// else
	return (cy_tval);
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
			if (x == 375 && y == 375)
				mlx_put_pixel(screen->img, x, y, 0xFF0000FF);
			else if (tval.t != 1.0 / 0.0)
				mlx_put_pixel(screen->img, x, y, + get_color(tval.rgb));
			else
				mlx_put_pixel(screen->img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}
