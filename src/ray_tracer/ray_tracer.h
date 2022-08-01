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
	t_vec	hit_point;
	t_color	rgb;
	int		obj_i;
	int		obj_type;
}	t_tval;

typedef struct s_cy
{
	t_vec	h;
	t_vec	l;
	t_vec	axis;
	t_vec	w;
	float	a;
	float	b;
	float	c;
	float	dist;
}	t_cy;

t_tval		intersection(t_ray ray, t_objects *objs, bool flag);

/*	SPHERE	*/

t_tval		sphere_loop(t_ray ray, t_objects *objs);
t_vec		get_sphere_normal(t_sp_list sp_node, t_tval tval, t_ray ray);

/*	PLANE	*/

t_tval		plane_loop(t_ray ray, t_objects *objs);
float		ray_plane(t_ray ray, t_pl_list *plane);
t_vec		get_plane_normal(t_pl_list pl_node, t_ray ray);

/*	CYLINDER	*/

t_tval		cylinder_loop(t_ray ray, t_objects *objs);
bool		mcheck(float t, t_ray ray, t_cy_list *cylinder, t_vec axis);
float		caps_check(t_ray ray, t_cy_list *cylinder);
float		caps_hit(t_ray ray, float rad, t_pl_list *h_cap, t_pl_list *c_cap);
t_vec		get_cy_norm(t_objects *objs, t_cy_list cy, t_tval tval, t_ray ray);
t_cy		cy_calc(t_ray ray, t_cy_list *cylinder);
t_vec		j_hit(t_dir_light light, t_cy_list cylinder, t_tval t);
int			get_factor(t_vec light_dir);

/*	UTILS	*/

int			min(int n1, int n2);
int			get_color(t_color rgb, t_amb_light *amb, t_dir_light *dir);
int			init_shading(t_tval point, t_ray ray, t_objects *objs);

#endif