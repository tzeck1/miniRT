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
	float	t1;
	float	t2;
	float	t;
	float	a;
	float	b;
	float	c;
	float	dist;
	float	m1;
	float	m2;
	t_vector	x;
	t_vector	H;
	t_vector	new_dir;

	new_dir = vec_new(cylinder->dir.y, cylinder->dir.x, cylinder->dir.z);

	// H = cy.og - cy.dir * h/2
	H = vec_sub(cylinder->center, vec_scale(new_dir, (cylinder->height / 2)));
	x = vec_sub(ray.og, H);

	a = vec_dot(ray.dir, ray.dir) - powf(vec_dot(ray.dir, new_dir), 2.0);
	b = 2.0 * (vec_dot(ray.dir, x) - vec_dot(ray.dir, new_dir) * vec_dot(x, new_dir));
	c = vec_dot(x, x) - powf(vec_dot(x, new_dir), 2.0) - powf(cylinder->radius, 2.0);
	// printf("a -> [%f]\nb -> [%f]\nc -> [%f]\n\n", a, b, c);

	dist = b * b - 4.0f * a * c;
	if (dist >= 0)
	{
		t1 = (-b + sqrtf(dist)) / (2 * a);
		t2 = (-b - sqrtf(dist)) / (2 * a);
	}
	else if (dist < 0)
	{
		t1 = 1.0 / 0.0;
		t2 = 1.0 / 0.0;
	}
	m1 = vec_dot(ray.dir, new_dir) * t1 + vec_dot(x, new_dir);
	m2 = vec_dot(ray.dir, new_dir) * t2 + vec_dot(x, new_dir);

	if (m1 >= 0 && m1 <= cylinder->height)
		return (t1);
	else if (m2 >= 0 && m2 <= cylinder->height)
		return (t2);
	else
		return (1.0 / 0.0);
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
