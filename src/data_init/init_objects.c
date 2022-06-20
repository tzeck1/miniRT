#include "../../includes/miniRT.h"
#include "data_init.h"

/**
 * @brief  creates list of n cylinder
 * @param  **argv: rt file
 * @retval head of filled cylinder list or NULL if no cylinder objects in rt file
 */
static t_cylinder_list	*creat_cylinder_list(char *rt_file_path)
{
	t_cylinder_list	*cy_head;
	int				cy_count;
	int				cy_index;
	char			*line;

	cy_count = cylinder_count(rt_file_path);
	if (cy_count == 0)
		return (NULL);
	cy_index = 0;
	line = get_obj_line(rt_file_path, CYLINDER_ID, cy_index);
	cy_head = cylinder_initialize_head(line);
	while (cy_index < cy_count - 1)
	{
		cy_index++;
		free(line);
		line = get_obj_line(rt_file_path, CYLINDER_ID, cy_index);
		cylinder_add_node(line, cy_head);
	}
	free(line);
	return (cy_head);
}

/**
 * @brief  creates list of n planes
 * @param  **argv: rt file
 * @retval head of filled plane list or NULL if no plane objects in rt file
 */
static t_plane_list	*creat_plane_list(char *rt_file_path)
{
	t_plane_list	*pl_head;
	int				pl_count;
	int				pl_index;
	char			*line;

	pl_count = plane_count(rt_file_path);
	if (pl_count == 0)
		return (NULL);
	pl_index = 0;
	line = get_obj_line(rt_file_path, PLANE_ID, pl_index);
	pl_head = plane_initialize_head(line);
	while (pl_index < pl_count - 1)
	{
		pl_index++;
		free(line);
		line = get_obj_line(rt_file_path, PLANE_ID, pl_index);
		plane_add_node(line, pl_head);
	}
	free(line);
	return (pl_head);
}

/**
 * @brief  creates list of n spheres
 * @param  **argv: rt file
 * @retval head of filled sphere list or NULL if no sphere objects in rt file
 */
static t_sphere_list	*creat_sphere_list(char *rt_file_path)
{
	t_sphere_list	*sp_head;
	int				sp_count;
	int				sp_index;
	char			*line;

	sp_count = sphere_count(rt_file_path);
	if (sp_count == 0)
		return (NULL);
	sp_index = 0;
	line = get_obj_line(rt_file_path, SPHERE_ID, sp_index);
	sp_head = sphere_initialize_head(line);
	while (sp_index < sp_count - 1)
	{
		sp_index++;
		free(line);
		line = get_obj_line(rt_file_path, SPHERE_ID, sp_index);
		sphere_add_node(line, sp_head);
	}
	free(line);
	return (sp_head);
}

/**
 * @brief  init object struct
 * @param  **argv: rt file
 * @retval filled object struct (contains a list of each object type)
 */
t_objects	*init_objects(char *rt_file_path)
{
	t_objects	*objs;

	objs = ft_calloc(1, sizeof(t_objects));
	objs->amb_l = get_ambient_light_data(rt_file_path);
	objs->dir_l = get_direct_light_data(rt_file_path);
	objs->cam = get_camera_data(rt_file_path);
	objs->cy_head = creat_cylinder_list(rt_file_path);
	objs->sp_head = creat_sphere_list(rt_file_path);
	objs->pl_head = creat_plane_list(rt_file_path);
	return (objs);
}
