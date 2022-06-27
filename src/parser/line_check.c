#include "parser.h"

void	ft_parse_error(int error, int line)
{
	if (error == WRONG_TYPE)
		fprintf(stderr, YELLOW"Error[line %d]: Wrong identifier!\n"RESET, line);
	else if (error == MULT_CAM)
		fprintf(stderr, YELLOW"Error[line %d]: Multiple cameras!\n"RESET, line);
	else if (error == MULT_AMB)
		fprintf(stderr, YELLOW"Error[line %d]: Multiple amb_lights!\n"RESET, line);
	else if (error == MULT_DIR)
		fprintf(stderr, YELLOW"Error[line %d]: Multiple dir_lights!\n"RESET, line);
}

static bool	check_obj(char *id, t_parse_errors *parse_errors)
{
	// printf("id: %s\n", id);
	if (ft_strncmp(id, "sp", 3) == 0)
		return (true);
	else if (ft_strncmp(id, "cy", 3) == 0)
		return (true);
	else if (ft_strncmp(id, "pl", 3) == 0)
		return (true);
	else
	{
		ft_parse_error(WRONG_TYPE, parse_errors->line);
		return (false);
	}
}

static bool	check_capital(char *id, t_parse_errors *parse_errors)
{
	// printf("id: %s\n", id);
	if (ft_strncmp(id, "C", 2) == 0 && parse_errors->cam == true)
		ft_parse_error(MULT_CAM, parse_errors->line);
	else if (ft_strncmp(id, "C", 2) == 0)
		parse_errors->cam = true;
	else if (ft_strncmp(id, "A", 2) == 0 && parse_errors->amb_light == true)
		ft_parse_error(MULT_AMB, parse_errors->line);
	else if (ft_strncmp(id, "A", 2) == 0)
		parse_errors->amb_light = true;
	else if (ft_strncmp(id, "L", 2) == 0 && parse_errors->dir_light == true)
		ft_parse_error(MULT_DIR, parse_errors->line);
	else if (ft_strncmp(id, "L", 2) == 0)
		parse_errors->dir_light = true;
	else
		return (false);
	return (true);
}

static bool	id_check(char *id, t_parse_errors *parse_errors)
{
	bool	flag;

	flag = true;
	if (check_capital(id, parse_errors) == false)
		if (check_obj(id, parse_errors) == false)
			return (false);
	return (true);
}

static void	line_content_check(char *line, t_parse_errors *parse_errors)
{
	char	**split_line;

	split_line = ft_split(line, ' ');
	if (id_check(split_line[0], parse_errors) == false)
		return ;
}

static bool	line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i + 1] != '\0')
	{
		if (line[i] != ' ')
			return (false);
		i++;
	}
	if (line[i] != '\n')
		return (false); 
	return (true);
}

bool	line_check(int fd)
{
	char			*line;
	t_parse_errors	*parse_errors;

	line = get_next_line(fd);
	if (line == NULL)
		ft_file_error(EMPTY_MAP, fd);
	parse_errors = ft_calloc(1, sizeof(t_parse_errors));
	while (line != NULL)
	{
		parse_errors->line++;
		if (line_empty(line) == false)
			line_content_check(line, parse_errors);
		free(line);
		line = get_next_line(fd);
	}
}