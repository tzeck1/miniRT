/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <@student.42heilbronn.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:00:44 by tzeck             #+#    #+#             */
/*   Updated: 2022/06/11 21:01:24 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static float	get_signifiand(float significand, char *str, int i, int power)
{
	if (str[i] == '.' && str[i])
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			significand += (pow(10, power--) * (str[i] - '0'));
			i++;
		}
	}
	return (significand);
}

float	ft_atof(char *str)
{
	float	exponent;
	float	significand;
	float	sign;
	int		power;
	int		i;

	exponent = 0.0;
	significand = 0.0;
	sign = 1.0;
	power = -1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1.0;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		exponent = exponent * 10 + (str[i] - '0');
		i++;
	}
	significand = get_signifiand(significand, str, i, power);
	return (sign * (exponent + significand));
}
