#include "../../includes/miniRT.h"

static int	sphere_count(char **argv)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strncmp(line, SPHERE_ID, ft_strlen(SPHERE_ID)) == 0)
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static void	fill_me_inside_daddy(char **data, t_sphere_list *sp_node)
{
	sp_node->identifier = SPHERE;
	sp_node->center = vector_from_str(data[1], data[2], data[3]);	//free
	sp_node->radius = float_to_fix(ft_atof(data[4]) / 2);
	sp_node->rgb = color_from_str(data[5], data[6], data[7]);	//free
}

static t_sphere_list	*initialize_head(char *line)
{
	t_sphere_list	*sp_head;
	char			**data;

	data = ft_split(line, ' ');
	sp_head = ft_calloc(1, sizeof(t_sphere_list));	//free
	fill_me_inside_daddy(data, sp_head);
	sp_head->i = 0;
	sp_head->next = sp_head;
	sp_head->prev = sp_head;
	ft_free_split(data);
	return (sp_head);
}

static int	get_list_index(t_sphere_list *head)
{
	t_sphere_list	*current;
	int				i;

	current = head;
	while (current->next->i != 0)
		current = current->next;
	i = current->i + 1;	
	return (i);
}

static void	set_link_pointers(t_sphere_list *head, t_sphere_list *node)
{
	node->prev = head->prev;
	head->prev->next = node;
	node->next = head;
	head->prev = node;
}

static void	add_node(char *line, t_sphere_list *sp_head)
{
	t_sphere_list	*sp_node;
	char			**data;

	data = ft_split(line, ' ');
	sp_node = ft_calloc(1, sizeof(t_sphere_list));
	fill_me_inside_daddy(data, sp_node);
	sp_node->i = get_list_index(sp_head);
	set_link_pointers(sp_head, sp_node);
	ft_free_split(data);
}

t_sphere_list	*creat_sphere_list(char **argv)
{
	t_sphere_list	*sp_head;
	int				sp_count;
	int				sp_index;
	char			*line;

	sp_count = sphere_count(argv);
	if (sp_count == 0)
		return (NULL);
	sp_index = 0;
	line = get_obj_line(argv[1], SPHERE_ID, sp_index);
	sp_head = initialize_head(line);
	while (sp_index < sp_count - 1)
	{
		sp_index++;
		free(line);
		line = get_obj_line(argv[1], SPHERE_ID, sp_index);
		add_node(line, sp_head); //multiple free
	}
	free(line);
	return (sp_head);
}