#include "../includes/miniRT.h"

static void	free_cylinder_list(t_cylinder_list *head)
{
	t_cylinder_list	*current;

	if (head != NULL)
	{
		while (head->i != 0)
			head = head->next;
		current = head->prev;
		while (head != NULL)
		{
			free(current->center);
			free(current->direction);
			free(current->rgb);
			if (current->prev != NULL)
			{
				current = current->prev;
				free(current->next);
			}
			else
			{
				free(current);
				current = NULL;
			}
		}
	}
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
	// objs->sp_head = free_sphere_list(objs->sp_head);
	// objs->sp_head = NULL;
	// objs->pl_head = free_plane_list(objs->pl_head);
	// objs->pl_head = NULL;
	free(objs);
	objs = NULL;
}