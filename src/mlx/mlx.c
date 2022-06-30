#include "mlx.h"

void	ft_mlx_error(int error)
{
	if (error == INIT_ERR)
		fprintf(stderr, YELLOW "Error[mlx]: " INIT_ERR_MSG RESET);
}

void	mrt_key_hook(mlx_key_data_t keydata, void *mlx)
{
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		mlx_close_window((mlx_t *)mlx);
}

mlx_t	*init_mlx(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniRT", false);
	if (mlx == NULL)
		ft_mlx_error(INIT_ERR);
	mlx_key_hook(mlx, &mrt_key_hook, (void *)mlx);
	return (mlx);
}