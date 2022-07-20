#include "ray_tracer.h"

float	caps_hit(t_ray ray, float radius, t_pl_list *h_cap, t_pl_list *c_cap)
{
	float		t1;
	float		t2;
	t_vector	p1;
	t_vector	p2;

	t1 = ray_plane(ray, h_cap);
	p1 = vec_add(ray.og, vec_scale(ray.dir, t1));
	t2 = ray_plane(ray, c_cap);
	p2 = vec_add(ray.og, vec_scale(ray.dir, t2));
	if (vec_len(vec_sub(h_cap->center, p1)) > radius)
		t1 = 1.0 / 0.0;
	if (vec_len(vec_sub(h_cap->center, p2)) > radius)
		t2 = 1.0 / 0.0;
	if (t1 <= t2)
		return (t1);
	else
		return (t2);
}

/**
 * @brief  checks if ray hits top or low cap of the cylinder
 * @param  ray: current ray
 * @param  *cylinder: current cylinder
 * @retval t for cap_hit, or inf in no hit
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
bool	mcheck(float t, t_ray ray, t_cy_list *cylinder, t_vector axis)
{
	float		m;
	t_vector	l;

	l = vec_sub(cylinder->center, vec_scale(vec_norm(cylinder->dir),
				cylinder->height / 2));
	m = vec_dot(vec_sub(vec_add(ray.og, vec_scale(ray.dir, t)), l), axis);
	if (m >= 0 && m <= cylinder->height)
		return (true);
	else
		return (false);
}