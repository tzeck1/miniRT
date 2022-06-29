#include "parser.h"

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