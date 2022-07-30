#include "../includes/miniRT.h"

// static void	loop_hook(void *param)
// {
// 	t_data	*data;
// 	int32_t	*x;
// 	int32_t	*y;

// 	data = param;

// 	if (mlx_is_key_down(data->screen->mlx, MLX_KEY_UP))
// 		data->objs->cam->pos.z += 1;
// 	if (mlx_is_key_down(data->screen->mlx, MLX_KEY_DOWN))
// 		data->objs->cam->pos.z -= 1;
// 	if (mlx_is_key_down(data->screen->mlx, MLX_KEY_RIGHT))
// 		data->objs->cam->pos.x += 0.1;
// 	if (mlx_is_key_down(data->screen->mlx, MLX_KEY_LEFT))
// 		data->objs->cam->pos.x -= 0.1;
// 	ray_tracing(data->screen, data->objs);
// }

/**
 * @brief  checks if esc key is pressed
 * @param  key_data: contains key info
 * @param  *mlx: mlx pointer
 */
static void	key_hook(mlx_key_data_t	key_data, void *mlx)
{
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window((mlx_t *)mlx);
}

static void	set_background(t_screen *screen)
{
	mlx_image_t	*bg;
	int			x;
	int			y;

	x = 0;
	y = 0;
	bg = mlx_new_image(screen->mlx, screen->width, screen->height);
	while (x < screen->width)
	{
		y = 0;
		while (y < screen->height)
		{
			mlx_put_pixel(bg, x, y, 0x000000FF);
			y++;
		}
		x++;
	}
	mlx_image_to_window(screen->mlx, bg, 0, 0);
	mlx_set_instance_depth(bg->instances, -200);
}

/**
 * @brief  calls mlx_init, key_hook and creates a new image
 * @param  *data: data sctruct, saves mlx pointer and image info
 */
void	init_mlx(t_data *data)
{
	t_screen	*screen;

	screen = ft_calloc(1, sizeof(t_screen));
	screen->width = 750;
	screen->height = 750;
	screen->mlx = mlx_init(screen->width, screen->height, "miniRT", false);
	if (screen->mlx == NULL)
		ft_exit(EXIT_FAILURE);
	mlx_key_hook(screen->mlx, &key_hook, screen->mlx);
	// mlx_loop_hook(screen->mlx, &loop_hook, data);
	screen->img = mlx_new_image(screen->mlx, screen->width, screen->height);
	if (screen->img == NULL)
		ft_exit(EXIT_FAILURE);
	mlx_image_to_window(screen->mlx, screen->img, 0, 0);
	set_background(screen);
	data->screen = screen;
}
