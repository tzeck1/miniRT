#include "ray_tracer.h"

/**
 * @brief  lowkey shading effect from obj center
 * @note   just for testing shapes, delete when implementing real light
 */
static unsigned int temp_shading(t_tval tval, t_ray ray, t_objects *objs)
{
	float	t = tval.t;
	tval.hit_point = vec_add(ray.og, vec_scale(ray.dir, t));
	t_vector H = vec_sub(objs->cy_head->center, vec_scale(objs->cy_head->dir, (objs->cy_head->height / 2)));
	t_vector x = vec_sub(ray.og, H);
	float m = vec_dot(ray.dir, objs->cy_head->dir) * t + vec_dot(x, objs->cy_head->dir);
	t_vector ax_point = vec_add(H, vec_scale(objs->cy_head->dir, m));
	tval.normal = vec_norm(vec_sub(tval.hit_point, ax_point));
	tval.rgb = objs->cy_head->rgb;
	if (0.0 > vec_dot(tval.normal, vec_scale(ray.dir, -1)))
		tval.rgb.a = 0;
	else
	{
		float f = vec_dot(tval.normal, vec_scale(ray.dir, -1));
		tval.rgb.a = f * 255.999;//(f >= 1.0 ? 255 : (f <= 0.0 ? 0 : (int)floor(f * 256.0)));
	}
	return (tval.rgb.a);
}

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
 * @brief  checks if ray hits top or low cap of the cylinder
 * @param  ray: current ray
 * @param  *cylinder: current cylinder
 * @retval t for cap_hit, or inf in no hit
 */
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
	top_cap->dir = cylinder->dir;
	low_cap->center = vec_add(cylinder->center, vec_scale(cylinder->dir, (cylinder->height / 2)));
	low_cap->dir = cylinder->dir;
	t1 = ray_plane(ray, top_cap);
	p1 = vec_add(ray.og, vec_scale(ray.dir, t1));
	t2 = ray_plane(ray, low_cap);
	p2 = vec_add(ray.og, vec_scale(ray.dir, t2));
	if (vec_len(vec_sub(top_cap->center, p1)) > cylinder->radius)
		t1 = 1.0 / 0.0;
	if (vec_len(vec_sub(top_cap->center, p2)) > cylinder->radius)
		t2 = 1.0 / 0.0;
	if (t1 <= t2)
		return (t1);
	else
		return (t2);
}

/**
 * @brief  cuts of inf cylinder at cy.height
 * @param  t: hitpoint distance
 * @param  ray: current ray
 * @param  *cylinder: current cylinder
 * @param  x: point on the cy axis
 * @retval 
 */
static bool	mcheck(float t, t_ray ray, t_cy_list *cylinder, t_vector X)
{
	float		m;

	m = vec_dot(ray.dir, cylinder->dir) * t + vec_dot(X, cylinder->dir);
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
	float		a;
	float		b;
	float		c;
	float		dist;
	float		t1;
	float		t2;
	t_vector	H;
	t_vector	C;
	t_vector	w;
	t_vector	h;
	t_vector	X;

	H = vec_sub(cylinder->center, vec_scale(cylinder->dir, cylinder->height / 2));
	C = vec_add(H, vec_scale(cylinder->dir, cylinder->height));
	h = vec_norm(vec_sub(H, C));
	w = vec_sub(ray.og, C);
	X = vec_sub(ray.og, H);

	a = vec_dot(ray.dir, ray.dir) - powf(vec_dot(ray.dir, h), 2.0);
	b = 2 * (vec_dot(ray.dir, w) - vec_dot(ray.dir, h) * vec_dot(w, h));
	c = vec_dot(w, w) - powf(vec_dot(w, h), 2.0) - powf(cylinder->radius, 2.0);

	dist = b * b - 4.0 * a * c;
	if (dist >= 0)
	{
		t1 = (-b + sqrtf(dist)) / (2 * a);
		t2 = (-b - sqrtf(dist)) / (2 * a);
		if (mcheck(t1, ray, cylinder, X) == true && mcheck(t2, ray, cylinder, X) == true)
		{
			if (t1 <= t2)
				return (t1);
			else
				return (t2);
		}
		if (mcheck(t1, ray, cylinder, X) == false)
			t1 = caps_check(ray, cylinder);
		if (mcheck(t2, ray, cylinder, X) == false)
			t2 = caps_check(ray, cylinder);
		if (t1 <= t2)
			return (t1);
		else
			return (t2);
	}
	else
	{
		// t1 = caps_check(ray, cylinder);
		// return (t1);
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
			tval.rgb.a = temp_shading(tval, ray, objs);
		}
		objs->cy_head = objs->cy_head->next;
		i++;
	}
	return (tval);
}