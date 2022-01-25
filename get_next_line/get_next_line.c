#include "get_next_line.h"

static char	*read_fd_and_add_to_backup(int fd, char *backup_str, char *buffer);
static char	*copy_backup_until_linebreak(char *backup_str);
static char	*update_backup(char *backup_str);

char	*get_next_line(int fd)
{
	static char		*backup_str[OPEN_MAX];
	char			*line;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	backup_str[fd] = read_fd_and_add_to_backup(fd, backup_str[fd], buffer);
	free(buffer);
	if (!backup_str[fd])
		return (NULL);
	line = copy_backup_until_linebreak(backup_str[fd]);
	backup_str[fd] = update_backup(backup_str[fd]);
	return (line);
}

/*
This function reads the input from the fd and stores it's content
into the buffer. It adds the content of buffer to the end of the
static string (backup_str) until this static string contains a 
linebreak character ('\n'). 
It returns NULL in case no new line is found
*/
static char	*read_fd_and_add_to_backup(int fd, char *backup_str, char *buffer)
{
	int		bytesread;

	bytesread = 1;
	while (bytesread > 0 && str_contains_no_linebreak(backup_str))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (!backup_str && bytesread == 0)
			return (NULL);
		if (bytesread == -1 || (bytesread == 0 && backup_str[0] == 0))
		{
			free(backup_str);
			return (NULL);
		}
		buffer[bytesread] = 0;
		backup_str = merge_strings(backup_str, buffer);
	}
	return (backup_str);
}

static int	count_length_of_string_until_linebreak(char *backup_str)
{
	int	i;

	if (!backup_str)
		return (0);
	i = 0;
	while (backup_str[i] != '\n' && backup_str[i])
		i++;
	i++;
	return (i);
}

/*
When BUFFER_SIZE is greater than 1, changes are that de backup_str
also contains characters that belong to the next line. We only want
to return the current line, so we copy the content up till the 
linebreak to a new string (output).
*/
static char	*copy_backup_until_linebreak(char *old)
{
	int		i;
	char	*new;

	if (!old)
		return (NULL);
	i = count_length_of_string_until_linebreak(old);
	new = (char *)malloc(sizeof(char) * (i + 2));
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

/*
We update backup_str to make sure it only stores the characters 
that don't belong to the current string. We do this by copying
the backup_str after we encounter the first linebreak.
*/
static char	*update_backup(char *old)
{
	int		start;
	char	*new;

	start = count_length_of_string_until_linebreak(old);
	if (there_is_a_newline_within_backupstring(old))
		new = (char *)malloc(sizeof(char) * (ft_strlen(old) - start + 1));
	else
		new = (char *)malloc(sizeof(char));
	if (!new)
	{
		free(old);
		return (NULL);
	}
	if (there_is_a_newline_within_backupstring(old))
		ft_strcpy(new, &old[start]);
	else
		new[0] = 0;
	free(old);
	return (new);
}
