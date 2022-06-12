#include "parser.h"

static bool	get_data(char *line, t_ambient_light *amb_l)
{
	char	**data;

	data = ft_split(line, ' ');	//free
	amb_l->identifier = AMBIENT;
	amb_l->ratio = ft_atof(data[1]);
	amb_l->rgb = ft_calloc(1, sizeof(t_color));	//free
	amb_l->rgb->red = ft_atoi(data[2]);
	amb_l->rgb->green = ft_atoi(data[3]);
	amb_l->rgb->blue = ft_atoi(data[4]);
	// FREE 2D ARRAY FUNC
	return (true);
}

static t_ambient_light	*get_ambient_light_data(char **argv)
{
	t_ambient_light	*amb_l;
	char			*line;
	int				fd;
	
	amb_l = ft_calloc(1, sizeof(t_ambient_light));	//free
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strncmp(line, "A", 1) == 0 && get_data(line, amb_l))	//change A to ambient macro
			break;
		free(line);
		line = get_next_line(fd);
	}
	if (line == NULL)
	{
		free(amb_l);
		amb_l = NULL;
	}
	else
		free(line);
	close(fd);
	return (amb_l);
}

t_objects	*init_objects(char **argv)
{
	t_objects	*objs;

	objs = ft_calloc(1, sizeof(t_objects));	//free
	objs->amb_l = get_ambient_light_data(argv);
	// objs->dir_l = get_direct_light_data(argv);
	// objs->cam = get_camera_data(argv);
	objs->cy_head = creat_cylinder_list(argv);
	// objs->sp_head = creat_sphere_list(argv);
	// objs->pl_head = creat_plane_list(argv);
	return (objs);
}