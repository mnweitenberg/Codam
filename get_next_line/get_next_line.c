#include "get_next_line.h"

char    *merge_strings(char *old, char *buffer)
{
    size_t  len_old;
    size_t  len_buffer;
    char    *new;

    len_buffer = ft_strlen(buffer);
    len_old = ft_strlen(old);
    new = (char *)malloc(sizeof(char) * (len_old + len_buffer + 1));
    if (!new)
        return (NULL);
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

char    *read_fd_and_add_to_backup(int fd, char *backup_str)
{
    int     bytesread;
    char    *buffer[BUFFER_SIZE + 1];

    bytesread = 1;
	while (bytesread > 0)
    {
        bytesread = read(fd, buffer, BUFFER_SIZE);
        buffer[bytesread] = 0;
        backup_str = merge_strings(backup_str, buffer);
        if (str_contains_char(backup_str, '\n'))
            break ;
    }
    if (bytesread == -1 || (bytesread == 0 && backup_str[0] == 0))
    {
        free(backup_str);
        backup_str = NULL;
    }
    return (backup_str);
}

char    *copy_backup_until_linebreak(char *old)
{
    int     i;
    char    *new;

    i = count_chars_until_linebreak_or_end_of_str(old);
    new = (char *)malloc(sizeof(char) * (i + 1));
    if (!new)
		return (NULL);
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

char *update_backup(char *old)
{
    int     start;
    char    *new;

	start = count_chars_until_linebreak_or_end_of_str(old);
	new = (char *)malloc(sizeof(char) * (ft_strlen(old) - start + 1));
	if (new)
		return (NULL);	
	if (str_contains_char(old, '\n'))
		ft_strcpy(new, &old[start]);
	else
		new[0] = 0;
	free(old);
    return (new);
}

char    *get_next_line(int fd)
{
    static char		*backup_str[OPEN_MAX];
    char            *line;

    if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	backup_str[fd] = read_fd_and_add_to_backup(fd, backup_str[fd]);
    if (!backup_str[fd])
        return (NULL);
    line = copy_backup_until_linebreak(backup_str[fd]);
    backup_str[fd] = update_backup(backup_str[fd]);
    return (line);
}
