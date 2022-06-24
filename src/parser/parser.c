#include "parser.h"

static void	check_line(char **line)
{

}

static int	general_check(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_pars_error(ARG_COUNT);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_pars_error(OPEN_ERR);
	if (check_emptiness(fd) == EXIT_FAILURE)
		ft_pars_error(EMPTY_MAP);
}

void	parser(int argc, char **argv)
{
	int 	fd;
	char	*line;
	char	**split_line;

	fd = general_check(argc, argv);
	line = get_next_line(fd);
	while (line != NULL)
	{
		split_line = ft_split(line, ' ');
		if (split_line == NULL)
			ft_alloc_error(strerror(errno));
		check_line(split_line);
		ft_free_split(split_line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}