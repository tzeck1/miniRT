#include "../includes/miniRT.h"

/**
 * @brief  frees all dynamic allocated memory in and including data
 * @param  *data: data struct
 */
void	free_data(t_data *data)
{
	free_objects(data->objs);
	free(data->screen);
	free(data);
	data = NULL;
}

/**
 * @brief  always call when using exit
 * @note   leaks check, free, ...
 * @param  status: exit status
 */
void	ft_exit(int status)
{
	system("leaks miniRT");
	if (status == 0)
		printf(GREEN"exited with exit status: %d\n"RESET, status);
	else
		printf(RED"exited with exit status: %d\n"RESET, status);
	exit(status);
}

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

/**
 * @brief  calls mlx_init, key_hook and creates a new image
 * @param  *data: data sctruct, saves mlx pointer and image info
 */
static void	init_mlx(t_data *data)
{
	t_screen	*screen;

	screen = ft_calloc(1, sizeof(t_screen));
	screen->width = 750;
	screen->height = 750;
	screen->mlx = mlx_init(screen->width, screen->height, "miniRT", false);
	if (screen->mlx == NULL)
		ft_exit(EXIT_FAILURE);
	mlx_key_hook(screen->mlx, &key_hook, screen->mlx);
	screen->img = mlx_new_image(screen->mlx, screen->width, screen->height);
	if (screen->img == NULL)
		ft_exit(EXIT_FAILURE);
	mlx_image_to_window(screen->mlx, screen->img, 0, 0); // maybe change later
	data->screen = screen;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (parser(argc, argv) == false)
		ft_exit(EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	data->objs = init_objects(argv[1]);
	init_mlx(data);
	mlx_image_t *bg = mlx_new_image(data->screen->mlx, data->screen->width, data->screen->height);
	for (int x = 0; x < data->screen->width; x++)
	{
		for (int y = 0; y < data->screen->height; y++)
		{
			mlx_put_pixel(bg, x, y, 0x000000FF);
		}
	}
	mlx_image_to_window(data->screen->mlx, bg, 0, 0);
	mlx_set_instance_depth(bg->instances, -200);
	ray_tracing(data->screen, data->objs);
	mlx_loop(data->screen->mlx);
	mlx_terminate(data->screen->mlx);
	free_data(data);
	ft_exit(EXIT_SUCCESS);
}
