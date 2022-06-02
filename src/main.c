/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <@student.42heilbronn.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:06:34 by tzeck             #+#    #+#             */
/*   Updated: 2022/06/02 15:24:51 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

#include <memory.h>
#define WIDTH 1920
#define HEIGHT 1080

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		if (g_img->instances[0].y >= 0)
			g_img->instances[0].y -= 25;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		if (g_img->instances[0].y <= 1000 - 250)
			g_img->instances[0].y += 25;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		if (g_img->instances[0].x >= 0)
			g_img->instances[0].x -= 25;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		if (g_img->instances[0].x <= 1000 - 250)
			g_img->instances[0].x += 25;
}

void	test_program()
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 250, 250);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	test_program();
	return (EXIT_SUCCESS);
}
