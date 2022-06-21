#include "../../includes/miniRT.h"

/**
 * @brief  creates new vector
 * @retval t_vector pointer
 */
t_vector	*vector_new(float x, float y, float z)
{
	t_vector	*vec;

	vec = ft_calloc(1, sizeof(t_vector));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

/**
 * @brief  creates new vector from string
 * @note   only for input reading
 * @retval t_vector pointer
 */
t_vector	*vector_from_str(char *x, char *y, char *z)
{
	t_vector	*vec;

	vec = ft_calloc(1, sizeof(t_vector));
	vec->x = ft_atof(x);
	vec->y = ft_atof(y);
	vec->z = ft_atof(z);
	return (vec);
}

/**
 * @brief  reassign values of existing vector
 * @param  *vec: existing vector
 * @param  x: new x value
 * @param  y: new y value
 * @param  z: new z value
 */
void	vector_change(t_vector *vec, float x, float y, float z)
{
	if (vec == NULL)
		return ;
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

/**
 * @brief  copy values from source vector to destination vector
 * @param  *vec_src: values to be copied
 * @param  *vec_dst: values to be overwritten
 */
void	vector_copy(t_vector *vec_src, t_vector *vec_dst)
{
	if (vec_src == NULL || vec_dst == NULL)
		return ;
	vec_dst->x = vec_src->x;
	vec_dst->y = vec_src->y;
	vec_dst->y = vec_src->y;
}
