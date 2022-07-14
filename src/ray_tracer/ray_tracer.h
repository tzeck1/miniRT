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

/*	SPHERE	*/

t_tval	sphere_loop(t_ray ray, t_objects *objs);

/*	PLANE	*/

t_tval	plane_loop(t_ray ray, t_objects *objs);

#endif