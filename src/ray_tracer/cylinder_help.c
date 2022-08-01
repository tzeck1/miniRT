#include "ray_tracer.h"

/**
 * @brief  calls plane_check and compares distance to cy radius
 * @param  ray: current ray
 * @param  radius: current radius
 * @param  *h_cap: top disk of the cylinder
 * @param  *c_cap: bottom disk of the cylinder
 * @retval 
 */
float	caps_hit(t_ray ray, float rad, t_pl_list *h_cap, t_pl_list *c_cap)
{
	float	t1;
	float	t2;
	t_vec	p1;
	t_vec	p2;

	t1 = ray_plane(ray, h_cap);
	p1 = vec_add(ray.og, vec_scale(ray.dir, t1));
	t2 = ray_plane(ray, c_cap);
	p2 = vec_add(ray.og, vec_scale(ray.dir, t2));
	if (vec_len(vec_sub(h_cap->center, p1)) > rad)
		t1 = 1.0 / 0.0;
	if (vec_len(vec_sub(c_cap->center, p2)) > rad)
		t2 = 1.0 / 0.0;
	free(h_cap);
	free(c_cap);
	if (t1 <= t2)
		return (t1);
	else
		return (t2);
}

/**
 * @brief  set info for top/bottom cap
 * @param  ray: current ray
 * @param  *cylinder: current cylinder
 * @retval t if anhitpoint was found, inf if no hit
 */
float	caps_check(t_ray ray, t_cy_list *cylinder)
{
	t_pl_list	*h_cap;
	t_pl_list	*c_cap;

	h_cap = ft_calloc(1, sizeof(t_pl_list));
	c_cap = ft_calloc(1, sizeof(t_pl_list));
	h_cap->center = vec_sub(cylinder->center, vec_scale(vec_norm(cylinder->dir),
				(cylinder->height / 2)));
	h_cap->dir = cylinder->dir;
	c_cap->center = vec_add(cylinder->center, vec_scale(vec_norm(cylinder->dir),
				(cylinder->height / 2)));
	c_cap->dir = cylinder->dir;
	return (caps_hit(ray, cylinder->radius, h_cap, c_cap));
}

/**
 * @brief  cuts of inf cylinder at cy.height
 * @param  t: hitpoint distance
 * @param  ray: current ray
 * @param  *cylinder: current cylinder
 * @param  axis: cylinder axis orientation vector
 * @retval 
 */
bool	mcheck(float t, t_ray ray, t_cy_list *cylinder, t_vec axis)
{
	float	m;
	t_vec	l;

	l = vec_sub(cylinder->center, vec_scale(vec_norm(cylinder->dir),
				cylinder->height / 2));
	m = vec_dot(vec_sub(vec_add(ray.og, vec_scale(ray.dir, t)), l), axis);
	if (m >= 0 && m <= cylinder->height)
		return (true);
	else
		return (false);
}
