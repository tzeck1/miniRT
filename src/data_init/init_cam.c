#include "../../includes/miniRT.h"

/**
 * @brief  saves data from rt file in camera struct
 * @param  *line: 'C' line from rt file
 * @param  *cam: camera struct
 * @retval true
 */
static void	save_data(char *line, t_camera *cam)
{
	char	**data;

	replace_commas(line);
	data = ft_split(line, ' ');
	cam->id = CAMERA;
	cam->pos = vec_from_str(data[1], data[2], data[3]);
	cam->dir = vec_from_str(data[4], data[5], data[6]);
	cam->fov = ft_atof(data[7]);
	ft_free_split(data);
}

/**
 * @brief  looks for 'C' line in rt file and if true calls save_data
 * @param  **argv: rt file
 * @retval camera struct or NULL if not in file
 */
t_camera	*get_camera_data(char *rt_file_path)
{
	t_camera	*cam;
	char		*line;
	int			fd;
	int			obj_index;

	cam = ft_calloc(1, sizeof(t_camera));
	fd = open(rt_file_path, O_RDONLY);
	obj_index = 0;
	line = get_obj_line(rt_file_path, CAMERA_ID, obj_index);
	if (line == NULL)
		cam = NULL;
	else
	{
		save_data(line, cam);
		free(line);
	}
	close(fd);
	return (cam);
}
