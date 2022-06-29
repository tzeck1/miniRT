#include "../../includes/miniRT.h"

/**
 * @brief  dot product (vector multiplication)
 * @retval product of vec_a and vec_b
 */
float	vector_dot(t_vector *vec_a, t_vector *vec_b)
{
	float	product_x;
	float	product_y;
	float	product_z;

	product_x = vec_a->x * vec_b->x;
	product_y = vec_a->y * vec_b->y;
	product_z = vec_a->z * vec_b->z;
	return (product_x + product_y + product_z);
}

/**
 * @brief  computes cross product of two vectors
 * @retval cross product (as a pseudo vector)
 */
t_vector	*vector_cross(t_vector *vec_a, t_vector *vec_b)
{
	t_vector	*result;

	result = ft_calloc(1, sizeof(t_vector));
	result->x = vec_a->y * vec_b->z - vec_a->z * vec_b->y;
	result->y = vec_a->z * vec_b->x - vec_a->x * vec_b->z;
	result->z = vec_a->x * vec_b->y - vec_a->y * vec_b->x;
	return (result);
}
