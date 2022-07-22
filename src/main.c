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
	// system("leaks miniRT");
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
	ray_tracing(data->screen, data->objs);
	mlx_loop(data->screen->mlx);
	mlx_terminate(data->screen->mlx);
	free_data(data);
	
	// t_vector	vec;
	// t_vector	C;
	// t_vector	r_og;
	// float		hc;
	// float		hi;
	// float		hr;
	// float		t;
	// float		alpha;

	// vec = vec_new(-1.6,0,8);
	// vec = vec_norm(vec);
	// C = vec_new(0,0,0);
	// r_og = vec_new(1.6,0,-8);
	// alpha = acosf(vec.z);
	// hc = sinf(alpha) * vec_len(vec_sub(C,r_og));
	// hi = sqrtf(powf(2.0,2.0) - powf(hc, 2));
	// hr = hc / tanf(alpha);
	// t = hr - hi;
	// printf("[%.8f]\n", t);
	// printf("dot_product -> [%f]\n", res);


	ft_exit(EXIT_SUCCESS);
}
