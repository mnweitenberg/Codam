#include "get_next_line.h"

int	ft_strlen(char *str)
{
	if (!str)
		return (0);
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = 0;
}

int	str_contains_char(char *str, char c)
{
	while (*str)
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

char *merge_strings(char *old, char* buffer)
{
	int old_len = ft_strlen(old);
	int buf_len = ft_strlen(buffer);
	char *new 	= (char *)malloc(old_len + buf_len + 1);
	if (!old)
		ft_strcpy(new, buffer);
	else
	{
		ft_strcpy(new, old);
		ft_strcpy(&new[old_len], buffer);
		free(old);
	}
	return (new);
}

char	*read_fd_and_add_to_backup(int fd, char *backup)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytesread = 1;
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

int count_chars_until_linebreak_or_end_of_str(char *str)
{
	int i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	return (i);
}

char    *copy_backup_until_newline(char *old)
{
	int		i = count_chars_until_linebreak_or_end_of_str(old);
	char	*new = (char *)malloc(sizeof(char) * (i + 2));
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
	int		start = count_chars_until_linebreak_or_end_of_str(old);
	char	*new = (char *)malloc(sizeof(char) * (ft_strlen(old) + 1));
	if (str_contains_char(old, '\n'))
		ft_strcpy(new, &old[start]);
	else
		new[0] = 0;
	free(old);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	if (fd < 0)
		return (NULL);
	backup = read_fd_and_add_to_backup(fd, backup);
	if (!backup)
		return (NULL);
	line = copy_backup_until_newline(backup);
	backup = update_backup(backup);
	return (line);
}
