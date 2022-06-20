/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:04:46 by tzeck             #+#    #+#             */
/*   Updated: 2021/09/14 14:02:33 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	if (s == NULL)
		return (-1);
	i = 0;
	ptr = (char *)s;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*trim_tmp(char **tmp, int i)
{
	char	*string;
	size_t	len;

	len = ft_strlen(*tmp) - i;
	string = ft_strndup(&(*tmp)[i], len);
	free_ptr(tmp);
	*tmp = string;
	return (*tmp);
}

char	*return_string(char **tmp, int i, int byte_read)
{
	char	*line;

	if (!*tmp && byte_read <= 0)
		return (NULL);
	line = NULL;
	if (i == -1)
		i = ft_strlen(*tmp);
	else
		i++;
	line = ft_strndup(*tmp, i);
	if (i == (int)ft_strlen(*tmp))
		free_ptr(tmp);
	else
		*tmp = trim_tmp(tmp, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*buf;
	int			i;
	int			byte_read;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 10240)
		return (NULL);
	i = ft_strchr(tmp, '\n');
	buf = NULL;
	while (i == -1)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (buf == NULL)
			return (NULL);
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read <= 0)
			break ;
		tmp = ft_strnjoin(tmp, buf, byte_read);
		i = ft_strchr(tmp, '\n');
		free_ptr(&buf);
	}
	free_ptr(&buf);
	return (return_string(&tmp, i, byte_read));
}
