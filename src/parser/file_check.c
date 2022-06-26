#include "parser.h"

/**
 * @brief  prints error message and calls ft_exit()
 * @param  error: error code 
 * @param  fd: close file when an error happens
 */
void	ft_file_error(int error, int fd)
{
	close(fd);
	if (error == ARG_COUNT)
		fprintf(stderr, "Error: Program requires exactly one argument!\n");
	else if (error == WRONG_TYPE)
		fprintf(stderr, "Error: File requires .rt extension!\n");
	else if (error == OPEN_ERR)
		fprintf(stderr, "Error: Cannot open file!\n");
	else if (error == EMPTY_MAP)
		fprintf(stderr, "Error: File feels empty (me too)!\n");
	ft_exit(EXIT_FAILURE);
}

/**
 * @brief  confirms that file ends with .rt
 * @param  *file: file to be checked
 * @retval true if it has .rt, false if not
 */
bool	check_for_rt(char *file)
{
	int	end;

	end = ft_strlen(file) - 1;
	if (file[end - 2] == '.' && file[end - 1] == 'r' && file[end] == 't')
		return (true);
	else
		return (false);
}

/**
 * @brief  checks the given file (.rt, perm, ...)
 * @param  argc: argument count
 * @param  **argv: argv[1] contains file to be checked
 * @retval fd to file (if file is correct)
 */
int	file_check(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_file_error(ARG_COUNT, -1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_file_error(OPEN_ERR, fd);
	if (check_for_rt(argv[1]) == false)
		ft_file_error(WRONG_TYPE, fd);
	return (fd);
}
