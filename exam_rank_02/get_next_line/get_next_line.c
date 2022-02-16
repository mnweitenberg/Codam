#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
	int i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = 0;
}

int str_contains_char(char *str, char c)
{
	while (*str)
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

int count_chars_until_linebreak_or_end_of_str(char *str)
{
	int i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i + 1);
}

char    *merge_strings(char *old, char *buffer)
{
	int		len_buffer = ft_strlen(buffer);
	int		len_old = ft_strlen(old);
	char    *new = (char *)malloc(sizeof(char) * (len_old + len_buffer + 1));
	if (!old)
		ft_strcpy(new, buffer);
	else
	{
		ft_strcpy(new, old);
		ft_strcpy(&new[len_old], buffer);
		free(old);
	}
	return (new);
}

char    *read_fd_and_add_to_backup(int fd, char *backup)
{
	int     bytesread = 1;
	char    buffer[BUFFER_SIZE + 1];
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		buffer[bytesread] = 0;
		backup = merge_strings(backup, buffer);
		if (str_contains_char(backup, '\n'))
			break ;
	}
	if (bytesread == -1 || (bytesread == 0 && backup[0] == 0))
	{
		free(backup);
		backup = NULL;
	}
	return (backup);
}

char    *copy_backup_until_linebreak(char *old)
{
	int 	i = count_chars_until_linebreak_or_end_of_str(old);
	char 	*new = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (old[i] && old[i] != '\n')
	{   
		new[i] = old[i];
		i++;
	}
	if (old[i] == '\n')
		new[i++] = '\n';
	new[i] = 0;
	return (new);
}

static char *update_backup(char *old)
{
	int 	start = count_chars_until_linebreak_or_end_of_str(old);
	char    *new = (char *)malloc(sizeof(char) * (ft_strlen(old) + 1));
	if (str_contains_char(old, '\n'))
		ft_strcpy(new, &old[start]);
	else
		new[0] = 0;
	free(old);
	return (new);
}

char    *get_next_line(int fd)
{
	static char     *backup;
	char            *line;
	if (fd < 0)
		return (NULL);
	backup = read_fd_and_add_to_backup(fd, backup);
	if (!backup)
		return (NULL);
	line = copy_backup_until_linebreak(backup);
	backup = update_backup(backup);
	return (line);
}
