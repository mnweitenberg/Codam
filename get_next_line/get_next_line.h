#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
int		str_contains_char(char *str, char c);
int		count_chars_until_linebreak_or_end_of_str(char *str);
char	*get_next_line(int fd);

#endif