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

static float	caps_check(t_ray ray, t_cy_list *cylinder)
{
	float	t1;
	float	t2;
	t_vector	p1;
	t_vector	p2;
	t_pl_list	*top_cap;
	t_pl_list	*low_cap;

	top_cap = ft_calloc(1, sizeof(t_pl_list));
	low_cap = ft_calloc(1, sizeof(t_pl_list));
	top_cap->center = vec_sub(cylinder->center, vec_scale(cylinder->dir, (cylinder->height / 2)));
	top_cap->center = cylinder->dir;
	low_cap->center = vec_add(cylinder->center, vec_scale(cylinder->dir, (cylinder->height / 2)));
	low_cap->center = cylinder->dir;
	t1 = ray_plane(ray, top_cap);
	p1 = vec_add(ray.og, vec_scale(ray.dir, t1));
	t2 = ray_plane(ray, low_cap);
	p2 = vec_add(ray.og, vec_scale(ray.dir, t2));
	if (vec_len(vec_sub(top_cap->center, p1)) > cylinder->radius)
		t1 = 1.0 / 0.0;
	if (vec_len(vec_sub(top_cap->center, p2)) > cylinder->radius)
		t2 = 1.0 / 0.0;
	if (t1 < t2)
		return (t1);
	else if (t2 < t1)
		return (t2);
	else
		return (1.0 / 0.0);
}

static bool	mcheck(float t, t_ray ray, t_cy_list *cylinder, t_vector x)
{
	float	m;

	m = vec_dot(ray.dir, cylinder->dir) * t + vec_dot(x, cylinder->dir);
	if (m >= 0 && m <= cylinder->height)
		return (true);
	else
		return (false);
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

	// H = cy.og - cy.dir * h/2
	H = vec_sub(cylinder->center, vec_scale(cylinder->dir, (cylinder->height / 2)));
	x = vec_sub(ray.og, H);

	a = vec_dot(ray.dir, ray.dir) - powf(vec_dot(ray.dir, cylinder->dir), 2.0);
	b = 2.0 * (vec_dot(ray.dir, x) - vec_dot(ray.dir, cylinder->dir) * vec_dot(x, cylinder->dir));
	c = vec_dot(x, x) - powf(vec_dot(x, cylinder->dir), 2.0) - powf(cylinder->radius, 2.0);
	// printf("a -> [%f]\nb -> [%f]\nc -> [%f]\n\n", a, b, c);

	dist = b * b - 4.0f * a * c;
	if (dist >= 0)
	{
		t1 = (-b + sqrtf(dist)) / (2 * a);
		t2 = (-b - sqrtf(dist)) / (2 * a);
		if (mcheck(t1, ray, cylinder, x) == true && mcheck(t2, ray, cylinder, x))
		{
			if (t1 < t2)
				return (t1);
			else
				return (t2);
		}
		else if (mcheck(t1, ray, cylinder, x) == false || mcheck(t2, ray, cylinder, x) == false)
		{
			if (mcheck(t1, ray, cylinder, x) == false)
				t1 = caps_check(ray, cylinder);
			if (mcheck(t2, ray, cylinder, x) == false)
				t2 = caps_check(ray, cylinder);
			if (t1 == 1.0 / 0.0 && t2 == 1.0 / 0.0)
				return (1.0 / 0.0);
			else if (t1 < t2)
				return (t1);
			else
				return (t2);
		}
	}
	else if (dist < 0)
	{
		t1 = caps_check(ray, cylinder);
		if (t1 != 1.0 / 0.0)
			return (t1);
		else
			return (1.0 / 0.0);
	}
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
