#include "parser.h"

static bool	min_objects(t_parse_errors *parse_errors)
{
	bool	flag;

	flag = true;
	if (parse_errors->cam == false)
	{
		ft_parse_error(NO_CAM, parse_errors->line);
		flag = false;
	}
	if (parse_errors->dir_light == false && parse_errors->amb_light == false)
	{
		ft_parse_error(NO_LIGHT, parse_errors->line);
		flag = false;
	}
	if (flag == false)
		return (false);
	else
		return (true);
}

static bool	line_check(int fd)
{
	char			*line;
	t_parse_errors	*parse_errors;

	line = get_next_line(fd);
	if (line == NULL)
		ft_file_error(EMPTY_MAP, fd);
	parse_errors = ft_calloc(1, sizeof(t_parse_errors));	// freed?
	printf("before line: %d\n", parse_errors->line);
	while (line != NULL)
	{
		parse_errors->line++;	// the name 'line' is extremly confusing in the functions context
		printf("line: %d\n", parse_errors->line);
		if (line_empty(line) == false)
			line_content_check(line, parse_errors);
		//	if first (or more) line is only with spaces but then nothing thereafter
		// (next_line == NULL) then we dont detect an error
		free(line);
		line = get_next_line(fd);
	}
	if (min_objects(parse_errors) == false)
		return (false);
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
