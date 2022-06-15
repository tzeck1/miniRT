#include "../../includes/miniRT.h"

/**
 * @brief  saves data from rt file in direct light struct
 * @param  *line: 'L' line from rt file
 * @param  *dir_l: direct light struct
 * @retval true
 */
static bool	save_data(char *line, t_direct_light *dir_l)
{
	char	**data;

	data = ft_split(line, ' ');
	dir_l->identifier = LIGHT;
	dir_l->position = vector_from_str(data[1], data[2], data[3]);
	dir_l->ratio = float_to_fix(ft_atof(data[4]));
	dir_l->rgb = ft_calloc(1, sizeof(t_color));
	dir_l->rgb->red = ft_atoi(data[5]);
	dir_l->rgb->green = ft_atoi(data[6]);
	dir_l->rgb->blue = ft_atoi(data[7]);
	ft_free_split(data);
	return (true);
}

/**
 * @brief  looks for 'L' line in rt file and if true calls save_data
 * @param  **argv: rt file
 * @retval direct light struct or NULL if not in file
 */
t_direct_light	*get_direct_light_data(char **argv)
{
	t_direct_light	*dir_l;
	char			*line;
	int				fd;

	dir_l = ft_calloc(1, sizeof(t_direct_light));
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, LIGHT_ID, 1) == 0 && save_data(line, dir_l))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	if (line == NULL)
	{
		free(dir_l);
		dir_l = NULL;
	}
	else
		free(line);
	close(fd);
	return (dir_l);
}
