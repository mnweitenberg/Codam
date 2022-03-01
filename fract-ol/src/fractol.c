#include "../inc/main.h"
#include "../inc/fractol.h"
#include "../inc/color.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	dst = &img->addr[offset];
	*(unsigned int *)dst = color;
}

static double	calculate_fractol(t_mlx *mlx,
	double *z_imaginary, double *z_real)
{
	double	i;
	double	r;

	r = *z_real;
	i = *z_imaginary;
	if (mlx->fractol_name == JULIA)
	{
		*z_real = r * r - i * i + mlx->c.julia_real;
		*z_imaginary = 2 * r * i + mlx->c.julia_imaginary;
	}
	if (mlx->fractol_name == BURNING_SHIP)
	{
		*z_real = fabs(r * r - i * i + mlx->c.real_no);
		*z_imaginary = fabs(2 * r * i + mlx->c.imaginary_no);
	}
	if (mlx->fractol_name == MANDELBAR)
	{
		*z_real = r * r - i * i + mlx->c.real_no;
		*z_imaginary = -2 * r * i + mlx->c.imaginary_no;
	}
	if (mlx->fractol_name == MANDELBROT)
	{
		*z_real = r * r - i * i + mlx->c.real_no;
		*z_imaginary = 2 * r * i + mlx->c.imaginary_no;
	}
	if (*z_imaginary * *z_imaginary + *z_real * *z_real > 4)
		return (0);
	return (1);
}

static void	draw_fractol(double x, double y, t_mlx *mlx)
{
	int				is_inside;
	unsigned int	iteration;
	double			z_imaginary;
	double			z_real;

	z_real = 0;
	z_imaginary = 0;
	if (mlx->fractol_name == JULIA)
	{
		z_real = mlx->c.real_no;
		z_imaginary = mlx->c.imaginary_no;
	}
	iteration = 0;
	is_inside = 1;
	while (iteration < mlx->max_iterations && is_inside == 1)
	{
		is_inside = calculate_fractol(mlx, &z_imaginary, &z_real);
		iteration++;
	}
	calculate_colors(mlx, iteration, is_inside);
	my_mlx_pixel_put(&mlx->img, x, y, mlx->colors.color);
}

static void	draw_menu(t_mlx *mlx)
{
	int		menu_width;
	int		menu_height;

	if (mlx->display_menu == 1)
	{
		menu_width = WINDOW_WIDTH;
		menu_height = WINDOW_HEIGHT;
		mlx->menu.img = mlx_xpm_file_to_image(mlx->mlx, "./img/menu.xpm",
				&menu_width, &menu_height);
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->menu.img, 0, 0);
	}
	else
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 0, 0);
}

void	calculate_and_draw_fractol(t_mlx *mlx)
{
	double	x;
	double	y;

	mlx->c.imaginary_no = -mlx->c.center_y;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		mlx->c.imaginary_no += mlx->c.size_of_pixel;
		mlx->c.real_no = -mlx->c.center_x;
		while (x < WINDOW_WIDTH)
		{
			mlx->c.real_no += mlx->c.size_of_pixel;
			draw_fractol(x, y, mlx);
			x++;
		}
		y++;
	}
	draw_menu(mlx);
}
