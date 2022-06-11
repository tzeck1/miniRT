/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:42:43 by rsiebert          #+#    #+#             */
/*   Updated: 2022/01/20 21:34:51 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_endcond(int buf_val, char **sv, int *char_pos, int endc)
{
	if (buf_val <= 0 && endc == 1)
	{
		if (buf_val == -1)
			return (0);
		if (!(*sv) || **sv == '\0')
		{
			if (sv)
				ft_free(sv);
			return (0);
		}
	}
	if (endc == 0)
	{
		*char_pos = ft_strclen(*sv, '\n', 1);
		return (*char_pos);
	}
	return (1);
}

static char	*ft_no_newline(char **sv)
{
	char	*out;
	int		i;

	out = ft_calloc(ft_strclen(*sv, '\0', 1) + 1, sizeof(char));
	if (out == NULL)
		return (NULL);
	i = 0;
	while (sv[0][i])
	{
		out[i] = sv[0][i];
		i++;
	}
	out[i] = '\0';
	sv[0][0] = '\0';
	return (out);
}

static char	*ft_append(char *sv, char *buf, int buf_val)
{
	char	*out;
	int		i;
	int		j;

	i = ft_strclen(sv, '\0', 1);
	out = ft_calloc(i + buf_val + 1, sizeof(char));
	if (out == NULL)
		return (NULL);
	j = 0;
	while (sv[j])
	{
		out[j] = sv[j];
		j++;
	}
	i = 0;
	while (buf_val-- > 0)
	{
		out[j] = buf[i];
		i++;
		j++;
	}
	out[j] = '\0';
	if (sv)
		free(sv);
	return (out);
}

static int	ft_alloc(char **sv, char **buf, int *buf_val, int fd)
{
	*buf = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (*buf == NULL)
		return (1);
	*buf_val = read(fd, *buf, BUFFER_SIZE);
	if (*buf_val == -1)
	{
		if (*sv != NULL)
			free(*sv);
		free(*buf);
		return (1);
	}
	if (*sv == NULL)
		*sv = ft_calloc(BUFFER_SIZE, sizeof(char));
	*sv = ft_append(*sv, *buf, *buf_val);
	ft_free(buf);
	if (*sv == NULL)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*sv[12288];
	char		*buf;
	char		*out;
	int			buf_val;
	int			char_pos;

	if ((0 > fd && fd < 12288) || BUFFER_SIZE < 0)
		return (NULL);
	buf_val = 1;
	while (ft_endcond(buf_val, &sv[fd], &char_pos, 1))
	{
		if (ft_alloc(&sv[fd], &buf, &buf_val, fd))
			return (NULL);
		if (ft_endcond(buf_val, &sv[fd], &char_pos, 0))
		{
			out = ft_newline(&sv[fd], char_pos);
			return (out);
		}
		else if (buf_val == 0 && sv[fd][0] != '\0')
		{
			out = ft_no_newline(&sv[fd]);
			return (out);
		}
	}
	return (NULL);
}
