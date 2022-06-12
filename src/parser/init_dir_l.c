#include "../../includes/miniRT.h"

static bool	save_data(char *line, t_direct_light *dir_l)
{
	char	**data;

	data = ft_split(line, ' '); //free
	dir_l->identifier = LIGHT;
	dir_l->position = vector_from_str(data[1], data[2], data[3]);
	dir_l->ratio = ft_atof(data[4]);
	dir_l->rgb = ft_calloc(1, sizeof(t_color)); //free
	dir_l->rgb->red = ft_atoi(data[5]);
	dir_l->rgb->green = ft_atoi(data[6]);
	dir_l->rgb->blue = ft_atoi(data[7]);
	ft_free_split(data);
	return (true);
}

t_direct_light	*get_direct_light_data(char **argv)
{
	t_direct_light	*dir_l;
	char			*line;
	int				fd;
	
	dir_l = ft_calloc(1, sizeof(t_direct_light));	//free
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, LIGHT_ID, 1) == 0 && save_data(line, dir_l))
			break;
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