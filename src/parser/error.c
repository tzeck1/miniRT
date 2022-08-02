/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42HN.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:27:36 by rsiebert          #+#    #+#             */
/*   Updated: 2022/08/02 16:27:37 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief  prints error messages but without calling ft_exit()
 * @param  error: error code
 * @param  line: line number of an error in the rt file
 * @retval None
 */
void	ft_parse_error(int error, int line)
{
	if (error == WRONG_TYPE)
		fprintf(stderr, YELLOW "Error[line %d]: " WRONG_TYPE_MSG RESET, line);
	else if (error == MULT_CAM)
		fprintf(stderr, YELLOW "Error[line %d]: " MULT_CAM_MSG RESET, line);
	else if (error == MULT_AMB)
		fprintf(stderr, YELLOW "Error[line %d]: " MULT_AMB_MSG RESET, line);
	else if (error == MULT_DIR)
		fprintf(stderr, YELLOW "Error[line %d]: " MULT_DIR_MSG RESET, line);
	else if (error == BAD_ARG)
		fprintf(stderr, YELLOW "Error[line %d]: " BAD_ARG_MSG RESET, line);
	else if (error == NO_FLOAT)
		fprintf(stderr, YELLOW "Error[line %d]: " NO_FLOAT_MSG RESET, line);
	else if (error == NO_CAM)
		fprintf(stderr, YELLOW "Error[file]: " NO_CAM_MSG RESET);
	else if (error == NO_LIGHT)
		fprintf(stderr, YELLOW "Error[file]: " NO_LIGHT_MSG RESET);
	else if (error == NO_OBJ)
		fprintf(stderr, YELLOW "Error[file]: " NO_OBJ_MSG RESET);
}

/**
 * @brief  prints error message and calls ft_exit()
 * @param  error: error code 
 * @param  fd: close file when an error happens
 */
void	ft_file_error(int error, int fd)
{
	close(fd);
	if (error == ARG_COUNT)
		fprintf(stderr, YELLOW "Error[file]: " ARG_COUNT_MSG RESET);
	else if (error == NO_RT)
		fprintf(stderr, YELLOW "Error[file]: " NO_RT_MSG RESET);
	else if (error == OPEN_ERR)
		fprintf(stderr, YELLOW "Error[file]: " OPEN_ERR_MSG RESET);
	else if (error == EMPTY_MAP)
		fprintf(stderr, YELLOW "Error[file]: " EMPTY_MAP_MSG RESET);
	ft_exit(EXIT_FAILURE);
}
