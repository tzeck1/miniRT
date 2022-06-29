#include "parser.h"

/**
 * @brief  checks direct light line for errors (calls sub functions)
 * @param  **line: direct light object line
 * @param  *parse_errors: parser struct
 * @retval bool if aight, false if error in block
 */
bool	check_dir_line(char **line, t_parse_errors *parse_errors)
{
	if (ft_count_array(line) != DIR_LINE_SIZE)
	{
		ft_parse_error(BAD_ARG, parse_errors->line);
		return (false);
	}
	else if (xyz_check(line[DIR_XYZ], parse_errors) == false)
		return (false);
	else if (ratio_check(line[DIR_RATIO], parse_errors) == false)
		return (false);
	else if (rgb_check(line[DIR_RGB], parse_errors) == false)
		return (false);
	else
		return (true);
}

/**
 * @brief  checks ambient light line for errors (calls sub functions)
 * @param  **line: ambient light object line
 * @param  *parse_errors: parser struct
 * @retval bool if aight, false if error in block
 */
bool	check_amb_line(char **line, t_parse_errors *parse_errors)
{
	if (ft_count_array(line) != AMB_LINE_SIZE)
	{
		ft_parse_error(BAD_ARG, parse_errors->line);
		return (false);
	}
	else if (ratio_check(line[AMB_RATIO], parse_errors) == false)
		return (false);
	else if (rgb_check(line[AMB_RGB], parse_errors) == false)
		return (false);
	else
		return (true);
}

/**
 * @brief  checks cam line for errors (calls sub functions)
 * @param  **line: cam object line
 * @param  *parse_errors: parser struct
 * @retval bool if aight, false if error in block
 */
bool	check_cam_line(char **line, t_parse_errors *parse_errors)
{
	if (ft_count_array(line) != CAM_LINE_SIZE)
	{
		ft_parse_error(BAD_ARG, parse_errors->line);
		return (false);
	}
	else if (xyz_check(line[CAM_XYZ], parse_errors) == false)
		return (false);
	else if (orientation_check(line[CAM_NO_VEC], parse_errors) == false)
		return (false);
	else if (fov_check(line[CAM_FOV], parse_errors) == false)
		return (false);
	else
		return (true);
}
