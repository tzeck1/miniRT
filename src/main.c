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
	data = ft_calloc(1, sizeof(char));
	data->objs = init_objects(argv);
	// test_program();
	// free data struct
	ft_exit(EXIT_SUCCESS);
}
