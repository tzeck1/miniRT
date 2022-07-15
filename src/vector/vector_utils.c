#include "../../includes/miniRT.h"

/**
 * @brief  calc vector length
 * @param  vec: vector
 * @retval length of vector
 */
float	vec_len(t_vector vec)
{
	return (sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

/**
 * @brief  scaling vec by n (multiplication)
 * @param  n: scaler
 * @retval product of vec multiplied with n
 */
t_vector	vec_scale(t_vector vec, float n)
{
	t_vector	vec_scaled;

	vec_scaled.x = vec.x * n;
	vec_scaled.y = vec.y * n;
	vec_scaled.z = vec.z * n;
	return (vec_scaled);
}

/**
 * @brief  scale points so length becomes one unit long
 * @param  vec: vector
 * @retval normalized vector
 */
t_vector	vec_norm(t_vector vec)
{
	float	length;
	float	inv_length;

	length = vec_len(vec);
	if (length > 0)
	{
		inv_length = 1 / length;
		vec = vec_scale(vec, inv_length);
	}
	return (vec);
}
