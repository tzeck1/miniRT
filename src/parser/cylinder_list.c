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
		if (ft_strncmp(line, CYLINDER_ID, ft_strlen(CYLINDER_ID)) == 0)
			count++;
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)	//Does it work that way? I mean this NULL string is still allocated, I think this should be freed ... I need sleep
		free(line);
	close(fd);
	return (count);
}

static void	fill_me_inside_daddy(char **data, t_cylinder_list *cy_node)
{
	cy_node->identifier = CYLINDER;
	cy_node->center = ft_calloc(1, sizeof(t_vector));	//free
	cy_node->center->x = float_to_fix(ft_atof(data[1]));	//replace with vector_from_str function
	cy_node->center->y = float_to_fix(ft_atof(data[2]));	//replace with vector_from_str function
	cy_node->center->z = float_to_fix(ft_atof(data[3]));	//replace with vector_from_str function
	cy_node->direction = ft_calloc(1, sizeof(t_vector));	//free
	cy_node->direction->x = float_to_fix(ft_atof(data[4]));	//replace with vector_from_str function
	cy_node->direction->y = float_to_fix(ft_atof(data[5]));	//replace with vector_from_str function
	cy_node->direction->z = float_to_fix(ft_atof(data[6]));	//replace with vector_from_str function
	cy_node->radius = ft_atof(data[7]) / 2;
	cy_node->height = ft_atof(data[8]);
	cy_node->rgb = ft_calloc(1, sizeof(t_color));	//free
	cy_node->rgb->red = ft_atoi(data[9]);	//replace with color_from_str function
	cy_node->rgb->green = ft_atoi(data[10]);	//replace with color_from_str function
	cy_node->rgb->blue = ft_atoi(data[11]);	//replace with color_from_str function
}

static t_cylinder_list	*initialize_head(char *line)
{
	t_cylinder_list	*cy_head;
	char			**data;

	data = ft_split(line, ' ');	//free
	cy_head = ft_calloc(1, sizeof(t_cylinder_list));	//free
	fill_me_inside_daddy(data, cy_head);
	cy_head->i = 0;
	cy_head->next = cy_head;
	cy_head->prev = cy_head;
	// FREE 2D ARRAY HERE
	return (cy_head);
}

static int	get_list_index(t_cylinder_list *head)
{
	t_cylinder_list	*current;
	int				i;

	current = head;
	while (current->next->i == 0)
		current = current->next;
	i = current->i + 1;	
	return (i);
}

static void	set_link_pointers(t_cylinder_list *head, t_cylinder_list *node)
{
	t_cylinder_list	*current;

	current = head;
	while (current->next->i == 0)
		current = current->next;
	current->next = node;
	head->prev = node;
	node->next = head;
	node->prev = current;
}

static void	add_node(char *line, t_cylinder_list *cy_head)
{
	t_cylinder_list	*cy_node;
	char			**data;

	data = ft_split(line, ' ');
	cy_node = ft_calloc(1, sizeof(t_cylinder_list));
	fill_me_inside_daddy(data, cy_node);
	cy_node->i = get_list_index(cy_head);
	set_link_pointers(cy_head, cy_node);
	// FREE 2D ARRAY
}

t_cylinder_list	*creat_cylinder_list(char **argv)
{
	t_cylinder_list	*cy_head;
	int				cy_count;
	int				cy_index;
	char			*line;

	cy_count = cylinder_count(argv);
	if (cy_count == 0)
		return (NULL);
	cy_index = 0;
	line = get_obj_line(argv[1], CYLINDER_ID, cy_index);
	cy_head = initialize_head(line);
	while (--cy_count > 0)	//or >= 0?
	{
		cy_index++;
		free(line);
		line = get_obj_line(argv[1], CYLINDER_ID, cy_index);
		add_node(line, cy_head);
	}
	free(line);
	return (cy_head);
}