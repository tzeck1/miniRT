#include "../includes/miniRT.h"

bool	object_intersect(int x, int y, t_objects *objs)
{

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
	a = 1;
	if (object_intersect(x, y, objs) == true)
	{
		r = objs->sp_head->rgb->red;
		g = objs->sp_head->rgb->green;
		b = objs->sp_head->rgb->blue;
		a = 1;
	}
	return (r << 24 | g << 16 | b << 8 | a)
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
			ray->direction = data->objs->cam->direction;
			color = get_color(x, y, data->objs);
			mlx_put_pixel(mlx_data->image, x, y, color);
			x++;
		}
		y++;
	}
}