#include "ray_tracer.h"

/**
 * @brief  gets the normal of a plane
 * @param  *pl_node: the plane object to get the normal from
 * @param  ray: ray to get normal
 * @retval the normal vector of the plane
 */
t_vector	get_plane_normal(t_pl_list *pl_node, t_ray ray)
{
	t_vector	normal;

	if (0.0 > vec_dot(pl_node->dir, ray.dir))
		normal = vec_scale(pl_node->dir, -1);
	else
		normal = pl_node->dir;
	return (normal);
}

/**
 * @brief  counts the number of nodes in the plane linked list
 * @param  *pl_head: head of the circular plane linked list
 * @retval the count of nodes in the list
 */
static int	count_planes(t_pl_list *pl_head)
{
	t_pl_list	*tmp;
	int			count;

	if (pl_head->i == pl_head->next->i)
		return (1);
	tmp = pl_head->prev;
	count = 0;
	while (pl_head != tmp)
	{
		pl_head = pl_head->next;
		count++;
	}
	pl_head = pl_head->next;
	return (count + 1);
}

/**
 * @brief  calculates a ray-plane intersection
 * @param  ray: ray to calculate the ntersection with
 * @param  *plane: the current plane node to calculate the intersection with
 * @retval the closest intersection distance or infinity if no solution
 */
float	ray_plane(t_ray ray, t_pl_list *plane)
{
	float	t;
	float	denom;

	denom = vec_dot(ray.dir, plane->dir);
	if (fabs(denom) <= 0.0001f)
		t = 1.0 / 0.0;
	else
		t = vec_dot(vec_sub(plane->center, ray.og), plane->dir) / denom;
	return (t);
}

/**
 * @brief  iterates through all planes and calculates for possible intersections
 * @param  ray: ray to calculate the intersections with
 * @param  *objs: object data struct
 * @retval informations on the plane closest to screen
 */
t_tval	plane_loop(t_ray ray, t_objects *objs)
{
	t_tval	tval;
	int		pl_last_i;
	int		i;
	float	t;

	i = 0;
	tval.t = 1.0 / 0.0;
	pl_last_i = count_planes(objs->pl_head);
	while (i != pl_last_i)
	{
		t = ray_plane(ray, objs->pl_head);
		if (t < tval.t && t > ray.t_min && t < ray.t_max)
		{
			tval.t = t;
			tval.obj_i = objs->pl_head->i;
			tval.obj_type = PLANE;
			tval.rgb = objs->pl_head->rgb;
		}
		objs->pl_head = objs->pl_head->next;
		i++;
	}
	return (tval);
}
