#include "ray_tracer.h"

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

static float	ray_plane(t_ray ray, t_pl_list *plane)
{
	return (0);
}

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
		if (t < tval.t && t > T_MIN && t < T_MAX)
		{
			tval.t = t;
			tval.rgb = objs->pl_head->rgb;
		}
		objs->pl_head = objs->pl_head->next;
		i++;
	}
	return (tval);
}
