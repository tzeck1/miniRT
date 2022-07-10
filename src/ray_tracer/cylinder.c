#include "ray_tracer.h"

/**
 * @brief  counts the number of nodes in the cylinder linked list
 * @param  *cy_head: head of the circular cylinder linked list
 * @retval the count of nodes in the list
 */
static int	count_cylinder(t_cy_list *cy_head)
{
	t_cy_list	*tmp;
	int			count;

	if (cy_head->i == cy_head->next->i)
		return (1);
	tmp = cy_head->prev;
	count = 0;
	while (cy_head != tmp)
	{
		cy_head = cy_head->next;
		count++;
	}
	cy_head = cy_head->next;
	return (count + 1);
}

/**
 * @brief  calculates a ray-cylinder intersection
 * @param  ray: ray to calculate the ntersection with
 * @param  *cylinder: the current cylinder node to calculate the intersection with
 * @retval the closest intersection distance or infinity if no solution
 */
static float	ray_cylinder(t_ray ray, t_cy_list *cylinder)
{
	float	t;
	float	c;
	float	alpha;
	float	hc;
	float	hi;
	t_vector	C;

	C = vec_new(cylinder->center.x, ray.og.y, cylinder->center.z);
	c = vec_dot(vec_new(ray.og.x, 0, ray.og.z), vec_norm(vec_sub(C, ray.og)));
	alpha = acosf(c) * (180/M_PI);
	hc = sinf(alpha) * vec_len(vec_sub(C, ray.og));
	if (hc > cylinder->radius)
		return (1.0 / 0.0);
	hi = sqrtf(powf(cylinder->radius, 2.0) - powf(hc, 2.0));
	t = (hc / tanf(alpha)) - hi;
	return (t);
}

/**
 * @brief  iterates through all cylinder and calculates for possible intersections
 * @param  ray: ray to calculate the intersections with
 * @param  *objs: object data struct
 * @retval informations on the cylinder closest to screen
 */
t_tval	cylinder_loop(t_ray ray, t_objects *objs)
{
	t_tval	tval;
	int		cy_last_i;
	int		i;
	float	t;

	i = 0;
	tval.t = 1.0 / 0.0;
	cy_last_i = count_cylinder(objs->cy_head);
	while (i != cy_last_i)
	{
		t = ray_cylinder(ray, objs->cy_head);
		if (t < tval.t && t > T_MIN && t < T_MAX)
		{
			tval.t = t;
			tval.rgb = objs->cy_head->rgb;
		}
		objs->cy_head = objs->cy_head->next;
		i++;
	}
	return (tval);
}
