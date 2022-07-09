#include "../../includes/miniRT.h"

/**
 * @brief  counts how many cylinder objects in rt file
 * @param  **argv:  rt file
 * @retval cylinder count
**/
int	cy_counter(char *rt_file_path)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(rt_file_path, O_RDONLY);
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

/**
 * @brief  fills node with rt file data for current cylinder line
 * @param  **data: rt file line
 * @param  *cy_node: current node in cylinder list
 */
void	cy_fill(char **data, t_cy_list *cy_node)
{
	cy_node->id = CYLINDER;
	cy_node->center = vector_from_str(data[1], data[2], data[3]);
	cy_node->dir = vector_from_str(data[4], data[5], data[6]);
	cy_node->radius = ft_atof(data[7]) / 2;
	cy_node->height = ft_atof(data[8]);
	cy_node->rgb = color_from_str(data[9], data[10], data[11]);
}

/**
 * @brief  create list and init head data
 * @param  *line: rt file line
 * @retval head of created list
 */
t_cy_list	*cy_init_head(char *line)
{
	t_cy_list	*cy_head;
	char		**data;

	replace_commas(line);
	data = ft_split(line, ' ');
	cy_head = ft_calloc(1, sizeof(t_cy_list));
	cy_fill(data, cy_head);
	cy_head->i = 0;
	cy_head->next = cy_head;
	cy_head->prev = cy_head;
	ft_free_split(data);
	return (cy_head);
}

/**
 * @brief  adds new node to the end of circular linked list
 * @param  *head: head of list
 * @param  *node: node to add
 */
void	cy_set_link_ptr(t_cy_list *head, t_cy_list *node)
{
	node->prev = head->prev;
	head->prev->next = node;
	node->next = head;
	head->prev = node;
}

/**
 * @brief  creates new node, calls fill and add to list functions
 * @param  *line: rt file line
 * @param  *cy_head: head of cylinder list
 */
void	cy_add_node(char *line, t_cy_list *cy_head)
{
	t_cy_list	*cy_node;
	char		**data;

	replace_commas(line);
	data = ft_split(line, ' ');
	cy_node = ft_calloc(1, sizeof(t_cy_list));
	cy_fill(data, cy_node);
	cy_node->i = cy_head->prev->i + 1;
	cy_set_link_ptr(cy_head, cy_node);
	ft_free_split(data);
}
