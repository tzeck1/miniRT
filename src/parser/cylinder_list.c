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
	close(fd);
	return (count);
}

static void	fill_me_inside_daddy(char **data, t_cylinder_list *cy_node)
{
	cy_node->identifier = CYLINDER;
	cy_node->center = vector_from_str(data[1], data[2], data[3]);	//free
	cy_node->direction = vector_from_str(data[4], data[5], data[6]);	//free
	cy_node->radius = float_to_fix(ft_atof(data[7]) / 2);
	cy_node->height = float_to_fix(ft_atof(data[8]));
	cy_node->rgb = ft_calloc(1, sizeof(t_color));	//free
	cy_node->rgb = color_from_str(data[9], data[10], data[11]);	//free
}

static t_cylinder_list	*initialize_head(char *line)
{
	t_cylinder_list	*cy_head;
	char			**data;

	data = ft_split(line, ' ');
	cy_head = ft_calloc(1, sizeof(t_cylinder_list));	//free
	fill_me_inside_daddy(data, cy_head);
	cy_head->i = 0;
	cy_head->next = cy_head;
	cy_head->prev = cy_head;
	ft_free_split(data);
	return (cy_head);
}

static int	get_list_index(t_cylinder_list *head)
{
	t_cylinder_list	*current;
	int				i;

	current = head;
	while (current->next->i != 0)
		current = current->next;
	i = current->i + 1;	
	return (i);
}

static void	set_link_pointers(t_cylinder_list *head, t_cylinder_list *node)
{
	node->prev = head->prev;
	head->prev->next = node;
	node->next = head;
	head->prev = node;
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
	ft_free_split(data);
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
	while (cy_index < cy_count - 1)
	{
		cy_index++;
		free(line);
		line = get_obj_line(argv[1], CYLINDER_ID, cy_index);
		add_node(line, cy_head); //multiple free
	}
	free(line);
	return (cy_head);
}