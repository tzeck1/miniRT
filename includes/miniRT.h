/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <@student.42heilbronn.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:07:12 by tzeck             #+#    #+#             */
/*   Updated: 2022/06/02 14:42:22 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*	INCLUDES	*/
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*	COLORS	*/
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define BLUE	"\033[34m"
# define YELLOW	"\033[33m"
# define RESET	"\033[0m"

/*	DEBUG	*/
# define PRINT_HERE(){printf(YELLOW"In File: %s\nIn Line: %d\n"RESET, __FILE__, __LINE__);}

#endif
