#include "parser.h"

static bool	valid_line(char **line, t_parse_errors *parse_errors)
{
	bool	flag;

	flag = true;
	if (ft_strncmp(line[0], "C", 2) == 0)
		flag = check_cam_line(line, parse_errors);
	else if (ft_strncmp(line[0], "A", 2) == 0)
		flag = check_amb_line(line, parse_errors);
	else if (ft_strncmp(line[0], "L", 2) == 0)
		flag = check_dir_line(line, parse_errors);
	else if (ft_strncmp(line[0], "sp", 3) == 0)
		flag = check_sp_line(line, parse_errors);
	else if (ft_strncmp(line[0], "cy", 3) == 0)
		flag = check_cy_line(line, parse_errors);
	else if (ft_strncmp(line[0], "pl", 3) == 0)
		flag = check_pl_line(line, parse_errors);
	if (flag == false)
		return (false);
	else
		return (true);
}

static bool	check_obj(char *id, t_parse_errors *parse_errors)
{
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
	if (check_capital(id, parse_errors) == false)
		if (check_obj(id, parse_errors) == false)
			return (false);
	return (true);
}

void	line_content_check(char *line, t_parse_errors *parse_errors)
{
	char	**split_line;

	split_line = ft_split(line, ' ');
	if (id_check(split_line[0], parse_errors) == false)
	{
		parse_errors->error = true;
		ft_free_split(split_line);
		return ;
	}
	if (valid_line(split_line, parse_errors) == false)
	{
		parse_errors->error = true;
		ft_free_split(split_line);
		return ;
	}
	ft_free_split(split_line);
}
