#include "parser.h"

/**
 * @brief  checks plane line for errors (calls sub functions)
 * @param  **line: plane object line
 * @param  *parser_utils: parser struct
 * @retval bool if aight, false if error in block
 */
bool	check_pl_line(char **line, t_parser_utils *parser_utils)
{
	if (ft_count_array(line) != PL_LINE_SIZE)
	{
		ft_parse_error(BAD_ARG, parser_utils->line);
		return (false);
	}
	else if (xyz_check(line[PL_XYZ], parser_utils) == false)
		return (false);
	else if (orientation_check(line[PL_NO_VEC], parser_utils) == false)
		return (false);
	else if (rgb_check(line[PL_RGB], parser_utils) == false)
		return (false);
	else
	{
		parser_utils->obj = true;
		return (true);
	}
}

/**
 * @brief  checks cylinder line for errors (calls sub functions)
 * @param  **line: cylinder object line
 * @param  *parser_utils: parser struct
 * @retval bool if aight, false if error in block
 */
bool	check_cy_line(char **line, t_parser_utils *parser_utils)
{
	if (ft_count_array(line) != CY_LINE_SIZE)
	{
		ft_parse_error(BAD_ARG, parser_utils->line);
		return (false);
	}
	else if (xyz_check(line[CY_XYZ], parser_utils) == false)
		return (false);
	else if (orientation_check(line[CY_NO_VEC], parser_utils) == false)
		return (false);
	else if (diameter_height_check(line[CY_DIA], parser_utils) == false)
		return (false);
	else if (diameter_height_check(line[CY_HEIGHT], parser_utils) == false)
		return (false);
	else if (rgb_check(line[CY_RGB], parser_utils) == false)
		return (false);
	else
	{
		parser_utils->obj = true;
		return (true);
	}
}

/**
 * @brief  checks sphere line for errors (calls sub functions)
 * @param  **line: sphere object line
 * @param  *parser_utils: parser struct
 * @retval bool if aight, false if error in block
 */
bool	check_sp_line(char **line, t_parser_utils *parser_utils)
{
	if (ft_count_array(line) != SP_LINE_SIZE)
	{
		ft_parse_error(BAD_ARG, parser_utils->line);
		return (false);
	}
	else if (xyz_check(line[SP_XYZ], parser_utils) == false)
		return (false);
	else if (diameter_height_check(line[SP_DIA], parser_utils) == false)
		return (false);
	else if (rgb_check(line[SP_RGB], parser_utils) == false)
		return (false);
	else
	{
		parser_utils->obj = true;
		return (true);
	}
}
