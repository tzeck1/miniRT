#include "ray_tracer.h"

/**
 * @brief  calculates special point J necessary for cylinder cap shading
 * @param  light: information on direct light
 * @param  cylinder: information on the current cyinder node
 * @param  t: information on ray-cyinder intersection
 * @retval the point J
 */
t_vec	j_hit(t_dir_light light, t_cy_list cylinder, t_tval t)
{
	t_ray		ray;
	t_cy		cy;
	float		t1;
	float		t2;
	t_vec		j;

	ray.dir = vec_norm(vec_sub(t.hit_point, light.pos));
	ray.og = light.pos;
	cy = cy_calc(ray, &cylinder);
	t1 = (-cy.b + sqrtf(cy.dist)) / (2.0 * cy.a);
	t2 = (-cy.b - sqrtf(cy.dist)) / (2.0 * cy.a);
	if (t2 < t1)
		t1 = t2;
	j = vec_add(ray.og, vec_scale(ray.dir, t1));
	return (j);
}

/**
 * @brief  if one value is 0 it's ignored from the division thus i--
 * @param  light_dir: direction from light origin to hit point
 * @retval factor (0, 1, 2 or 3)
 */
int	get_factor(t_vec light_dir)
{
	int	i;

	i = 3;
	if (light_dir.x == 0)
		i--;
	if (light_dir.y == 0)
		i--;
	if (light_dir.z == 0)
		i--;
	return (i);
}
