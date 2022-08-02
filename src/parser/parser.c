/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42HN.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:27:38 by rsiebert          #+#    #+#             */
/*   Updated: 2022/08/02 16:27:39 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief  prints error message if to few capital letter objects in rt file
 * @param  *parser_utils: parse error bool struct
 * @retval false if no camera and/or no light sources, true otherwise
 */
static bool	min_objects(t_parser_utils *parser_utils)
{
	bool	flag;

	flag = true;
	if (parser_utils->cam == false)
	{
		ft_parse_error(NO_CAM, parser_utils->line);
		flag = false;
	}
	if (parser_utils->dir_light == false && parser_utils->amb_light == false)
	{
		ft_parse_error(NO_LIGHT, parser_utils->line);
		flag = false;
	}
	if (parser_utils->obj == false)
	{
		ft_parse_error(NO_OBJ, parser_utils->line);
		flag = false;
	}
	if (flag == false)
		return (false);
	else
		return (true);
}

/**
 * @brief  check the rt file line by line
 * @param  fd: file descriptor of rt file
 * @retval false if any misconfiguration occurs, true otherwise
 */
static bool	line_check(int fd, t_parser_utils	*parser_utils)
{
	char			*line;

	line = get_next_line(fd);
	if (line == NULL)
		ft_file_error(EMPTY_MAP, fd);
	while (line != NULL)
	{
		parser_utils->line_error = false;
		parser_utils->line++;
		if (line_empty(line) == false)
			line_content_check(line, parser_utils);
		free(line);
		line = get_next_line(fd);
	}
	if (min_objects(parser_utils) == false)
		return (false);
	if (parser_utils->fatal_error == true)
		return (false);
	return (true);
}

/**
 * @brief  checks for any misconfigurations and ensures a secure run of miniRT
 * @param  argc: argument count
 * @param  **argv: argv[1] relative path to rt file
 * @retval false if any misconfiguration occurs, true otherwise
 */
bool	parser(int argc, char **argv)
{
	int				fd;
	t_parser_utils	*parser_utils;

	fd = file_check(argc, argv);
	parser_utils = ft_calloc(1, sizeof(t_parser_utils));
	if (line_check(fd, parser_utils) == true)
	{
		free(parser_utils);
		return (true);
	}
	else
	{
		free(parser_utils);
		return (false);
	}
}
