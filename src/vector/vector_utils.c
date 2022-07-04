#include "../../includes/miniRT.h"

/**
 * @brief  calc vector length
 * @param  vec: vector
 * @retval length of vector
 */
float	vector_length(t_vector vec)
{
	return (sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

/**
 * @brief  scaling vec by n (multiplication)
 * @param  n: scaler
 * @retval product of vec multiplied with n
 */
t_vector	vector_scale(t_vector vec, float n)
{
	t_vector	vec_scaled;

	vec_scaled.x = vec.x * n;
	vec_scaled.y = vec.y * n;
	vec_scaled.z = vec.z * n;
	return (vec);
}

/**
 * @brief  scale points so length becomes one unit long
 * @param  vec: vector
 * @retval normalized vector
 */
t_vector	vector_normalize(t_vector vec)
{
	float	length;
	float	inv_length;

	length = vector_length(vec);
	if (length > 0)
	{
		inv_length = 1 / length;
		vec = vector_scale(vec, inv_length);
	}
	return (vec);
}
