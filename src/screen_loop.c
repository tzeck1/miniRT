#include "../includes/miniRT.h"

bool	object_intersect(int x, int y, t_objects *objs)
{
	if (x % 7 == 0 && y % 7 == 0)
		return (true);
	else
		return (false);
}

int	get_color(int x, int y, t_objects *objs)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = 0;
	g = 0;
	b = 0;
	a = 255;
	if (object_intersect(x, y, objs) == true)
	{
		r = objs->sp_head->rgb->red;
		g = objs->sp_head->rgb->green;
		b = objs->sp_head->rgb->blue;
		a = 255;
	}
	return (r << 24 | g << 16 | b << 8 | a);
}

t_vector	*get_ray_direction(float x, float y, t_data *data)
{
	t_vector	*direction;
	float		NDCx;
	float		NDCy;

	NDCx = (x + 0.5) / data->mlx_data->width;
	NDCy = (y + 0.5) / data->mlx_data->height;
	direction = ft_calloc(1, sizeof(t_vector));
	direction->x = 1 - 2 * NDCx;
	direction->y = 1 - 2 * NDCy;
}

void	screen_loop(mlx_t *mlx, t_data *data)
{
	t_mlx_data	*mlx_data;
	int	x;
	int	y;
	int	color;

	mlx_data = data->mlx_data;
	y = 0;
	while (y < mlx_data->height)
	{
		x = 0;
		while (x < mlx_data->width)
		{
			t_ray *ray = ft_calloc(1, sizeof(t_ray));
			ray->origin = data->objs->cam->position;
			ray->direction = get_ray_direction(x, y, data);
			color = get_color(x, y, data->objs);
			mlx_put_pixel(mlx_data->image, x, y, color);
			x++;
		}
		y++;
	}
}