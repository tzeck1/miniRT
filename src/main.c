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
	data = init_data(argv);
	// test_program();
	ft_exit(EXIT_SUCCESS);
}
