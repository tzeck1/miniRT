#include "parser.h"

/**
 * @brief  checks if vector is normalized
 * @param  *line: vector array [x, y, z]
 * @param  *parser_utilss: parser struct
 * @retval true if aight, false if error in block
 */
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
		return (false);
	if (x == 0 && y == 0 && z == 0)
		return (false);
	else
		return (true);
}

/**
 * @brief  checks fov for cam object
 * @param  *line: fov value as string
 * @param  *parser_utils: parser struct
 * @retval true if aight, false if error in block
 */
bool	fov_check(char *line, t_parser_utils *parser_utils)
{
	float	fov;

	fov = ft_atof(line);
	if (fov < FOV_MIN || fov > FOV_MAX)
	{
		ft_parse_error(BAD_ARG, parser_utils->line);
		parser_utils->line_error = true;
	}
	if (parser_utils->line_error == true)
		return (false);
	else
		return (true);
}

/**
 * @brief  checks oriantation vector for object
 * @param  *line: vector array [x, y, z]
 * @param  *parser_utilss: parser struct
 * @retval true if aight, false if error in block
 */
bool	orientation_check(char *line, t_parser_utils *parser_utilss)
{
	char	**vec_block;

	vec_block = ft_split(line, ',');
	if (check_comma_count(line) == false || ft_count_array(vec_block) != 3)
	{
		ft_parse_error(BAD_ARG, parser_utilss->line);
		parser_utilss->line_error = true;
	}
	else if (float_check(vec_block[0]) == false
		|| float_check(vec_block[1]) == false
		|| float_check(vec_block[2]) == false)
	{
		ft_parse_error(NO_FLOAT, parser_utilss->line);
		parser_utilss->line_error = true;
	}
	else if (!normalized_check(vec_block[0], vec_block[1], vec_block[2]))
	{
		ft_parse_error(NO_FLOAT, parser_utilss->line);
		parser_utilss->line_error = true;
	}
	ft_free_split(vec_block);
	if (parser_utilss->line_error == true)
		return (false);
	else
		return (true);
}

/**
 * @brief  checks coordinate vector for object
 * @param  *line: vector array [x, y, z]
 * @param  *parser_utilss: parser struct
 * @retval true if aight, false if error in block
 */
bool	xyz_check(char *line, t_parser_utils *parser_utils)
{
	char	**xyz_block;

	xyz_block = ft_split(line, ',');
	if (check_comma_count(line) == false || ft_count_array(xyz_block) != 3)
	{
		ft_parse_error(BAD_ARG, parser_utils->line);
		parser_utils->line_error = true;
	}
	else if (float_check(xyz_block[0]) == false
		|| float_check(xyz_block[1]) == false
		|| float_check(xyz_block[2]) == false)
	{
		ft_parse_error(NO_FLOAT, parser_utils->line);
		parser_utils->line_error = true;
	}
	ft_free_split(xyz_block);
	if (parser_utils->line_error == true)
		return (false);
	else
		return (true);
}
