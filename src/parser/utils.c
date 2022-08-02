/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42HN.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:27:43 by rsiebert          #+#    #+#             */
/*   Updated: 2022/08/02 16:27:44 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief  checks if block is divided by exactly two commas
 * @param  *str: block to check [x,y,z] || [r,g,b]
 * @retval false if more than two commas in block
 */
bool	check_comma_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count == 2)
		return (true);
	else
		return (false);
}

/**
 * @brief  checks if the line is empty or not
 * @note   '\n' and ' ' count as empty
 * @param  *line: current line from rt file
 * @retval true if line is empty, false otherwise
 */
bool	line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief  counts the length of a 2d array
 * @param  **array: a 2d array
 * @retval the length of the 2d array
 */
int	ft_count_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

/**
 * @brief  checks for a valid float value
 * @param  *value: a float value from the rt file
 * @retval true if float is valid, false otherwise
 */
bool	float_check(char *value)
{
	if (ft_isfloat(value) == false)
		return (false);
	return (true);
}
