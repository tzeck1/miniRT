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

/**
 * @brief  vector addition
 * @param  *vec_res: sum of vec_a and vec_b
 */
void	vector_add(t_vector *vec_res, t_vector *vec_a, t_vector *vec_b)
{
	vec_res->x = vec_a->x + vec_b->x;
	vec_res->y = vec_a->y + vec_b->y;
	vec_res->z = vec_a->z + vec_b->z;
}

/**
 * @brief  vector subtraction
 * @param  *vec_res: difference of vec_a and vec_b
 */
void	vector_sub(t_vector *vec_res, t_vector *vec_a, t_vector *vec_b)
{
	vec_res->x = vec_a->x - vec_b->x;
	vec_res->y = vec_a->y - vec_b->y;
	vec_res->z = vec_a->z - vec_b->z;
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
 * @brief  dot product (vector multiplication)
 * @retval product of vec_a and vec_b
 */
int	vector_dot(t_vector *vec_a, t_vector *vec_b)
{
	int	product_x;
	int product_y;
	int product_z;

	product_x = vec_a->x * vec_b->x;
	product_y = vec_a->y * vec_b->y;
	product_z = vec_a->z * vec_b->z;
	return (product_x + product_y + product_z);
}