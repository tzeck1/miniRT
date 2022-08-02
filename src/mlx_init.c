/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42HN.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:29:31 by rsiebert          #+#    #+#             */
/*   Updated: 2022/08/02 16:44:17 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

/**
 * @brief  checks if esc key is pressed
 * @param  key_data: contains key info
 * @param  *mlx: mlx pointer
 */
static void	key_hook(mlx_key_data_t	key_data, void *mlx)
{
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window((mlx_t *)mlx);
}

/**
 * @brief  sets a second image as black background 
 * @param  *screen: screen utils struct
 */
static void	set_background(t_screen *screen)
{
	mlx_image_t	*bg;
	int			x;
	int			y;

	x = 0;
	y = 0;
	bg = mlx_new_image(screen->mlx, screen->width, screen->height);
	while (x < screen->width)
	{
		y = 0;
		while (y < screen->height)
		{
			mlx_put_pixel(bg, x, y, 0x000000FF);
			y++;
		}
		x++;
	}
	mlx_image_to_window(screen->mlx, bg, 0, 0);
	mlx_set_instance_depth(bg->instances, -200);
}

/**
 * @brief  calls mlx_init, key_hook and creates a new image
 * @param  *data: data sctruct, saves mlx pointer and image info
 */
void	init_mlx(t_data *data)
{
	t_screen	*screen;

	screen = ft_calloc(1, sizeof(t_screen));
	screen->width = 750;
	screen->height = 750;
	screen->mlx = mlx_init(screen->width, screen->height, "miniRT", false);
	if (screen->mlx == NULL)
		ft_exit(EXIT_FAILURE);
	mlx_key_hook(screen->mlx, &key_hook, screen->mlx);
	screen->img = mlx_new_image(screen->mlx, screen->width, screen->height);
	if (screen->img == NULL)
		ft_exit(EXIT_FAILURE);
	mlx_image_to_window(screen->mlx, screen->img, 0, 0);
	set_background(screen);
	data->screen = screen;
}
