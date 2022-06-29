#include "parser.h"

static bool	line_check(int fd)
{
	char			*line;
	t_parse_errors	*parse_errors;

	line = get_next_line(fd);
	if (line == NULL)
		ft_file_error(EMPTY_MAP, fd);
	parse_errors = ft_calloc(1, sizeof(t_parse_errors));	// freed?
	while (line != NULL)
	{
		parse_errors->line++;	// the name 'line' is extremly confusing in the functions context
		if (line_empty(line) == false)
			line_content_check(line, parse_errors);
		//	if first (or more) line is only with spaces but then nothing thereafter
		// (next_line == NULL) then we dont detect an error
		free(line);
		line = get_next_line(fd);
	}
	if (parse_errors->error == true)
		return (false);
	return (true);
}

bool	parser(int argc, char **argv)
{
	int		fd;

	fd = file_check(argc, argv);
	if (line_check(fd) == true)
		return (true);
	else
		return (false);
}
