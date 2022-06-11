/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:24:01 by rsiebert          #+#    #+#             */
/*   Updated: 2021/08/23 19:26:14 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	count(const char *str, int *i, int *neg)
{
	*i = 0;
	*neg = 1;
	while (str[*i] == 32 || (9 <= str[*i] && str[*i] <= 13))
		*i += 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*neg *= -1;
		*i += 1;
	}
	while ('0' <= str[*i] && str[*i] <= '9')
		*i += 1;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	neg;
	int	factor;

	res = 0;
	factor = 1;
	count(str, &i, &neg);
	while (i > 0 && '0' <= str[i - 1] && str[i - 1] <= '9')
	{
		res += (str[i - 1] - '0') * factor;
		factor *= 10;
		i--;
	}
	res *= neg;
	return (res);
}
