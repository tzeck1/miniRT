#include "../../includes/miniRT.h"

static int	cylinder_count(char **argv)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strncmp(line, "cy", 2) == 0)	//change cy to cylinder macro
			count++;
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)	//Does it work that way? I mean this NULL string is still allocated, I think this should be freed ... I need sleep
		free(line);
	close(fd);
	return (count);
}

static t_cylinder_list	*initialize_head(argv)
{
	t_cylinder_list	*cy_head;
	char			**data;

	data = ft_split(argv, ' ');	//free	//FIXME this wont work with argv, the right line is needed
	cy_head = ft_calloc(1, sizeof(t_cylinder_list));	//free
	cy_head->identifier = CYLINDER;
	cy_head->i = 0;
	cy_head->center = ft_calloc(1, sizeof(t_vector));	//free
	cy_head->center->x = float_to_fix(ft_atof(data[1]));	//replace with vector_from_str function
	cy_head->center->y = float_to_fix(ft_atof(data[2]));	//replace with vector_from_str function
	cy_head->center->z = float_to_fix(ft_atof(data[3]));	//replace with vector_from_str function
	cy_head->direction = ft_calloc(1, sizeof(t_vector));	//free
	cy_head->direction->x = float_to_fix(ft_atof(data[4]));	//replace with vector_from_str function
	cy_head->direction->y = float_to_fix(ft_atof(data[5]));	//replace with vector_from_str function
	cy_head->direction->z = float_to_fix(ft_atof(data[6]));	//replace with vector_from_str function
	cy_head->radius = ft_atof(data[7]) / 2;
	cy_head->height = ft_atof(data[8]);
	cy_head->rgb = ft_calloc(1, sizeof(t_color));	//free
	cy_head->rgb->red = ft_atoi(data[9]);	//replace with color_from_str function
	cy_head->rgb->green = ft_atoi(data[10]);	//replace with color_from_str function
	cy_head->rgb->blue = ft_atoi(data[11]);	//replace with color_from_str function
	cy_head->next = cy_head;
	cy_head->prev = cy_head;
	// FREE 2D ARRAY HERE
	return (cy_head);
}

static void	add_node(char **argv, t_cylinder_list *cy_head)
{
}

t_cylinder_list	*creat_cylinder_list(char **argv)
{
	t_cylinder_list	*cy_head;
	int				cy_count;
	int				cy_index;

	cy_count = cylinder_count(argv);
	if (cy_count == 0)
		return (NULL);
	cy_index = 0;
	cy_head = initialize_head(get_obj_line(argv[1], "cy", cy_index));	//FIXE char *line not char **argv	//change cy to cylinder macro
	cy_index++;
	while (--cy_count)
		add_node(get_obj_line(argv[1], "cy", cy_index), cy_head);	//FIXE char *line not char **argv	//change cy to cylinder macro
	return (cy_head);
}