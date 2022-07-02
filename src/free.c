#include "../includes/miniRT.h"

/**
 * @brief  frees the plane linked list
 * @param  *head: head of plane linked list
 */
static void	free_pl_list(t_pl_list *head)
{
	t_pl_list	*end_node;

	end_node = head->prev;
	while (head != end_node)
	{
		head = head->next;
		free(head->prev);
		head->prev = NULL;
	}
	free(head);
	head = NULL;
}

/**
 * @brief  frees the sphere linked list
 * @param  *head: head of sphere linked list
 */
static void	free_sp_list(t_sp_list *head)
{
	t_sp_list	*end_node;

	end_node = head->prev;
	while (head != end_node)
	{
		head = head->next;
		free(head->prev);
		head->prev = NULL;
	}
	free(head);
	head = NULL;
}

/**
 * @brief  frees the cylinder linked list
 * @param  *head: head of cylinder linked list
 */
static void	free_cy_list(t_cy_list *head)
{
	t_cy_list	*end_node;

	end_node = head->prev;
	while (head != end_node)
	{
		head = head->next;
		free(head->prev);
		head->prev = NULL;
	}
	free(head);
	head = NULL;
}

/**
 * @brief  free cam, direct and ambient light
 * @param  *cam: camera struct
 * @param  *dir_l: direct light struct
 * @param  *amb_l: ambient light struct
 */
void	free_cam_light(t_camera *cam, t_dir_light *dir_l, t_amb_light *amb_l)
{
	free(cam);
	if (dir_l != NULL)
	{
		free(dir_l);
		dir_l = NULL;
	}
	if (amb_l != NULL)
	{
		free(amb_l);
		amb_l = NULL;
	}
}

/**
 * @brief  checks for allocated memory, frees it and sets it to NULL
 * @param  *objs: objects struct
 */
void	free_objects(t_objects *objs)
{
	free_cam_light(objs->cam, objs->dir_l, objs->amb_l);
	free_cy_list(objs->cy_head);
	free_sp_list(objs->sp_head);
	free_pl_list(objs->pl_head);
	free(objs);
	objs = NULL;
}
