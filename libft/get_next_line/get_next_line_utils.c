/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <@student.42heilbronn.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:04:50 by tzeck             #+#    #+#             */
/*   Updated: 2022/06/29 15:48:47 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return ((size_t)i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*p;

	if (!dst && !src)
		return (NULL);
	p = dst;
	while (n > 0)
	{
		*((char *)dst) = *((char *)src);
		dst++;
		src++;
		n--;
	}
	return (p);
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc(count * size);
	if (p == NULL)
		return (NULL);
	while (i != count)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*p;

	if (!s1)
		len_s1 = 0;
	else
		len_s1 = ft_strlen(s1);
	len_s2 = n;
	p = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s1, len_s1);
	ft_memcpy(p + len_s1, s2, len_s2);
	if (s1)
		free((void *)s1);
	p[len_s1 + len_s2] = '\0';
	return (p);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*p;
	size_t	i;
	size_t	l;

	l = n + 1;
	i = 0;
	p = malloc(sizeof(char) * l);
	if (p == NULL)
		return (NULL);
	while (i < l - 1)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
