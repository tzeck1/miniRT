/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:16:13 by rsiebert          #+#    #+#             */
/*   Updated: 2022/01/20 21:43:01 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strclen(const char *s, char c, int strlen)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0' && strlen == 0)
	{
		while (i < ft_strclen(s, '\0', 1) && s[i] != c)
			i++;
		if (s[i - 1] != c)
			return (0);
	}
	else
	{
		while (s[i] != c && s[i])
			i++;
		if (s[i] != c)
			return (0);
	}
	if (s[i] == c && i == 0)
		return (-1);
	return (i);
}

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}
/*
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	i;
	char	*str;

	p = (void *)malloc(nmemb * size + 1);
	if (p == NULL)
		return (NULL);
	str = (char *)p;
	i = 0;
	while (i < (nmemb * size))
	{
		str[i] = '\0';
		i++;
	}
	return (p);
}
*/
char	*ft_cutout(char **sv, int newline_position)
{
	char	*tmp;
	int		i;

	i = ft_strclen(*sv, '\0', 1) - newline_position;
	tmp = ft_calloc(i, sizeof(char));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (sv[0][newline_position])
	{
		tmp[i] = sv[0][newline_position];
		newline_position++;
		i++;
	}
	tmp[i] = '\0';
	free(*sv);
	return (tmp);
}

char	*ft_newline(char **sv, int newline_position)
{
	char	*out;
	int		i;

	if (newline_position == -1)
		newline_position = 0;
	out = ft_calloc(newline_position + 1, sizeof(char));
	if (out == NULL)
		return (NULL);
	i = 0;
	while (newline_position >= 0)
	{
		out[i] = sv[0][i];
		i++;
		newline_position--;
	}
	out[i] = '\0';
	*sv = ft_cutout(sv, i);
	return (out);
}
