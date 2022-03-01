#include "../inc/main.h"
#include "../inc/fractol.h"
#include "../inc/interaction.h"
#include "../inc/utils.h"

static int	check_if_provided_fractol_is_valid(char *fractol_name)
{
	if (ft_strncmp(fractol_name, "mandelbrot", 11) == 0)
		return (1);
	if (ft_strncmp(fractol_name, "mandelbar", 9) == 0)
		return (2);
	if (ft_strncmp(fractol_name, "burning_ship", 12) == 0)
		return (3);
	if (ft_strncmp(fractol_name, "julia", 5) == 0)
		return (4);
	error_message_and_exit();
	exit(EXIT_FAILURE);
}

void	init_data(t_mlx *mlx)
{
	mlx->c.image_ratio = (double)WINDOW_HEIGHT / (double)WINDOW_WIDTH;
	mlx->c.total_range_y = TOTAL_RANGE_Y;
	mlx->c.total_range_x = mlx->c.total_range_y / mlx->c.image_ratio;
	mlx->c.size_of_pixel = mlx->c.total_range_y / WINDOW_HEIGHT;
	mlx->c.center_x = mlx->c.total_range_x / 2;
	mlx->c.center_y = mlx->c.total_range_y / 2;
	mlx->c.real_no = 0;
	mlx->c.imaginary_no = 0;
	mlx->c.julia_real = 0;
	mlx->c.julia_imaginary = 0;
	mlx->colors.color = 0;
	mlx->colors.color_counter = 1;
	mlx->colors.zoom = 0;
	mlx->colors.zoom_counter = 0;
	mlx->colors.zoom_boundary = 0;
	mlx->colors.opacity = 200;
	mlx->max_iterations = 20;
}

static void	init(t_mlx	*mlx, char *fractol_name)
{
	mlx->fractol_name = check_if_provided_fractol_is_valid(fractol_name);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Fract-ol");
	mlx->img.img = mlx_new_image(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	init_data(mlx);
	mlx->display_menu = 1;
}

int	main(int argc, char **argv)
{
	t_mlx			mlx;

	if (argc < 2)
		error_message_and_exit();
	init(&mlx, argv[1]);
	calculate_and_draw_fractol(&mlx);
	mlx_hook(mlx.window, 17, 0, close_window, &mlx);
	mlx_mouse_hook(mlx.window, mouse_hook, &mlx);
	mlx_key_hook(mlx.window, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	exit(EXIT_SUCCESS);
}
