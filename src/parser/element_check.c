#include "parser.h"

bool	rgb_range_check(char *value)
{
	int	n;

	if (ft_isint(value) == false)
		return (false);
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

	rgb_block = ft_split(line, ',');
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
	ft_free_split(rgb_block);
	if (parse_errors->error == true)
		return (false);
	else
		return (true);
}