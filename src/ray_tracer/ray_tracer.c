/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42HN.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:28:24 by rsiebert          #+#    #+#             */
/*   Updated: 2022/08/02 16:28:25 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

/**
 * @brief  creates a ray corresponding to x and y screen position of pixel
 * @param  *screen: mlx data struct
 * @param  *cam: camera object struct
 * @param  x: x-value of pixel on screen
 * @param  y: y-value of pixel on screen
 * @retval ray struct
 */
static t_ray	create_ray(t_screen *screen, t_camera *cam, float x, float y)
{
	t_ray	ray;
	float	fov;

	fov = tanf((cam->fov * M_PI / 180.0) / 2.0);
	ray.og = vec_copy(cam->pos);
	ray.dir.x = cam->dir.x;
	ray.dir.x += x * (2.0 * fov / (float)screen->width) + cam->pos.x - fov;
	ray.dir.y = cam->dir.y;
	ray.dir.y += fov - y * (2.0 * fov / (float)screen->height) + cam->pos.y;
	ray.dir.z = cam->dir.z;
	ray.dir = vec_norm(ray.dir);
	ray.t_min = 0.1;
	ray.t_max = 1000.0;
	return (ray);
}

/**
 * @brief  calls the object loops and determines the object closest to screen
 * @param  ray: ray to calculate the intersections with
 * @param  *objs: objects data struct
 * @retval informations to the object closest to screen
 */
t_tval	intersection(t_ray ray, t_objects *objs, bool flag)
{
	t_tval	sp_tval;
	t_tval	pl_tval;
	t_tval	cy_tval;
	t_tval	result;

	sp_tval.t = 1.0 / 0.0;
	pl_tval.t = 1.0 / 0.0;
	cy_tval.t = 1.0 / 0.0;
	result.t = 1.0 / 0.0;
	if (objs->sp_head != NULL)
		sp_tval = sphere_loop(ray, objs);
	if (sp_tval.t < result.t)
		result = sp_tval;
	if (objs->pl_head != NULL)
		pl_tval = plane_loop(ray, objs);
	if (pl_tval.t < result.t)
		result = pl_tval;
	if (objs->cy_head != NULL)
		cy_tval = cylinder_loop(ray, objs);
	if (cy_tval.t < result.t)
		result = cy_tval;
	if (result.t != 1.0 / 0.0 && flag == true)
		result.rgb.a = init_shading(result, ray, objs);
	return (result);
}

/**
 * @brief  Loops through every pixel and calculates their color with ray tracing
 * @param  *screen: mlx data struct
 * @param  *objs: objects data struct
 */
void	ray_tracing(t_screen *screen, t_objects *objs)
{
	int		x;
	int		y;
	t_ray	ray;
	t_tval	tval;

	y = 0;
	while (y < screen->height)
	{
		x = 0;
		while (x < screen->width)
		{
			ray = create_ray(screen, objs->cam, x, y);
			tval = intersection(ray, objs, true);
			if (tval.t != 1.0 / 0.0)
			{
				mlx_put_pixel(screen->img, x, y,
					get_color(tval.rgb, objs->amb_l, objs->dir_l));
			}
			else
				mlx_put_pixel(screen->img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}
