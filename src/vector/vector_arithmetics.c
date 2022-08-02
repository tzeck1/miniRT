/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmetics.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42HN.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:29:18 by rsiebert          #+#    #+#             */
/*   Updated: 2022/08/02 16:29:19 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

/**
 * @brief  dot product (vector multiplication)
 * @retval product of vec_a and vec_b
 */
float	vec_dot(t_vec vec_a, t_vec vec_b)
{
	float	product_x;
	float	product_y;
	float	product_z;

	product_x = vec_a.x * vec_b.x;
	product_y = vec_a.y * vec_b.y;
	product_z = vec_a.z * vec_b.z;
	return (product_x + product_y + product_z);
}

/**
 * @brief  computes cross product of two vectors
 * @retval cross product (as a pseudo vector)
 */
t_vec	vec_cross(t_vec vec_a, t_vec vec_b)
{
	t_vec	vec_cross;

	vec_cross.x = vec_a.y * vec_b.z - vec_a.z * vec_b.y;
	vec_cross.y = vec_a.z * vec_b.x - vec_a.x * vec_b.z;
	vec_cross.z = vec_a.x * vec_b.y - vec_a.y * vec_b.x;
	return (vec_cross);
}

/**
 * @brief  adds two vectors and returns the result
 * @retval sum of vec_a and vec_b
 */
t_vec	vec_add(t_vec vec_a, t_vec vec_b)
{
	t_vec	vec_sum;

	vec_sum.x = vec_a.x + vec_b.x;
	vec_sum.y = vec_a.y + vec_b.y;
	vec_sum.z = vec_a.z + vec_b.z;
	return (vec_sum);
}

/**
 * @brief  subtracts two vectors and returns the result
 * @retval differnece of vec_a and vec_b
 */
t_vec	vec_sub(t_vec vec_a, t_vec vec_b)
{
	t_vec	vec_diff;

	vec_diff.x = vec_a.x - vec_b.x;
	vec_diff.y = vec_a.y - vec_b.y;
	vec_diff.z = vec_a.z - vec_b.z;
	return (vec_diff);
}
