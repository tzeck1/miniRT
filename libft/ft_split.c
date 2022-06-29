/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:24:21 by rsiebert          #+#    #+#             */
/*   Updated: 2022/06/24 19:03:29 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	free_alloc(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	*strings(char const *s, char c, int n)
{
	int		i;
	int		j;
	char	*str;

	i = n;
	while (i >= 0 && s[i] != c)
		i--;
	j = n - i;
	str = (char *)ft_calloc(j + 1, sizeof(char));
	i = n;
	while (i > 0 && s[i - 1] != c)
		i--;
	j = 0;
	while (i <= n)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	res = (char **)ft_calloc(count(s, c) + 1, sizeof(char *));
	if (!s || !res)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			res[j] = strings(s, c, i);
			if (res[j] == NULL)
			{
				free_alloc(res, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}
