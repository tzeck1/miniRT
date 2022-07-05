#include "../../includes/miniRT.h"

static bool	ray_sphere(t_ray ray, t_sp_list *sphere)
{
	t_vector	o_minus_c;
	float		p;
	float		q;
	float		discriminant;
	float		dRoot;
	
	o_minus_c = vector_copy(vector_sub(ray.origin, sphere->center));
	p = vector_dot(ray.direction, o_minus_c);
	q = vector_dot(o_minus_c, o_minus_c) - (sphere->radius * sphere->radius);
	discriminant = (p * p) - q;
	if (discriminant < 0.0f)
	{
		return (false);
	}
	dRoot = sqrtf(discriminant);
	float dist1 = -p - dRoot;
	float dist2 = -p + dRoot;

	if (discriminant > 1e-7)
		return (true);
	return (false);
}

static t_ray	create_ray(t_screen *screen, t_camera *cam, float x, float y)
{
	t_ray	ray;
	float	fov;
	fov = cam->fov * M_PI / 180.0;
	ray.origin.x = x * (2.0 * tanf(fov / 2.0) / (float)screen->width) + cam->position.x - tanf(fov / 2);
	ray.origin.y =  tanf(fov / 2) - y * (2.0 * tanf(fov / 2.0) / (float)screen->height) + cam->position.y;
	ray.origin.z = cam->direction.z;
	// printf("Pixel [%.0f,%.0f]\n", x, y);
	// debug_print_vector(ray.origin);
	// printf("--------------------\n");
	ray.direction = vector_copy(cam->direction);
	ray.t_min = T_MIN;
	ray.t_max = T_MAX;
	return (ray);
}

void	basic_ray(t_screen *screen, t_objects *objs)
{
	int		x;
	int		y;
	t_ray	ray;

	y = 0;
	while (y <= screen->height)
	{
		x = 0;
		while (x <= screen->width)
		{
			ray = create_ray(screen, objs->cam, x, y);
			if (ray_sphere(ray, objs->sp_head))
				mlx_put_pixel(screen->img, x, y, 0x00FFFF);
			else
				mlx_put_pixel(screen->img, x, y, 0x0000FF);
			x++;
		}
		y++;
	}
}
