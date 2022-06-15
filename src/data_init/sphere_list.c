#include "../../includes/miniRT.h"

/**
 * @brief  counts how many sphere objects in rt file
 * @param  **argv:  rt file
 * @retval sphere count
**/
int	sphere_count(char **argv)
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

/**
 * @brief  fills node with rt file data for current sphere line
 * @param  **data: rt file line
 * @param  *sp_node: current node in sphere list
 */
void	sphere_fill(char **data, t_sphere_list *sp_node)
{
	sp_node->identifier = SPHERE;
	sp_node->center = vector_from_str(data[1], data[2], data[3]);
	sp_node->radius = float_to_fix(ft_atof(data[4]) / 2);
	sp_node->rgb = color_from_str(data[5], data[6], data[7]);
}

/**
 * @brief  create list and init head data
 * @param  *line: rt file line
 * @retval head of created list
 */
t_sphere_list	*sphere_initialize_head(char *line)
{
	t_sphere_list	*sp_head;
	char			**data;

	data = ft_split(line, ' ');
	sp_head = ft_calloc(1, sizeof(t_sphere_list));
	sphere_fill(data, sp_head);
	sp_head->i = 0;
	sp_head->next = sp_head;
	sp_head->prev = sp_head;
	ft_free_split(data);
	return (sp_head);
}

/**
 * @brief  adds new node to the end of circular linked list
 * @param  *head: head of list
 * @param  *node: node to add
 */
void	sphere_set_link_pointers(t_sphere_list *head, t_sphere_list *node)
{
	node->prev = head->prev;
	head->prev->next = node;
	node->next = head;
	head->prev = node;
}

/**
 * @brief  creates new node, calls fill and add to list functions
 * @param  *line: rt file line
 * @param  *sp_head: head of sphere list
 */
void	sphere_add_node(char *line, t_sphere_list *sp_head)
{
	t_sphere_list	*sp_node;
	char			**data;

	data = ft_split(line, ' ');
	sp_node = ft_calloc(1, sizeof(t_sphere_list));
	sphere_fill(data, sp_node);
	sp_node->i = sp_head->prev->i + 1;
	sphere_set_link_pointers(sp_head, sp_node);
	ft_free_split(data);
}
