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
 * @brief  calc t if we have a hit point on the cy surface
 * @param  cy: cylinder information for calculations
 * @param  ray: current ray
 * @param  *cylinder: current cylinder
 * @retval hit distance (t)
 */
static float	cy_hit(t_cy cy, t_ray ray, t_cy_list *cylinder)
{
	float	t1;
	float	t2;

	t1 = (-cy.b + sqrtf(cy.dist)) / (2 * cy.a);
	t2 = (-cy.b - sqrtf(cy.dist)) / (2 * cy.a);
	if (mcheck(t1, ray, cylinder, cy.axis) == true
		&& mcheck(t2, ray, cylinder, cy.axis) == true)
	{
		if (t1 <= t2)
			return (t1);
		else
			return (t2);
	}
	if (mcheck(t1, ray, cylinder, cy.axis) == false)
		t1 = caps_check(ray, cylinder);
	if (mcheck(t2, ray, cylinder, cy.axis) == false)
		t2 = caps_check(ray, cylinder);
	if (t1 <= t2)
		return (t1);
	else
		return (t2);
}

/**
 * @brief  set variables for calc hitpoint
 * @param  ray: current ray
 * @param  *cylinder: current cylinder
 * @retval filled cy struct
 */
static t_cy	cy_calc(t_ray ray, t_cy_list *cylinder)
{
	t_cy	cy;

	cy.h = vec_add(cylinder->center, vec_scale(vec_norm(cylinder->dir),
				cylinder->height / 2));
	cy.l = vec_sub(cylinder->center, vec_scale(vec_norm(cylinder->dir),
				cylinder->height / 2));
	cy.axis = vec_norm(vec_sub(cy.h, cy.l));
	cy.w = vec_sub(ray.og, cy.l);
	cy.a = vec_dot(ray.dir, ray.dir);
	cy.a -= powf(vec_dot(ray.dir, cy.axis), 2.0);
	cy.b = vec_dot(ray.dir, cy.w);
	cy.b -= vec_dot(cy.w, cy.axis) * vec_dot(ray.dir, cy.axis);
	cy.b *= 2.0;
	cy.c = vec_dot(cy.w, cy.w) - powf(vec_dot(cy.w, cy.axis), 2.0);
	cy.c -= powf(cylinder->radius, 2.0);
	cy.dist = cy.b * cy.b - 4.0 * cy.a * cy.c;
	return (cy);
}

/**
 * @brief  calls functions to find hitpoint
 * @param  ray: current ray
 * @param  *cylinder: current cylinder
 * @retval returns hit distance (t) or inf if no point was found
 */
static float	ray_cylinder(t_ray ray, t_cy_list *cylinder)
{
	t_cy		cy;

	cy = cy_calc(ray, cylinder);
	cy.dist = cy.b * cy.b - 4.0 * cy.a * cy.c;
	if (cy.dist >= 0)
		return (cy_hit(cy, ray, cylinder));
	else
		return (caps_check(ray, cylinder));
}

/**
 * @brief  iterates through all cy and calculates for possible intersections
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
		if (t < tval.t && t > ray.t_min && t < ray.t_max)
		{
			tval.t = t;
			tval.obj_id = objs->cy_head->i;
			tval.obj_type = CYLINDER;
			tval.rgb = objs->cy_head->rgb;
		}
		objs->cy_head = objs->cy_head->next;
		i++;
	}
	return (tval);
}
