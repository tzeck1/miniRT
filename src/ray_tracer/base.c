#include "../../includes/miniRT.h"

static t_ray	create_ray(t_screen *screen, t_camera *cam, float x, float y)
{
	t_ray	ray;

	ray.origin.x = (x * (2.0 / (float)screen->width) + cam->position.x) - 1.0;
	ray.origin.y = 1.0 - y * (2.0 / (float)screen->height) + cam->position.y;
	ray.origin.z = cam->position.z + 1;
	// printf("Pixel [%.0f,%.0f]\n", x, y);
	// debug_print_vector(ray.origin);
	// printf("--------------------\n");
	ray.direction.x = cam->direction.x;
	ray.direction.y = cam->direction.y;
	ray.direction.z = cam->direction.z;
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
			x++;
		}
		y++;
	}
}
