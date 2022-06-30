#include "../../includes/miniRT.h"

/**
 * @brief  saves data from rt file in direct light struct
 * @param  *line: 'L' line from rt file
 * @param  *dir_l: direct light struct
 * @retval true
 */
static void	save_data(char *line, t_dir_light *dir_l)
{
	char	**data;

	replace_commas(line);
	data = ft_split(line, ' ');
	dir_l->identifier = LIGHT;
	dir_l->position = vector_from_str(data[1], data[2], data[3]);
	dir_l->ratio = ft_atof(data[4]);
	dir_l->rgb = ft_calloc(1, sizeof(t_color));
	dir_l->rgb->red = ft_atoi(data[5]);
	dir_l->rgb->green = ft_atoi(data[6]);
	dir_l->rgb->blue = ft_atoi(data[7]);
	ft_free_split(data);
}

/**
 * @brief  looks for 'L' line in rt file and if true calls save_data
 * @param  **argv: rt file
 * @retval direct light struct or NULL if not in file
 */
t_dir_light	*get_dir_light_data(char *rt_file_path)
{
	t_dir_light	*dir_l;
	char		*line;
	int			fd;
	int			obj_index;

	dir_l = ft_calloc(1, sizeof(t_dir_light));
	fd = open(rt_file_path, O_RDONLY);
	obj_index = 0;
	line = get_obj_line(rt_file_path, LIGHT_ID, obj_index);
	if (line == NULL)
		dir_l = NULL;
	else
	{
		save_data(line, dir_l);
		free(line);
	}
	close(fd);
	return (dir_l);
}
