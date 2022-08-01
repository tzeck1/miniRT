#include "ray_tracer.h"

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
