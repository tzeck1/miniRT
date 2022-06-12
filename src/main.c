#include "../includes/miniRT.h"

void	ft_exit(int status)
{
//	system("leaks miniRT");
	exit(status);
}

void	ft_alloc_error(char *err_msg)
{
	fprintf(stderr, RED_BOLD"Error: %s%s\n", RESET, err_msg);
	ft_exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	// parser(argc, argv);
	data = init_data(argv);
	// test_program();
	ft_exit(EXIT_SUCCESS);
}
