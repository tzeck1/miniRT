#include "parser.h"

/**
 * @brief  checks if vector is normalized
 * @param  *line: vector array [x, y, z]
 * @param  *parse_errors: parser struct
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
	else
		return (true);
}

/**
 * @brief  checks fov for cam object
 * @param  *line: fov value as string
 * @param  *parse_errors: parser struct
 * @retval true if aight, false if error in block
 */
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

/**
 * @brief  checks oriantation vector for object
 * @param  *line: vector array [x, y, z]
 * @param  *parse_errors: parser struct
 * @retval true if aight, false if error in block
 */
bool	orientation_check(char *line, t_parse_errors *parse_errors)
{
	char	**vec_block;

	vec_block = ft_split(line, ',');
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
	else if (!normalized_check(vec_block[0], vec_block[1], vec_block[2]))
	{
		ft_parse_error(NO_FLOAT, parse_errors->line);
		parse_errors->error = true;
	}
	ft_free_split(vec_block);
	if (parse_errors->error == true)
		return (false);
	else
		return (true);
}

/**
 * @brief  checks coordinate vector for object
 * @param  *line: vector array [x, y, z]
 * @param  *parse_errors: parser struct
 * @retval true if aight, false if error in block
 */
bool	xyz_check(char *line, t_parse_errors *parse_errors)
{
	char	**xyz_block;

	xyz_block = ft_split(line, ',');
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
	ft_free_split(xyz_block);
	if (parse_errors->error == true)
		return (false);
	else
		return (true);
}
