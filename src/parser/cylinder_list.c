#include "../../includes/miniRT.h"

/**
 * @brief  counts how many cylinder objects in rt file
 * @param  **argv:  rt file
 * @retval cylinder count
**/
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

/**
 * @brief  fills node with rt file data for current cylinder line
 * @param  **data: rt file line
 * @param  *cy_node: current node in cylinder list
 */
static void	fill_me_inside_daddy(char **data, t_cylinder_list *cy_node)
{
	cy_node->identifier = CYLINDER;
	cy_node->center = vector_from_str(data[1], data[2], data[3]);	//free
	cy_node->direction = vector_from_str(data[4], data[5], data[6]);	//free
	cy_node->radius = float_to_fix(ft_atof(data[7]) / 2);
	cy_node->height = float_to_fix(ft_atof(data[8]));
	cy_node->rgb = color_from_str(data[9], data[10], data[11]);	//free
}

/**
 * @brief  create list and init head data
 * @param  *line: rt file line
 * @retval head of created list
 */
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

/**
 * @brief  adds new node to the end of circular linked list
 * @param  *head: head of list
 * @param  *node: node to add
 */
static void	set_link_pointers(t_cylinder_list *head, t_cylinder_list *node)
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
static void	add_node(char *line, t_cylinder_list *cy_head)
{
	t_cylinder_list	*cy_node;
	char			**data;

	data = ft_split(line, ' ');
	cy_node = ft_calloc(1, sizeof(t_cylinder_list));
	fill_me_inside_daddy(data, cy_node);
	cy_node->i = cy_head->prev->i + 1;
	set_link_pointers(cy_head, cy_node);
	ft_free_split(data);
}

/**
 * @brief  creates list of n cylinder
 * @param  **argv: rt file
 * @retval head of filled cylinder list or NULL if no cylinder objects in rt file
 */
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