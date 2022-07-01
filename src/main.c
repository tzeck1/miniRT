#include "../includes/miniRT.h"

/**
 * @brief  frees all dynamic allocated memory in and including data
 * @param  *data: data struct
 */
void	free_data(t_data *data)
{
	free_objects(data->objs);
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

int	main(int argc, char **argv)
{
	t_data	*data;
	mlx_t	*mlx;

	if (parser(argc, argv) == false)
		ft_exit(EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	data->objs = init_objects(argv[1]);
	mlx = init_mlx();
	screen_loop(mlx, data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_data(data);
	ft_exit(EXIT_SUCCESS);
}
