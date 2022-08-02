/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42HN.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:28:36 by rsiebert          #+#    #+#             */
/*   Updated: 2022/08/02 16:28:37 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

/**
 * @brief  gets the normal of an intersection point of a sphere
 * @param  *sp_node: the sphere object to get the normal from
 * @param  tval: struct with information on ray-sphere intersection
 * @param  ray: ray to get intersection point
 * @retval the normal vector of the sphere from intersection point
 */
t_vec	get_sphere_normal(t_sp_list sp_node, t_tval tval, t_ray ray)
{
	t_vec	normal;
	t_vec	hit_point;

	hit_point = vec_add(ray.og, vec_scale(ray.dir, tval.t));
	normal = vec_sub(hit_point, sp_node.center);
	normal = vec_norm(normal);
	return (normal);
}

/**
 * @brief  counts the number of nodes in the sphere linked list
 * @param  *sp_head: head of the circular sphere linked list
 * @retval the count of nodes in the list
 */
static int	count_spheres(t_sp_list *sp_head)
{
	t_sp_list	*tmp;
	int			count;

	if (sp_head->i == sp_head->next->i)
		return (1);
	tmp = sp_head->prev;
	count = 0;
	while (sp_head != tmp)
	{
		sp_head = sp_head->next;
		count++;
	}
	sp_head = sp_head->next;
	return (count + 1);
}

/**
 * @brief  calculates a ray-sphere intersection
 * @param  ray: ray to calculate the intersection with
 * @param  *sphere: the current sphere node to calculate the intersection with
 * @retval the closest intersection distance or infinity if no intersection
 */
static float	ray_sphere(t_ray ray, t_sp_list *sphere)
{
	float	a;
	float	b;
	float	c;
	float	dist;

	a = vec_dot(ray.dir, ray.dir);
	b = 2.0 * vec_dot(ray.dir, vec_sub(ray.og, sphere->center));
	c = powf(vec_len(vec_sub(ray.og, sphere->center)), 2.0);
	c = c - powf(sphere->radius, 2.0);
	dist = b * b - 4.0f * a * c;
	if (dist > 0)
	{
		if ((-b + sqrtf(dist)) / (2 * a) < (-b - sqrtf(dist)) / (2 * a))
			return ((-b + sqrtf(dist)) / (2 * a));
		else
			return ((-b - sqrtf(dist)) / (2 * a));
	}
	else if (dist == 0)
		return ((-b + sqrtf(dist)) / (2 * a));
	else
		return (1.0 / 0.0);
}

/**
 * @brief  iterates through all spheres and calculates for possible intersections
 * @param  ray: ray to calculate the intersections with
 * @param  *objs: object data struct
 * @retval informations on the sphere closest to screen
 */
t_tval	sphere_loop(t_ray ray, t_objects *objs)
{
	t_tval	tval;
	int		sp_last_i;
	int		i;
	float	t;

	i = 0;
	tval.t = 1.0 / 0.0;
	sp_last_i = count_spheres(objs->sp_head);
	while (i != sp_last_i)
	{
		t = ray_sphere(ray, objs->sp_head);
		if (t < tval.t && t > ray.t_min && t < ray.t_max)
		{
			tval.t = t;
			tval.obj_i = objs->sp_head->i;
			tval.obj_type = SPHERE;
			tval.rgb = objs->sp_head->rgb;
		}
		objs->sp_head = objs->sp_head->next;
		i++;
	}
	return (tval);
}
