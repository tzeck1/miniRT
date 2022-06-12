#include "../../includes/miniRT.h"

static bool	save_data(char *line, t_camera *cam)
{
	char	**data;

	data = ft_split(line, ' ');
	cam->identifier = CAMERA;
	cam->position = vector_from_str(data[1], data[2], data[3]);	//free
	cam->direction = vector_from_str(data[4], data[5], data[6]);	//free
	cam->fov = float_to_fix(ft_atoi(data[7]));
	ft_free_split(data);
	return (true);
}

t_camera	*get_camera_data(char **argv)
{
	t_camera		*cam;
	char			*line;
	int				fd;
	
	cam = ft_calloc(1, sizeof(t_camera));	//free
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, CAMERA_ID, 1) == 0 && save_data(line, cam))
			break;
		free(line);
		line = get_next_line(fd);
	}
	if (line == NULL)
	{
		free(cam);
		cam = NULL;
	}
	else
		free(line);
	close(fd);
	return (cam);
}
