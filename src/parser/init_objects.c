#include "../../includes/miniRT.h"

t_objects	*init_objects(char **argv)
{
	t_objects	*objs;

	objs = ft_calloc(1, sizeof(t_objects));	//free
	objs->amb_l = get_ambient_light_data(argv);
	objs->dir_l = get_direct_light_data(argv);
	objs->cam = get_camera_data(argv);
	// objs->cy_head = creat_cylinder_list(argv);
	// objs->sp_head = creat_sphere_list(argv);
	// objs->pl_head = creat_plane_list(argv);
	return (objs);
}