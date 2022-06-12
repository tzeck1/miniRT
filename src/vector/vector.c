#include "vector.h"

t_vector	*vector_new(int x, int y, int z)
{
	t_vector	*vec;

	vec = ft_calloc(1, sizeof(t_vector));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

void	vector_change(t_vector *vec, int x, int y, int z)
{
	if (vec == NULL)
		return ;
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

void	vector_copy(t_vector *vec_src, t_vector *vec_dst)
{
	if (vec_src == NULL || vec_dst == NULL)
		return ;
	vec_dst->x = vec_src->x;
	vec_dst->y = vec_src->y;
	vec_dst->y = vec_src->y;
}