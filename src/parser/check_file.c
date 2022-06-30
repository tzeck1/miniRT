#include "parser.h"

/**
 * @brief  confirms that file ends with .rt
 * @param  *file: file to be checked
 * @retval true if it has .rt, false if not
 */
static bool	check_for_rt(char *file)
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
	if (check_for_rt(argv[1]) == false)
		ft_file_error(NO_RT, fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_file_error(OPEN_ERR, fd);
	return (fd);
}
