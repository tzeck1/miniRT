/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42HN.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:29:28 by rsiebert          #+#    #+#             */
/*   Updated: 2022/08/02 16:44:05 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

/**
 * @brief  frees all dynamic allocated memory in and including data
 * @param  *data: data struct
 */
void	free_data(t_data *data)
{
	free_objects(data->objs);
	free(data->screen);
	free(data);
	data = NULL;
}

/**
 * @brief  always call when using exit
 * @note   leaks check, free, ...
 * @param  status: exit status
 */
void	ft_exit(int status)
{
	if (status == 0)
		printf(GREEN"exited with exit status: %d\n"RESET, status);
	else
		printf(RED"exited with exit status: %d\n"RESET, status);
	exit(status);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (parser(argc, argv) == false)
		ft_exit(EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	data->objs = init_objects(argv[1]);
	init_mlx(data);
	ray_tracing(data->screen, data->objs);
	mlx_loop(data->screen->mlx);
	mlx_terminate(data->screen->mlx);
	free_data(data);
	ft_exit(EXIT_SUCCESS);
}
