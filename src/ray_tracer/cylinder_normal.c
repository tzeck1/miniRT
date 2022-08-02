#include "ray_tracer.h"

/**
 * @brief  
 * @note   
 * @param  norm: 
 * @param  scale: 
 * @param  light: 
 * @param  t: 
 * @retval 
 */
static t_vec	scale_norm(t_vec norm, float scale, t_dir_light light, t_tval t)
{
	t_vec		light_dir;
	float		ratio;
	int			factor;

	light_dir = vec_norm(vec_sub(light.pos, t.hit_point));
	ratio = vec_dot(norm, light_dir);
	ratio *= scale;
	factor = get_factor(light_dir);
	norm.x = ratio / factor / light_dir.x;
	norm.y = ratio / factor / light_dir.y;
	norm.z = ratio / factor / light_dir.z;
	if (norm.x == 1.0 / 0.0)
		norm.x = 0;
	if (norm.y == 1.0 / 0.0)
		norm.y = 0;
	if (norm.z == 1.0 / 0.0)
		norm.z = 0;
	return (norm);
}

/**
 * @brief  calc normal of cap and move it to generate gradiant
 * @param  *dir_l: light source
 * @param  cy: current cylinder we want to shade
 * @param  t: distance from hitpoint to origin
 * @param  m: distcance from l_cap to hitpoint on axis
 * @retval cylinder (cap) normal
 */
static t_vec	h_cap_norm(t_dir_light *dir_l, t_cy_list cy, t_tval t, float m)
{
	float	j_p;
	float	i_j;
	float	i_p;
	float	scale_ratio;

	j_p = m - cy.height;
	i_j = vec_len(vec_sub(j_hit(*dir_l, cy, t), t.hit_point));
	i_p = sqrtf(powf(i_j, 2.0) - powf(j_p, 2.0));
	scale_ratio = i_p / (4.0 * cy.radius) + 0.2;
	if (scale_ratio > 1.0)
		scale_ratio = 1.0;
	return (scale_norm(cy.dir, scale_ratio, *dir_l, t));
}

/**
 * @brief  calc normal of cap and move it to generate gradiant
 * @param  *dir_l: light source
 * @param  cy: current cylinder we want to shade
 * @param  t: distance from hitpoint to origin
 * @param  m: distcance from l_cap to hitpoint on axis
 * @retval cylinder (cap) normal
 */
static t_vec	l_cap_norm(t_dir_light *dir_l, t_cy_list cy, t_tval t, float m)
{
	float	j_p;
	float	i_j;
	float	i_p;
	float	scale_ratio;

	j_p = m * -1.0;
	i_j = vec_len(vec_sub(j_hit(*dir_l, cy, t), t.hit_point));
	i_p = sqrtf(powf(i_j, 2.0) - powf(j_p, 2.0));
	scale_ratio = i_p / (4.0 * cy.radius) + 0.2;
	if (scale_ratio > 1.0)
		scale_ratio = 1.0;
	return (scale_norm(vec_scale(cy.dir, -1.0), scale_ratio, *dir_l, t));
}

/**
 * @brief  gets the norm of an intersection point on a cylinder
 * @param  *cy: the cylinder object to get the norm from
 * @param  tval: struct with information on ray-cylinder intersection
 * @param  ray: ray to get the intersection point
 * @retval the norm vector of the cylinder from intersection point
 */
t_vec	get_cy_norm(t_objects *objs, t_cy_list cy, t_tval tval, t_ray ray)
{
	t_vec	norm;
	float	m;
	t_vec	h;
	t_vec	l;
	t_vec	axis;

	h = vec_scale(vec_norm(cy.dir), (cy.height / 2));
	h = vec_add(cy.center, h);
	l = vec_scale(vec_norm(cy.dir), (cy.height / 2));
	l = vec_sub(cy.center, l);
	axis = vec_norm(vec_sub(h, l));
	m = vec_dot(vec_sub(vec_add(ray.og, vec_scale(ray.dir, tval.t)), l), axis);
	if (vec_len(vec_sub(tval.hit_point, h)) < cy.radius)
		norm = h_cap_norm(objs->dir_l, cy, tval, m);
	else if (vec_len(vec_sub(tval.hit_point, l)) < cy.radius)
		norm = l_cap_norm(objs->dir_l, cy, tval, m);
	else
	{
		norm = vec_sub(tval.hit_point, vec_add(l, vec_scale(axis, m)));
		norm = vec_norm(norm);
	}
	return (norm);
}
