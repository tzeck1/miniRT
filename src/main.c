#include "../includes/miniRT.h"

void	ft_exit(int status)
{
//	system("leaks miniRT");
	exit(status);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	// parser(argc, argv);
	if (argc != 2)
	{
		printf(RED_BOLD"PLESE JUST REMEMBER ONE FUCKING PARAMETER!"RESET);
		ft_exit(EXIT_FAILURE);
	}
	data = ft_calloc(1, sizeof(t_data));	//free
	data->objs = init_objects(argv);
	printf("identifier:\t%i\n", data->objs->amb_l->identifier);
	printf("ratio:\t\t%f\n", data->objs->amb_l->ratio);
	printf("red:\t\t%i\n", data->objs->amb_l->rgb->red);
	printf("green:\t\t%i\n", data->objs->amb_l->rgb->green);
	printf("blue:\t\t%i\n", data->objs->amb_l->rgb->blue);
	printf("identifier:\t%i\n", data->objs->cam->identifier);
	printf("identifier:\t%i\n", data->objs->dir_l->identifier);
	printf("position_x:\t%f\n", data->objs->cam->position->x);

	// test_program();
	ft_exit(EXIT_SUCCESS);
}
