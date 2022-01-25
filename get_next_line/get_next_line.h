#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*merge_strings(char *s1, char *s2);
int		str_contains_no_linebreak(char *str);
char	*get_next_line(int fd);
int		there_is_a_newline_within_backupstring(char *backup_str);

#endif