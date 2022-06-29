#include "parser.h"

bool	line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i + 1] != '\0')
	{
		if (line[i] != ' ')
			return (false);
		i++;
	}
	if (line[i] != '\n')
		return (false); 
	return (true);
}

int	ft_count_array(char **xyz_block)
{
	int	i;

	i = 0;
	while (xyz_block[i] != NULL)
		i++;
	return (i);
}

bool	float_check(char *block)
{
	if (ft_isfloat(block) == false)
		return (false);
	return (true);
}