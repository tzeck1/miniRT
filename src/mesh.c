#include "../includes/miniRT.h"

static t_sphere	*creat_icosahedron(t_sp_list *sp_head)
{
	return (NULL);
}

t_meshes	*init_meshes(t_objects *objs)
{
	t_meshes	*meshes;

	meshes = ft_calloc(1, sizeof(t_meshes));
	meshes->sphere = creat_icosahedron(objs->sp_head);
	return (meshes);
}