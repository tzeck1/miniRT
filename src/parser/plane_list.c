#include "../../includes/miniRT.h"

/**
 * @brief  counts how many plane objects in rt file
 * @param  **argv:  rt file
 * @retval plane count
**/
int	plane_count(char **argv)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strncmp(line, PLANE_ID, ft_strlen(PLANE_ID)) == 0)
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

/**
 * @brief  fills node with rt file data for current plane line
 * @param  **data: rt file line
 * @param  *pl_node: current node in plane list
 */
void	plane_fill(char **data, t_plane_list *pl_node)
{
	pl_node->identifier = PLANE;
	pl_node->i_hat = vector_from_str(data[1], data[2], data[3]); //free
	pl_node->j_hat = vector_from_str(data[4], data[5], data[6]); //free
	pl_node->rgb = color_from_str(data[7], data[8], data[9]); //free
}

/**
 * @brief  create list and init head data
 * @param  *line: rt file line
 * @retval head of created list
 */
t_plane_list	*plane_initialize_head(char *line)
{
	t_plane_list	*pl_head;
	char			**data;

	data = ft_split(line, ' ');
	pl_head = ft_calloc(1, sizeof(t_plane_list)); //free
	plane_fill(data, pl_head);
	pl_head->i = 0;
	pl_head->next = pl_head;
	pl_head->prev = pl_head;
	ft_free_split(data);
	return (pl_head);
}

/**
 * @brief  adds new node to the end of circular linked list
 * @param  *head: head of list
 * @param  *node: node to add
 */
void	plane_set_link_pointers(t_plane_list *head, t_plane_list *node)
{
	node->prev = head->prev;
	head->prev->next = node;
	node->next = head;
	head->prev = node;
}

/**
 * @brief  creates new node, calls fill and add to list functions
 * @param  *line: rt file line
 * @param  *pl_head: head of plane list
 */
void	plane_add_node(char *line, t_plane_list *pl_head)
{
	t_plane_list	*pl_node;
	char			**data;

	data = ft_split(line, ' ');
	pl_node = ft_calloc(1, sizeof(t_plane_list));
	plane_fill(data, pl_node);
	pl_node->i = pl_head->prev->i + 1;
	plane_set_link_pointers(pl_head, pl_node);
	ft_free_split(data);
}
