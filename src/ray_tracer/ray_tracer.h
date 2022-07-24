#ifndef RAY_TRACER_H
# define RAY_TRACER_H

# include "../../includes/miniRT.h"

/**
 * @param  t: smallest intersection distance
 * @param  rgb: color struct from closest intersection object
 */
typedef struct s_tval
{
	float	t;
	t_color	rgb;
}	t_tval;

typedef struct s_cy
{
	t_vector	h;
	t_vector	l;
	t_vector	axis;
	t_vector	w;
	float		a;
	float		b;
	float		c;
	float		dist;
}	t_cy;

/*	SPHERE	*/

t_tval	sphere_loop(t_ray ray, t_objects *objs);

/*	PLANE	*/

t_tval	plane_loop(t_ray ray, t_objects *objs);
float	ray_plane(t_ray ray, t_pl_list *plane);

/*	CYLINDER	*/

t_tval	cylinder_loop(t_ray ray, t_objects *objs);
bool	mcheck(float t, t_ray ray, t_cy_list *cylinder, t_vector axis);
float	caps_check(t_ray ray, t_cy_list *cylinder);
float	caps_hit(t_ray ray, float radius, t_pl_list *h_cap, t_pl_list *c_cap);
t_vector	get_cylinder_normal(t_cy_list *cy_node, t_tval tval, t_ray ray);

#endif