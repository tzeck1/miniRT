/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <@student.42heilbronn.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:04:56 by tzeck             #+#    #+#             */
/*   Updated: 2022/06/29 15:49:15 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc_gnl(size_t count, size_t size);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
char	*ft_strndup(const char *s1, size_t n);
void	free_ptr(char **ptr);

#endif