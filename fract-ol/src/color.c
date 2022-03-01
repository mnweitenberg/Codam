#include "../inc/main.h"
#include "../inc/color.h"

static int	create_color(int transparancy, int red, int green, int blue)
{
	return (transparancy << 24 | red << 16 | green << 8 | blue);
}

void	change_color(t_mlx *mlx)
{
	if (mlx->colors.zoom_boundary >= 0)
	{
		if (mlx->colors.zoom_counter % 255 == 0)
			mlx->colors.zoom_boundary++;
		if (mlx->colors.zoom_boundary % 2 != 0)
			mlx->colors.zoom += 5;
		else
			mlx->colors.zoom -= 5;
		mlx->colors.zoom_counter += 5;
	}
	else
	{
		mlx->colors.zoom = 5;
		mlx->colors.zoom_counter = 5;
		mlx->colors.zoom_boundary = -1;
	}
}

void	calculate_colors(t_mlx *mlx, int iteration, int is_inside)
{
	int	zoom;
	int	gradient;

	zoom = mlx->colors.zoom;
	gradient = 255 * iteration / mlx->max_iterations;
	if (mlx->colors.color_counter % 3 == 1)
	{
		mlx->colors.color = create_color(0, 255 - zoom, 255, 255 - zoom);
		if (is_inside == 0)
			mlx->colors.color = create_color(0, gradient, zoom, zoom);
	}
	else if (mlx->colors.color_counter % 3 == 2)
	{
		mlx->colors.color = MAX_COLOR;
		if (is_inside == 0)
			mlx->colors.color = MAX_COLOR * iteration / mlx->max_iterations;
	}
	else
	{
		mlx->colors.color = create_color(200, zoom, 255 - zoom, 255 - zoom);
		if (is_inside == 0)
			mlx->colors.color = create_color(200, 255 - zoom, gradient, zoom);
	}
}
