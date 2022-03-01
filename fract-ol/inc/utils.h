#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <unistd.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr(char *s);
int		close_window(t_mlx *mlx);
void	error_message_and_exit(void);

#endif