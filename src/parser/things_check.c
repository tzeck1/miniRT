#include "parser.h"

bool	float_check(char *block)
{
	if (ft_isfloat(block) == false)
		return (false);
	return (true);
}

int	ft_count_array(char **xyz_block)
{
	int	i;

	i = 0;
	while (xyz_block[i] != NULL)
		i++;
	return (i);
}

bool	rgb_range_check(char *value)
{
	int	n;

	n = ft_atoi(value);
	if (n < RGB_MIN || n > RGB_MAX)
		return (false);
	else
		return (true);
}

bool	diameter_height_check(char *diameter, t_parse_errors *parse_errors)
{
	if (float_check(diameter) == false)
	{
		ft_parse_error(NO_FLOAT, parse_errors->line);
		parse_errors->error = true;
		return (false);
	}
	return (true);
}

bool	ratio_check(char *ratio, t_parse_errors *parse_errors)
{
	float	n;

	if (float_check(ratio) == false)
	{
		ft_parse_error(NO_FLOAT, parse_errors->line);
		parse_errors->error = true;
		return (false);
	}
	n = ft_atof(ratio);
	if (n < LIGHT_MIN || n > LIGHT_MAX)
	{
		ft_parse_error(BAD_ARG, parse_errors->line);
		parse_errors->error = true;
	}
	if (parse_errors->error == true)
		return (false);
	else
		return (true);
}

bool	rgb_check(char *line, t_parse_errors *parse_errors)
{
	char **rgb_block;

	rgb_block = ft_split(line, ',');	// freed?
	if (ft_count_array(rgb_block) != 3)
	{
		ft_parse_error(BAD_ARG, parse_errors->line);
		parse_errors->error = true;
	}
	else if (rgb_range_check(rgb_block[0]) == false 
			|| rgb_range_check(rgb_block[1]) == false 
			||rgb_range_check(rgb_block[2]) == false )
	{
		ft_parse_error(NO_FLOAT, parse_errors->line);
		parse_errors->error = true;
	}
	if (parse_errors->error == true)
		return (false);
	else
		return (true);
}

bool	normalized_check(char *x_value, char *y_value, char *z_value)
{
	float	x;
	float	y;
	float	z;

	x = ft_atof(x_value);
	y = ft_atof(y_value);
	z = ft_atof(z_value);
	if (x < NO_VEC_MIN || x > NO_VEC_MAX
		|| y < NO_VEC_MIN || y > NO_VEC_MAX
		|| z < NO_VEC_MIN || z > NO_VEC_MAX)
	return (false);	// missing tab?
	else
		return (true);
}

bool	fov_check(char *line, t_parse_errors *parse_error)
{
	float	fov;

	fov = ft_atof(line);
	if (fov < FOV_MIN || fov > FOV_MAX)
	{
		ft_parse_error(BAD_ARG, parse_error->line);
		parse_error->error = true;
	}
	if (parse_error->error == true)
		return (false);
	else
		return (true);
}

bool	orientation_check(char *line, t_parse_errors *parse_errors)
{
	char **vec_block;

	vec_block = ft_split(line, ',');	// freed?
	if (ft_count_array(vec_block) != 3)
	{
		ft_parse_error(BAD_ARG, parse_errors->line);
		parse_errors->error = true;
	}
	else if (float_check(vec_block[0]) == false 
			|| float_check(vec_block[1]) == false
			|| float_check(vec_block[2]) == false)
	{
		ft_parse_error(NO_FLOAT, parse_errors->line);
		parse_errors->error = true;
	}
	else if (normalized_check(vec_block[0], vec_block[1], vec_block[2]) == false)
	{
		ft_parse_error(NO_FLOAT, parse_errors->line);
		parse_errors->error = true;
	}
	if (parse_errors->error == true)
		return (false);
	else
		return (true);
}

bool	xyz_check(char *line, t_parse_errors *parse_errors)
{
	char **xyz_block;

	xyz_block = ft_split(line, ',');	// freed?
	if (ft_count_array(xyz_block) != 3)
	{
		ft_parse_error(BAD_ARG, parse_errors->line);
		parse_errors->error = true;
	}
	else if (float_check(xyz_block[0]) == false
			|| float_check(xyz_block[1]) == false
			|| float_check(xyz_block[2]) == false)
	{
		ft_parse_error(NO_FLOAT, parse_errors->line);
		parse_errors->error = true;
	}
	if (parse_errors->error == true)
		return (false);
	else
		return (true);
}
