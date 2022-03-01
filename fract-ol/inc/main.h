#ifndef MAIN_H
# define MAIN_H
# include "../mlx/mlx.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_menu
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_menu;

typedef struct s_coordinates
{
	double	image_ratio;
	double	center_x;
	double	center_y;
	double	total_range_x;
	double	total_range_y;
	double	size_of_pixel;
	double	real_no;
	double	imaginary_no;
	double	julia_real;
	double	julia_imaginary;
}	t_coordinates;

typedef struct s_colors
{
	int	color;
	int	color_counter;
	int	zoom;
	int	zoom_counter;
	int	zoom_boundary;
	int	opacity;
}	t_colors;

typedef struct s_mlx {
	void			*mlx;
	void			*window;
	int				fractol_name;
	unsigned int	max_iterations;
	int				display_menu;
	t_coordinates	c;
	t_img			img;
	t_menu			menu;
	t_colors		colors;
}	t_mlx;

enum e_values{
	WINDOW_HEIGHT	= 960,
	WINDOW_WIDTH	= 1280,
	TOTAL_RANGE_Y	= 4,
	MANDELBROT		= 1,
	MANDELBAR		= 2,
	BURNING_SHIP	= 3,
	JULIA			= 4,
	ZOOM_SPEED		= 120,
	MAX_COLOR		= 16777215
};

void	init_data(t_mlx *mlx);

#endif