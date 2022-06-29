#include "parser.h"

/**
 * @brief  checks if the line is empty or not
 * @note   '\n' and ' ' count as empty
 * @param  *line: current line from rt file
 * @retval true if line is empty, false otherwise
 */
bool	line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief  counts the length of a 2d array
 * @param  **array: a 2d array
 * @retval the length of the 2d array
 */
int	ft_count_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

/**
 * @brief  checks for a valid float value
 * @param  *value: a float value from the rt file
 * @retval true if float is valid, false otherwise
 */
bool	float_check(char *value)
{
	if (ft_isfloat(value) == false)
		return (false);
	return (true);
}
