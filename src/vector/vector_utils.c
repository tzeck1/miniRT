#include "../../includes/miniRT.h"

/**
 * @brief  calc vector length
 * @param  *vec: vector
 * @retval length of vector
 */
float	vector_length(t_vector *vec)
{
	return (sqrtf(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
}

/**
 * @brief  scaling vec_a by n (multiplication)
 * @param  *vec_res: product of vec_a multiplied with n
 * @param  n: scaler
 */
void	vector_scale(t_vector *vec_res, t_vector *vec_a, float n)
{
	vec_res->x = vec_a->x * n;
	vec_res->y = vec_a->y * n;
	vec_res->z = vec_a->z * n;
}

/**
 * @brief  scale points so length becomes one unit long
 * @param  *vec: vector
 */
void	vector_normalize(t_vector *vec)
{
	float	length;
	float	inv_length;

	length = vector_length(vec);
	if (length > 0)
	{
		inv_length = 1 / length;
		vector_scale(vec, vec, inv_length);
	}
}
