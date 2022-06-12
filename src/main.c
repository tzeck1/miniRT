#include "../includes/miniRT.h"

void	ft_exit(int status)
{
//	system("leaks miniRT");
	printf("exited with exit status: %d\n", status);
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
	

	// test_program();
	ft_exit(EXIT_SUCCESS);
}
