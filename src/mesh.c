#include "../includes/miniRT.h"

void	create_triangles(t_sphere *sphere)
{
	sphere->triangles = ft_calloc(20, sizeof(t_triangle));
	sphere->triangles[0] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[0]->v1 = sphere->vertices[2];
	sphere->triangles[0]->v2 = sphere->vertices[1];
	sphere->triangles[0]->v3 = sphere->vertices[0];
	sphere->triangles[1] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[1]->v1 = sphere->vertices[1];
	sphere->triangles[1]->v2 = sphere->vertices[2];
	sphere->triangles[1]->v3 = sphere->vertices[3];
	sphere->triangles[2] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[2]->v1 = sphere->vertices[5];
	sphere->triangles[2]->v2 = sphere->vertices[4];
	sphere->triangles[2]->v3 = sphere->vertices[3];
	sphere->triangles[3] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[3]->v1 = sphere->vertices[4];
	sphere->triangles[3]->v2 = sphere->vertices[8];
	sphere->triangles[3]->v3 = sphere->vertices[3];
	sphere->triangles[4] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[4]->v1 = sphere->vertices[7];
	sphere->triangles[4]->v2 = sphere->vertices[6];
	sphere->triangles[4]->v3 = sphere->vertices[0];
	sphere->triangles[5] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[5]->v1 = sphere->vertices[6];
	sphere->triangles[5]->v2 = sphere->vertices[9];
	sphere->triangles[5]->v3 = sphere->vertices[0];
	sphere->triangles[6] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[6]->v1 = sphere->vertices[11];
	sphere->triangles[6]->v2 = sphere->vertices[10];
	sphere->triangles[6]->v3 = sphere->vertices[4];
	sphere->triangles[7] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[7]->v1 = sphere->vertices[10];
	sphere->triangles[7]->v2 = sphere->vertices[11];
	sphere->triangles[7]->v3 = sphere->vertices[6];
	sphere->triangles[8] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[8]->v1 = sphere->vertices[9];
	sphere->triangles[8]->v2 = sphere->vertices[5];
	sphere->triangles[8]->v3 = sphere->vertices[2];
	sphere->triangles[9] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[9]->v1 = sphere->vertices[5];
	sphere->triangles[9]->v2 = sphere->vertices[9];
	sphere->triangles[9]->v3 = sphere->vertices[11];
	sphere->triangles[10] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[10]->v1 = sphere->vertices[8];
	sphere->triangles[10]->v2 = sphere->vertices[7];
	sphere->triangles[10]->v3 = sphere->vertices[1];
	sphere->triangles[11] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[11]->v1 = sphere->vertices[7];
	sphere->triangles[11]->v2 = sphere->vertices[8];
	sphere->triangles[11]->v3 = sphere->vertices[10];
	sphere->triangles[12] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[12]->v1 = sphere->vertices[2];
	sphere->triangles[12]->v2 = sphere->vertices[5];
	sphere->triangles[12]->v3 = sphere->vertices[3];
	sphere->triangles[13] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[13]->v1 = sphere->vertices[8];
	sphere->triangles[13]->v2 = sphere->vertices[1];
	sphere->triangles[13]->v3 = sphere->vertices[3];
	sphere->triangles[14] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[14]->v1 = sphere->vertices[9];
	sphere->triangles[14]->v2 = sphere->vertices[2];
	sphere->triangles[14]->v3 = sphere->vertices[0];
	sphere->triangles[15] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[15]->v1 = sphere->vertices[1];
	sphere->triangles[15]->v2 = sphere->vertices[7];
	sphere->triangles[15]->v3 = sphere->vertices[0];
	sphere->triangles[16] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[16]->v1 = sphere->vertices[11];
	sphere->triangles[16]->v2 = sphere->vertices[9];
	sphere->triangles[16]->v3 = sphere->vertices[6];
	sphere->triangles[17] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[17]->v1 = sphere->vertices[7];
	sphere->triangles[17]->v2 = sphere->vertices[10];
	sphere->triangles[17]->v3 = sphere->vertices[6];
	sphere->triangles[18] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[18]->v1 = sphere->vertices[5];
	sphere->triangles[18]->v2 = sphere->vertices[11];
	sphere->triangles[18]->v3 = sphere->vertices[4];
	sphere->triangles[19] = ft_calloc(1, sizeof(t_triangle));
	sphere->triangles[19]->v1 = sphere->vertices[10];
	sphere->triangles[19]->v2 = sphere->vertices[8];
	sphere->triangles[19]->v3 = sphere->vertices[4];
}

void	create_vertices(t_sphere *sphere)
{
	sphere->vertices = ft_calloc(12, sizeof(t_vector));
	sphere->vertices[0] = vector_new(sphere->origin->x, sphere->b, -sphere->a);
	sphere->vertices[1] = vector_new(sphere->b, sphere->a, sphere->origin->z);
	sphere->vertices[2] = vector_new(-sphere->b, sphere->a, sphere->origin->z);
	sphere->vertices[3] = vector_new(sphere->origin->x, sphere->b, sphere->a);
	sphere->vertices[4] = vector_new(sphere->origin->x, -sphere->b, sphere->a);
	sphere->vertices[5] = vector_new(-sphere->a, sphere->origin->y, sphere->b);
	sphere->vertices[6] = vector_new(sphere->origin->x, -sphere->b, -sphere->a);
	sphere->vertices[7] = vector_new(sphere->a, sphere->origin->y, -sphere->b);
	sphere->vertices[8] = vector_new(sphere->a, sphere->origin->y, sphere->b);
	sphere->vertices[9] = vector_new(-sphere->a, sphere->origin->y, -sphere->b);
	sphere->vertices[10] = vector_new(sphere->b, -sphere->a, sphere->origin->z);
	sphere->vertices[11] = vector_new(-sphere->b, -sphere->a, sphere->origin->z);
}

static t_sphere	*creat_icosahedron(t_sp_list *sp_head)
{
	t_sphere	*sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	sphere->origin = ft_calloc(1, sizeof(t_vector));
	vector_copy(sp_head->center, sphere->origin);
	sphere->a = sp_head->radius;
	sphere->b = sp_head->radius / ((1.0f + sqrtf(5.0f)) * 0.5f);
	create_vertices(sphere);
	create_triangles(sphere);
	return (sphere);
}

t_meshes	*init_meshes(t_objects *objs)
{
	t_meshes	*meshes;

	meshes = ft_calloc(1, sizeof(t_meshes));
	meshes->sphere = creat_icosahedron(objs->sp_head);
	return (meshes);
}