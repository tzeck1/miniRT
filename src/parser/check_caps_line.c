#include "parser.h"

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