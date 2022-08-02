/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_caps_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42HN.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:27:23 by rsiebert          #+#    #+#             */
/*   Updated: 2022/08/02 16:27:24 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief  checks direct light line for errors (calls sub functions)
 * @param  **line: direct light object line
 * @param  *parser_utils: parser struct
 * @retval bool if aight, false if error in block
 */
bool	check_dir_line(char **line, t_parser_utils *parser_utils)
{
	if (ft_count_array(line) != DIR_LINE_SIZE)
	{
		ft_parse_error(BAD_ARG, parser_utils->line);
		return (false);
	}
	else if (xyz_check(line[DIR_XYZ], parser_utils) == false)
		return (false);
	else if (ratio_check(line[DIR_RATIO], parser_utils) == false)
		return (false);
	else if (rgb_check(line[DIR_RGB], parser_utils) == false)
		return (false);
	else
		return (true);
}

/**
 * @brief  checks ambient light line for errors (calls sub functions)
 * @param  **line: ambient light object line
 * @param  *parser_utils: parser struct
 * @retval bool if aight, false if error in block
 */
bool	check_amb_line(char **line, t_parser_utils *parser_utils)
{
	if (ft_count_array(line) != AMB_LINE_SIZE)
	{
		ft_parse_error(BAD_ARG, parser_utils->line);
		return (false);
	}
	else if (ratio_check(line[AMB_RATIO], parser_utils) == false)
		return (false);
	else if (rgb_check(line[AMB_RGB], parser_utils) == false)
		return (false);
	else
		return (true);
}

/**
 * @brief  checks cam line for errors (calls sub functions)
 * @param  **line: cam object line
 * @param  *parser_utils: parser struct
 * @retval bool if aight, false if error in block
 */
bool	check_cam_line(char **line, t_parser_utils *parser_utils)
{
	if (ft_count_array(line) != CAM_LINE_SIZE)
	{
		ft_parse_error(BAD_ARG, parser_utils->line);
		return (false);
	}
	else if (xyz_check(line[CAM_XYZ], parser_utils) == false)
		return (false);
	else if (orientation_check(line[CAM_NO_VEC], parser_utils) == false)
		return (false);
	else if (fov_check(line[CAM_FOV], parser_utils) == false)
		return (false);
	else
		return (true);
}
