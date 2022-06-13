#include "../includes/miniRT.h"

/**
 * @brief  frees the plane linked list
 * @param  *head: head of plane linked list
 */
static void	free_plane_list(t_plane_list *head)
{
	t_plane_list	*end_node;
	
	end_node = head->prev;
	while (head != end_node)
	{
		free(head->i_hat);
		free(head->j_hat);
		free(head->rgb);
		head = head->next;
		free(head->prev);
	}
	free(head->i_hat);
	free(head->j_hat);
	free(head->rgb);
	free(head);
}

/**
 * @brief  frees the sphere linked list
 * @param  *head: head of sphere linked list
 */
static void	free_sphere_list(t_sphere_list *head)
{
	t_sphere_list	*end_node;
	
	end_node = head->prev;
	while (head != end_node)
	{
		free(head->center);
		free(head->rgb);
		head = head->next;
		free(head->prev);
	}
	free(head->center);
	free(head->rgb);
	free(head);
}

/**
 * @brief  frees the cylinder linked list
 * @param  *head: head of cylinder linked list
 */
static void	free_cylinder_list(t_cylinder_list *head)
{
	t_cylinder_list	*end_node;
	
	end_node = head->prev;
	while (head != end_node)
	{
		free(head->center);
		free(head->direction);
		free(head->rgb);
		head = head->next;
		free(head->prev);
	}
	free(head->center);
	free(head->direction);
	free(head->rgb);
	free(head);
}

/**
 * @brief  checks for allocated memory, frees it and sets it to NULL
 * @param  *objs: objects struct
 */
void	free_objects(t_objects *objs)
{
	free(objs->cam->position);
	free(objs->cam->direction);
	free(objs->cam);
	if (objs->amb_l != NULL)
	{
		free(objs->amb_l->rgb);
		free(objs->amb_l);
		objs->amb_l = NULL;
	}
	if (objs->dir_l != NULL)
	{
		free(objs->dir_l->position);
		free(objs->dir_l->rgb);
		free(objs->dir_l);
		objs->dir_l = NULL;
	}
	free_cylinder_list(objs->cy_head);
	objs->cy_head = NULL;
	free_sphere_list(objs->sp_head);
	objs->sp_head = NULL;
	free_plane_list(objs->pl_head);
	objs->pl_head = NULL;
	free(objs);
	objs = NULL;
}