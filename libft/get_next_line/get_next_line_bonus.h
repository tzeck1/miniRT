/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:17:56 by rsiebert          #+#    #+#             */
/*   Updated: 2022/01/03 20:28:03 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	ft_free(char **str);
int		ft_strclen(const char *s, char c, int strlen);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_newline(char **sv, int newline_position);
char	*ft_cutout(char **sv, int newline_position);

#endif
