#include "../../includes/miniRT.h"

/**
 * @brief  saves data from rt file in ambient_light struct
 * @param  *line: 'A' line from rt file
 * @param  *amb_l: ambient light struct
 * @retval true
 */
static void	save_data(char *line, t_amb_light *amb_l)
{
	char	**data;

	replace_commas(line);
	data = ft_split(line, ' ');
	amb_l->identifier = AMBIENT;
	amb_l->ratio = ft_atof(data[1]);
	amb_l->rgb.red = ft_atoi(data[2]);
	amb_l->rgb.green = ft_atoi(data[3]);
	amb_l->rgb.blue = ft_atoi(data[4]);
	ft_free_split(data);
}

/**
 * @brief  looks for 'A' line in rt file and if true calls save_data
 * @param  **argv: rt file
 * @retval ambient_light struct or NULL if not in file
 */
t_amb_light	*get_amb_light_data(char *rt_file_path)
{
	t_amb_light	*amb_l;
	char		*line;
	int			fd;
	int			obj_index;

	amb_l = ft_calloc(1, sizeof(t_amb_light));
	fd = open(rt_file_path, O_RDONLY);
	obj_index = 0;
	line = get_obj_line(rt_file_path, AMB_LIGHT_ID, obj_index);
	if (line == NULL)
		amb_l = NULL;
	else
	{
		save_data(line, amb_l);
		free(line);
	}
	close(fd);
	return (amb_l);
}
