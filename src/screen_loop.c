#include "../includes/miniRT.h"

void	screen_loop(mlx_t *mlx, t_data *data)
{
	t_mlx_data	*mlx_data;
	int	x;
	int	y;

	mlx_data = data->mlx_data;
	y = 0;
	while (y < mlx_data->height)
	{
		x = 0;
		while (x < mlx_data->width)
		{
			mlx_put_pixel(mlx_data->image, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
}