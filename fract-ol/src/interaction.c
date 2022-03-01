#include "../inc/main.h"
#include "../inc/fractol.h"
#include "../inc/interaction.h"
#include "../inc/utils.h"
#include "../inc/color.h"

/*
      old_view
    *-----------------------------------------------------------------------*
    |                       ^                                               |
    |                       | z_up                                          |
    |        new_view       v                                               |
    |      *-----------------------------------------*                      |
    |z_left|                                         |       z_right        |
    |<---->|                mouse position           |<-------------------->|
    |      |                    +                    |                      |
    |      |                                         |                      |
    |      |                                         |                      |
    |      *-----------------------------------------*                      |
    |                       ^                                               |
    |                       |                                               |
    |                       |                                               |
    |                       | z_down                                        |
    |                       |                                               |
    |                       v                                               |
    *-----------------------------------------------------------------------*

	zoom_residu_x = z_left + z_right = total_range_x - total_range_x * zoom;
	zoom_residu_y = z_down + z_top   = total_range_y - total_range_y * zoom;
	z_top  = zoom_residu_y * position_of_y_as_percentage;
	z_left = zoom_residu_x * position_of_x_as_percentage;
*/
static void	zoom(t_mlx *mlx, double zoom, int x, int y)
{
	double	position_of_x_as_percentage;
	double	position_of_y_as_percentage;
	double	zoom_residu_x;
	double	zoom_residu_y;

	change_color(mlx);
	position_of_x_as_percentage = (double)x / WINDOW_WIDTH;
	position_of_y_as_percentage = (double)y / WINDOW_HEIGHT;
	zoom_residu_x = mlx->c.total_range_x - mlx->c.total_range_x * zoom;
	zoom_residu_y = mlx->c.total_range_y - mlx->c.total_range_y * zoom;
	mlx->c.center_x -= zoom_residu_x * position_of_x_as_percentage;
	mlx->c.center_y -= zoom_residu_y * position_of_y_as_percentage;
	mlx->c.total_range_y = mlx->c.total_range_y * zoom;
	mlx->c.total_range_x = mlx->c.total_range_y / mlx->c.image_ratio;
	mlx->c.size_of_pixel = mlx->c.total_range_y / WINDOW_HEIGHT;
}

int	mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	mlx->display_menu = -1;
	mlx_mouse_get_pos(mlx->window, &x, &y);
	if (keycode == MOUSE_CLICK)
	{
		mlx->c.julia_real = -mlx->c.center_x + x * mlx->c.size_of_pixel;
		mlx->c.julia_imaginary = -mlx->c.center_y + y * mlx->c.size_of_pixel;
	}
	if (keycode == SCROLL_UP)
		zoom(mlx, 0.90, x, y);
	if (keycode == SCROLL_DOWN)
		zoom(mlx, 1.10, x, y);
	calculate_and_draw_fractol(mlx);
	return (0);
}

static void	move_arrows(int keycode, t_mlx *mlx)
{
	int	move_speed;

	move_speed = 25;
	if (keycode == LEFT)
		mlx->c.center_x = mlx->c.center_x + move_speed * mlx->c.size_of_pixel;
	if (keycode == RIGHT)
		mlx->c.center_x = mlx->c.center_x - move_speed * mlx->c.size_of_pixel;
	if (keycode == DOWN)
		mlx->c.center_y = mlx->c.center_y - move_speed * mlx->c.size_of_pixel;
	if (keycode == UP)
		mlx->c.center_y = mlx->c.center_y + move_speed * mlx->c.size_of_pixel;
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == SPACEBAR)
		mlx->display_menu *= -1;
	else
		mlx->display_menu = -1;
	move_arrows(keycode, mlx);
	if (keycode == TAB)
		mlx->colors.color_counter += 1;
	if (keycode == PLUS && mlx->max_iterations < 100)
		mlx->max_iterations += 5;
	if (keycode == MINUS && mlx->max_iterations > 6)
		mlx->max_iterations -= 5;
	if (keycode == ONE)
		mlx->fractol_name = 1;
	if (keycode == TWO)
		mlx->fractol_name = 2;
	if (keycode == THREE)
		mlx->fractol_name = 3;
	if (keycode == FOUR)
		mlx->fractol_name = 4;
	if (keycode == ZERO || (keycode >= ONE && keycode <= FOUR))
		init_data(mlx);
	if (keycode == ESC)
		close_window(mlx);
	calculate_and_draw_fractol(mlx);
	return (0);
}
