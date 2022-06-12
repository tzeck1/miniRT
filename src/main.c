#include "../includes/miniRT.h"

void	ft_exit(int status)
{
//	system("leaks miniRT");
	exit(status);
}

void	ft_error(char *err_msg, char *arg_msg)
{
	// write(STDERR_FILENO, RED, 1);
	// write(STDERR_FILENO, RED"Error: "RESET, 12);
	// write(STDERR_FILENO, RESET, 1);
	write(STDERR_FILENO, ERROR, ft_strlen(ERROR));
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, ERROR_LIGHT, ft_strlen(ERROR_LIGHT));
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	if (arg_msg != NULL)
		write(STDERR_FILENO, arg_msg, ft_strlen(arg_msg));
	write(STDERR_FILENO, "\n", 1);
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
