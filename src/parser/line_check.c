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
	else if (error == BAD_ARG)
		fprintf(stderr, YELLOW"Error[line %d]: Bad object info!\n"RESET, line);
	else if (error == NO_FLOAT)
		fprintf(stderr, YELLOW"Error[line %d]: No number given!\n"RESET, line);
}

bool	check_pl_line(char **line, t_parse_errors *parse_errors)
{
	if (xyz_check(line[PL_XYZ], parse_errors) == false)
		return (false);
	else if (orientation_check(line[PL_NO_VEC], parse_errors) == false)
		return (false);
	else if (rgb_check(line[PL_RGB], parse_errors) == false)
		return (false);
	else
		return (true);
}

bool	check_cy_line(char **line, t_parse_errors *parse_errors)
{
	if (xyz_check(line[CY_XYZ], parse_errors) == false)
		return (false);
	else if (orientation_check(line[CY_NO_VEC], parse_errors) == false)
		return (false);
	else if (diameter_height_check(line[CY_DIA], parse_errors) == false)
		return (false);
	else if (diameter_height_check(line[CY_HEIGHT], parse_errors) == false)
		return (false);
	else if (rgb_check(line[CY_RGB], parse_errors) == false)
		return (false);
	else
		return (true);
}

bool	check_sp_line(char **line, t_parse_errors *parse_errors)
{
	if (xyz_check(line[SP_XYZ], parse_errors) == false)
		return (false);
	else if (diameter_height_check(line[SP_DIA], parse_errors) == false)
		return (false);
	else if (rgb_check(line[SP_RGB], parse_errors) == false)
		return (false);
	else
		return (true);
}

bool	check_dir_line(char **line, t_parse_errors *parse_errors)
{
	if (xyz_check(line[DIR_XYZ], parse_errors) == false)
		return (false);
	else if (ratio_check(line[DIR_RATIO], parse_errors) == false)
		return (false);
	else if (rgb_check(line[DIR_RGB], parse_errors) == false)
		return (false);
	else
		return (true);
}

bool	check_amb_line(char **line, t_parse_errors *parse_errors)
{
	if (ratio_check(line[AMB_RATIO], parse_errors) == false)
		return (false);
	else if (rgb_check(line[AMB_RGB], parse_errors) == false)
		return (false);
	else
		return (true);
}

bool	check_cam_line(char **line, t_parse_errors *parse_errors)
{
	if (xyz_check(line[CAM_XYZ], parse_errors) == false)
		return (false);
	else if (orientation_check(line[CAM_NO_VEC], parse_errors) == false)
		return (false);
	else if (fov_check(line[CAM_FOV], parse_errors) == false)
		return (false);
	else
		return (true);
}

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
	if (parse_errors->error == true)
		return (false);
	return (true);
}
