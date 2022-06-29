#include "parser.h"

/**
 * @brief  prints error message if to few capital letter objects in rt file
 * @param  *parse_errors: parse error bool struct
 * @retval false if no camera and/or no light sources, true otherwise
 */
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

/**
 * @brief  check the rt file line by line
 * @param  fd: file descriptor of rt file
 * @retval false if any misconfiguration occurs, true otherwise
 */
static bool	line_check(int fd)
{
	char			*line;
	t_parse_errors	*parse_errors;

	line = get_next_line(fd);
	if (line == NULL)
		ft_file_error(EMPTY_MAP, fd);
	parse_errors = ft_calloc(1, sizeof(t_parse_errors));
	while (line != NULL)
	{
		parse_errors->error = false;
		parse_errors->line++;
		if (line_empty(line) == false)
			line_content_check(line, parse_errors);
		free(line);
		line = get_next_line(fd);
	}
	if (min_objects(parse_errors) == false)
		return (false);
	if (parse_errors->exit == true)
		return (false);
	return (true);
}

/**
 * @brief  checks for any misconfigurations and ensures a secure run of miniRT
 * @param  argc: argument count
 * @param  **argv: argv[1] relative path to rt file
 * @retval false if any misconfiguration occurs, true otherwise
 */
bool	parser(int argc, char **argv)
{
	int				fd;
	t_parse_errors	*parse_errors;

	fd = file_check(argc, argv);
	parse_errors = ft_calloc(1, sizeof(t_parse_errors));
	if (line_check(fd) == true)
	{
		free(parse_errors);
		return (true);
	}
	else
	{
		free(parse_errors);
		return (false);
	}
}
