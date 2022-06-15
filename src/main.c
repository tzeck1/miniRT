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
	printf("exited with exit status: %d\n", status);
	exit(status);
}

int	main(int argc, char **argv)
{
	clock_t begin = clock();
	t_data	*data;
	// parser(argc, argv);
	if (argc != 2)
	{
		printf(RED_BOLD"PLESE JUST REMEMBER ONE FUCKING PARAMETER!\n"RESET);
		ft_exit(EXIT_FAILURE);
	}
	data = ft_calloc(1, sizeof(t_data)); //free
	data->objs = init_objects(argv);
	// debug_print_ambient_light(data->objs->amb_l);
	// debug_print_camera(data->objs->cam);
	// debug_print_cylinder_list(data->objs->cy_head);
	// debug_print_sphere_list(data->objs->sp_head);
	// debug_print_plane_list(data->objs->pl_head);
	free_data(data);
	clock_t end = clock();
	printf(BLUE"\nRUNTIME: %.4f sec\n\n"RESET, (double)(end - begin) / CLOCKS_PER_SEC);
	ft_exit(EXIT_SUCCESS);
}
