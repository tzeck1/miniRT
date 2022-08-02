/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42HN.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:27:27 by rsiebert          #+#    #+#             */
/*   Updated: 2022/08/02 16:27:28 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief  checks for each identifier the corresponding argument structur
 * @note   sets flag to false if a misconfiguration occurs, parsing continues
 * @param  **line: splited current line into blocks
 * @param  *parser_utils: parse error bool struct
 * @retval false if a misconfiguration in any of the objs occured, true otherwise
 */
static bool	valid_line(char **line, t_parser_utils *parser_utils)
{
	bool	flag;

	flag = true;
	if (ft_strncmp(line[0], "C", 2) == 0)
		flag = check_cam_line(line, parser_utils);
	else if (ft_strncmp(line[0], "A", 2) == 0)
		flag = check_amb_line(line, parser_utils);
	else if (ft_strncmp(line[0], "L", 2) == 0)
		flag = check_dir_line(line, parser_utils);
	else if (ft_strncmp(line[0], "sp", 3) == 0)
		flag = check_sp_line(line, parser_utils);
	else if (ft_strncmp(line[0], "cy", 3) == 0)
		flag = check_cy_line(line, parser_utils);
	else if (ft_strncmp(line[0], "pl", 3) == 0)
		flag = check_pl_line(line, parser_utils);
	if (flag == false)
		return (false);
	else
		return (true);
}

/**
 * @brief  checks for valid object identifiers
 * @param  *id: identifier of current line
 * @param  *parser_utils: parse error bool struct
 * @retval false if no valid object identifier occurs, true otherwise
 */
static bool	check_obj(char *id, t_parser_utils *parser_utils)
{
	if (ft_strncmp(id, "sp", 3) == 0)
		return (true);
	else if (ft_strncmp(id, "cy", 3) == 0)
		return (true);
	else if (ft_strncmp(id, "pl", 3) == 0)
		return (true);
	else if (ft_strncmp(id, "C", 2) != 0
		&& ft_strncmp(id, "A", 2) != 0
		&& ft_strncmp(id, "L", 2) != 0)
	{
		ft_parse_error(WRONG_TYPE, parser_utils->line);
		return (false);
	}
	return (false);
}

/**
 * @brief  checks for valid capital letter identifiers and sets multiples
 * @param  *id: identifier of current line
 * @param  *parser_utils: parse error bool struct
 * @retval false if no valid capital identifier occurs, true otherwise
 */
static bool	check_capital(char *id, t_parser_utils *parser_utils)
{
	if (ft_strncmp(id, "C", 2) == 0 && parser_utils->cam == true)
		ft_parse_error(MULT_CAM, parser_utils->line);
	else if (ft_strncmp(id, "A", 2) == 0 && parser_utils->amb_light == true)
		ft_parse_error(MULT_AMB, parser_utils->line);
	else if (ft_strncmp(id, "L", 2) == 0 && parser_utils->dir_light == true)
		ft_parse_error(MULT_DIR, parser_utils->line);
	else
	{
		if (ft_strncmp(id, "C", 2) == 0)
			parser_utils->cam = true;
		else if (ft_strncmp(id, "A", 2) == 0)
			parser_utils->amb_light = true;
		else if (ft_strncmp(id, "L", 2) == 0)
			parser_utils->dir_light = true;
		else
			return (false);
		return (true);
	}
	return (false);
}

/**
 * @brief  checks for valid identifiers
 * @param  *id: identifier of current line
 * @param  *parser_utils: parse error bool struct
 * @retval false if an invalid identifier occurs, true otherwise
 */
static bool	id_check(char *id, t_parser_utils *parser_utils)
{
	if (check_capital(id, parser_utils) == false)
		if (check_obj(id, parser_utils) == false)
			return (false);
	return (true);
}

/**
 * @brief  checks the line indepth
 * @param  *line: a line from the rt file
 * @param  *parser_utils: parse error bool struct
 * @retval None
 */
void	line_content_check(char *line, t_parser_utils *parser_utils)
{
	char	**split_line;
	int		newline;

	newline = ft_strlen(line) - 1;
	if (line[newline] == '\n')
		line[newline] = '\0';
	split_line = ft_split(line, ' ');
	if (id_check(split_line[0], parser_utils) == false)
	{
		parser_utils->line_error = true;
		parser_utils->fatal_error = true;
		ft_free_split(split_line);
		return ;
	}
	if (valid_line(split_line, parser_utils) == false)
	{
		parser_utils->line_error = true;
		parser_utils->fatal_error = true;
		ft_free_split(split_line);
		return ;
	}
	ft_free_split(split_line);
}
