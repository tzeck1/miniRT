#include "../../includes/miniRT.h"

static bool	save_data(char *line, t_ambient_light *amb_l)
{
	char	**data;

	data = ft_split(line, ' ');
	amb_l->identifier = AMBIENT;
	amb_l->ratio = float_to_fix(ft_atof(data[1]));
	amb_l->rgb = ft_calloc(1, sizeof(t_color));	//free
	amb_l->rgb->red = ft_atoi(data[2]);
	amb_l->rgb->green = ft_atoi(data[3]);
	amb_l->rgb->blue = ft_atoi(data[4]);
	ft_free_split(data);
	return (true);
}

t_ambient_light	*get_ambient_light_data(char **argv)
{
	t_ambient_light	*amb_l;
	char			*line;
	int				fd;
	
	amb_l = ft_calloc(1, sizeof(t_ambient_light));	//free
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, AMB_LIGHT_ID, 1) == 0 && save_data(line, amb_l))
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
