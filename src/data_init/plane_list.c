/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42HN.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:26:55 by rsiebert          #+#    #+#             */
/*   Updated: 2022/08/02 16:26:56 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

/**
 * @brief  counts how many plane objects in rt file
 * @param  **argv:  rt file
 * @retval plane count
**/
int	pl_counter(char *rt_file_path)
{
	int		count;
	int		fd;
	int		j;
	char	*line;

	count = 0;
	fd = open(rt_file_path, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		j = 0;
		while (line[j] == ' ')
			j++;
		if (ft_strncmp(&line[j], PLANE_ID, ft_strlen(PLANE_ID)) == 0)
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
void	pl_fill(char **data, t_pl_list *pl_node)
{
	pl_node->id = PLANE;
	pl_node->center = vec_from_str(data[1], data[2], data[3]);
	pl_node->dir = vec_from_str(data[4], data[5], data[6]);
	pl_node->rgb = color_from_str(data[7], data[8], data[9]);
}

/**
 * @brief  create list and init head data
 * @param  *line: rt file line
 * @retval head of created list
 */
t_pl_list	*pl_init_head(char *line)
{
	t_pl_list	*pl_head;
	char		**data;

	replace_commas(line);
	data = ft_split(line, ' ');
	pl_head = ft_calloc(1, sizeof(t_pl_list));
	pl_fill(data, pl_head);
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
void	pl_set_link_ptr(t_pl_list *head, t_pl_list *node)
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
void	pl_add_node(char *line, t_pl_list *pl_head)
{
	t_pl_list	*pl_node;
	char		**data;

	replace_commas(line);
	data = ft_split(line, ' ');
	pl_node = ft_calloc(1, sizeof(t_pl_list));
	pl_fill(data, pl_node);
	pl_node->i = pl_head->prev->i + 1;
	pl_set_link_ptr(pl_head, pl_node);
	ft_free_split(data);
}
