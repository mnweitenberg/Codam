#include "../inc/main.h"
#include "../inc/utils.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(EXIT_SUCCESS);
}

void	error_message_and_exit(void)
{
	ft_putstr("\nPlease provide a valid fractol:\n");
	ft_putstr("./fractol [fractol_name]\n\n");
	ft_putstr("options:\tjulia\n\t\tmandelbrot\n");
	ft_putstr("\t\tmandelbar\n\t\tburning_ship\n");
	exit(EXIT_FAILURE);
}
