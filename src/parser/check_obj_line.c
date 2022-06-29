#include "parser.h"

/**
 * @brief  checks plane line for errors (calls sub functions)
 * @param  **line: plane object line
 * @param  *parse_errors: parser struct
 * @retval bool if aight, false if error in block
 */
bool	check_pl_line(char **line, t_parse_errors *parse_errors)
{
	if (ft_count_array(line) != PL_LINE_SIZE)
	{
		ft_parse_error(BAD_ARG, parse_errors->line);
		return (false);
	}
	else if (xyz_check(line[PL_XYZ], parse_errors) == false)
		return (false);
	else if (orientation_check(line[PL_NO_VEC], parse_errors) == false)
		return (false);
	else if (rgb_check(line[PL_RGB], parse_errors) == false)
		return (false);
	else
		return (true);
}

/**
 * @brief  checks cylinder line for errors (calls sub functions)
 * @param  **line: cylinder object line
 * @param  *parse_errors: parser struct
 * @retval bool if aight, false if error in block
 */
bool	check_cy_line(char **line, t_parse_errors *parse_errors)
{
	if (ft_count_array(line) != CY_LINE_SIZE)
	{
		ft_parse_error(BAD_ARG, parse_errors->line);
		return (false);
	}
	else if (xyz_check(line[CY_XYZ], parse_errors) == false)
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

/**
 * @brief  checks sphere line for errors (calls sub functions)
 * @param  **line: sphere object line
 * @param  *parse_errors: parser struct
 * @retval bool if aight, false if error in block
 */
bool	check_sp_line(char **line, t_parse_errors *parse_errors)
{
	if (ft_count_array(line) != SP_LINE_SIZE)
	{
		ft_parse_error(BAD_ARG, parse_errors->line);
		return (false);
	}
	else if (xyz_check(line[SP_XYZ], parse_errors) == false)
		return (false);
	else if (diameter_height_check(line[SP_DIA], parse_errors) == false)
		return (false);
	else if (rgb_check(line[SP_RGB], parse_errors) == false)
		return (false);
	else
		return (true);
}
