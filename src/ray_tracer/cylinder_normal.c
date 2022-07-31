#include "ray_tracer.h"

static t_vector	get_J_hit_point(t_dir_light light, t_cy_list cylinder, t_tval t)
{
	t_ray		ray;
	t_cy		cy;
	float		t1;
	float		t2;
	t_vector	J;

	ray.dir = vec_norm(vec_sub(t.hit_point, light.pos));
	ray.og = light.pos;
	cy = cy_calc(ray, &cylinder);
	t1 = (-cy.b + sqrtf(cy.dist)) / (2.0 * cy.a);
	t2 = (-cy.b - sqrtf(cy.dist)) / (2.0 * cy.a);
	if (t2 < t1)
		t1 = t2;
	J = vec_add(ray.og, vec_scale(ray.dir, t1));
	return (J);
}

static t_vector	scale_normal(t_vector normal, float scale_ratio, t_dir_light light, t_tval t)
{
	t_vector	light_dir;
	float		ratio;
	int			factor;

	light_dir = vec_norm(vec_sub(light.pos, t.hit_point));
	ratio = vec_dot(normal, light_dir);
	ratio *= scale_ratio;
	factor
	normal.x = ratio / 3 / light_dir.x;
	normal.y = ratio / 3 / light_dir.y;
	normal.z = ratio / 3 / light_dir.z;
	return (normal);
}

static t_vector	get_hcap_normal(t_objects *objs, t_cy_list cy, t_tval t, float m)
{
	float	JP;
	float	IJ;
	float	IP;
	float	scale_ratio;

	JP = m - cy.height;
	IJ = vec_len(vec_sub(get_J_hit_point(*objs->dir_l, cy, t), t.hit_point));
	IP = sqrtf(powf(IJ, 2.0) - powf(JP, 2.0));
	scale_ratio = IP / (4.0 * cy.radius) + 0.2;
	if (scale_ratio > 1.0)
		scale_ratio = 1.0;
	return (scale_normal(cy.dir, scale_ratio, *objs->dir_l, t));
}

static t_vector	get_lcap_normal(t_objects *objs, t_cy_list cy, t_tval t, float m)
{
	float	JP;
	float	IJ;
	float	IP;
	float	scale_ratio;

	JP = m * -1.0;
	IJ = vec_len(vec_sub(get_J_hit_point(*objs->dir_l, cy, t), t.hit_point));
	IP = sqrtf(powf(IJ, 2.0) - powf(JP, 2.0));
	scale_ratio = IP / (4.0 * cy.radius) + 0.2;
	if (scale_ratio > 1.0)
		scale_ratio = 1.0;
	return (scale_normal(vec_scale(cy.dir, -1.0), scale_ratio, *objs->dir_l, t));
}

/**
 * @brief  gets the normal of an intersection point on a cylinder
 * @param  *cy_node: the cylinder object to get the normal from
 * @param  tval: struct with information on ray-cylinder intersection
 * @param  ray: ray to get the intersection point
 * @retval the normal vector of the cylinder from intersection point
 */
t_vector	get_cylinder_normal(t_objects *objs, t_cy_list cy_node, t_tval tval, t_ray ray)
{
	t_vector	normal;
	float		m;
	t_vector	h;
	t_vector	l;
	t_vector	axis;

	h = vec_scale(vec_norm(cy_node.dir), (cy_node.height / 2));
	h = vec_add(cy_node.center, h);
	l = vec_scale(vec_norm(cy_node.dir), (cy_node.height / 2));
	l = vec_sub(cy_node.center, l);
	axis = vec_norm(vec_sub(h, l));
	m = vec_dot(vec_sub(vec_add(ray.og, vec_scale(ray.dir, tval.t)), l), axis);
	if (vec_len(vec_sub(tval.hit_point, h)) < cy_node.radius)
		normal = get_hcap_normal(objs, cy_node, tval, m);
	else if (vec_len(vec_sub(tval.hit_point, l)) < cy_node.radius)
		normal = get_lcap_normal(objs, cy_node, tval, m);
	else
	{
		normal = vec_sub(tval.hit_point, vec_add(l, vec_scale(axis, m)));
		normal = vec_norm(normal);
	}
	// debug_print_vector(normal);
	return (normal);
}
