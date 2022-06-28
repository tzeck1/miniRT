#include "libft.h"

bool	ft_isfloat(char *str)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
		return (false);
	i++;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (false);
		if (str[i] == '.')
			dot_count++;
		i++;
	}
	if (str[i - 1] == '.')
		return (false);
	if (dot_count != 0 && dot_count != 1)
		return (false);
	return (true);
}