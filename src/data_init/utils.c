#include "../../includes/miniRT.h"

/**
 * @brief  replaces commas ',' to spaces ' '
 * @note   for split purposes
 * @param  *line: current line from rt file
 * @retval None
 */
void	replace_commas(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			line[i] = ' ';
		i++;
	}
}

/**
 * @brief  get obj line from rt file
 * @param  *rt_file_path: file path for open()
 * @param  *obj_id: object identifier e.G sp
 * @param  obj_index: occourence of line e.G 1(first sp line)
 * @retval obj line or NULL if not in file
 */
char	*get_obj_line(char *rt_file_path, char *obj_id, int obj_index)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(rt_file_path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		if (ft_strncmp(line, obj_id, ft_strlen(obj_id)) == 0)
		{
			if (i == obj_index)
				return (line);
			else
				i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (NULL);
}

/**
 * @brief  creates new color struct from string
 * @retval t_color pointer
 */
t_color	color_from_str(char *red, char *green, char *blue)
{
	t_color	color;

	color.red = ft_atoi(red);
	color.green = ft_atoi(green);
	color.blue = ft_atoi(blue);
	return (color);
}
