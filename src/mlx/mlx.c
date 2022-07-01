#include "mlx.h"

void	ft_mlx_error(int error)
{
	if (error == INIT_ERR)
		fprintf(stderr, YELLOW "Error[mlx]: " INIT_ERR_MSG RESET);
}

void	mrt_key_hook(mlx_key_data_t keydata, void *mlx)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window((mlx_t *)mlx);
}

mlx_t	*init_mlx(t_mlx_data *mlx_data)
{
	mlx_t	*mlx;

	mlx_data->height = 600;
	mlx_data->width = 600;
	mlx = mlx_init(mlx_data->width, mlx_data->height, "miniRT", false);
	if (mlx == NULL)
		ft_mlx_error(INIT_ERR);
	mlx_key_hook(mlx, &mrt_key_hook, (void *)mlx);
	mlx_data->image = mlx_new_image(mlx, mlx_data->width, mlx_data->height);
	mlx_image_to_window(mlx, mlx_data->image, 0, 0); // needs to be deleted at end
	return (mlx);
}