#include "libft.h"
#include <math.h>

/**
 * @brief  gets number after decimal point
 * @retval fraction part of float
 */
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

/**
 * @brief  converts string to float
 * @param  *str: incoming string (should contain only digits and a '.')
 * @retval converted float
 */
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
