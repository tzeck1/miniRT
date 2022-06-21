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

// float	vector_cross(void)
// {
// 	return (0);
// }
