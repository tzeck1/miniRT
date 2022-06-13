#include "../../includes/miniRT.h"

/**
 * @brief  counts how many plane objects in rt file
 * @param  **argv:  rt file
 * @retval plane count
**/
static int	plane_count(char **argv)
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
static void	fill_me_inside_daddy(char **data, t_plane_list *pl_node)
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
static t_plane_list	*initialize_head(char *line)
{
	t_plane_list	*pl_head;
	char			**data;

	data = ft_split(line, ' ');
	pl_head = ft_calloc(1, sizeof(t_plane_list)); //free
	fill_me_inside_daddy(data, pl_head);
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
static void	set_link_pointers(t_plane_list *head, t_plane_list *node)
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
static void	add_node(char *line, t_plane_list *pl_head)
{
	t_plane_list	*pl_node;
	char			**data;

	data = ft_split(line, ' ');
	pl_node = ft_calloc(1, sizeof(t_plane_list));
	fill_me_inside_daddy(data, pl_node);
	pl_node->i = pl_head->prev->i + 1;
	set_link_pointers(pl_head, pl_node);
	ft_free_split(data);
}

/**
 * @brief  creates list of n planes
 * @param  **argv: rt file
 * @retval head of filled plane list or NULL if no plane objects in rt file
 */
t_plane_list	*creat_plane_list(char **argv)
{
	t_plane_list	*pl_head;
	int				pl_count;
	int				pl_index;
	char			*line;

	pl_count = plane_count(argv);
	if (pl_count == 0)
		return (NULL);
	pl_index = 0;
	line = get_obj_line(argv[1], PLANE_ID, pl_index);
	pl_head = initialize_head(line);
	while (pl_index < pl_count - 1)
	{
		pl_index++;
		free(line);
		line = get_obj_line(argv[1], PLANE_ID, pl_index);
		add_node(line, pl_head); //multiple free
	}
	free(line);
	return (pl_head);
}
