#include "../../includes/miniRT.h"

/**
 * @brief  creates new vector
 * @retval new vector
 */
t_vec	vec_new(float x, float y, float z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

/**
 * @brief  creates new vector from string
 * @note   only for input reading
 * @retval new vector
 */
t_vec	vec_from_str(char *x, char *y, char *z)
{
	t_vec	vec;

	vec.x = ft_atof(x);
	vec.y = ft_atof(y);
	vec.z = ft_atof(z);
	return (vec);
}

/**
 * @brief  reassign values of existing vector
 * @param  *vec: existing vector
 * @param  x: new x value
 * @param  y: new y value
 * @param  z: new z value
 * @retval vector with new values
 */
t_vec	vec_change(t_vec vec, float x, float y, float z)
{
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

/**
 * @brief  copy values from source vector to new vector
 * @param  *vec_src: values to be copied
 * @retval new vector with values from vec_src
 */
t_vec	vec_copy(t_vec vec_src)
{
	t_vec	vec;

	vec.x = vec_src.x;
	vec.y = vec_src.y;
	vec.z = vec_src.z;
	return (vec);
}
