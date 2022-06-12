#include "parser.h"

static bool	save_data(char *line, t_camera *cam)
{
	char	**data;

	data = ft_split(line, ' ');
	cam->identifier = CAMERA;
	cam->position = ft_calloc(1, sizeof(t_vector));	//free
	cam->position->x = ft_atof(data[1]);
	cam->position->y = ft_atof(data[2]);
	cam->position->z = ft_atof(data[3]);
	cam->direction = ft_calloc(1, sizeof(t_vector));	//free
	cam->direction->x = ft_atof(data[4]);
	cam->direction->y = ft_atof(data[5]);
	cam->direction->z = ft_atof(data[6]);
	cam->fov = ft_atoi(data[7]);
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
