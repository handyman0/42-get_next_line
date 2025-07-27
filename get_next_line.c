#include "get_next_line.h"

char	*ft_read_and_store(int fd, char *resto)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*temp;

	if (!resto)
		resto = ft_strdup("");
	if (!resto)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(resto, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(resto);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(resto, buffer);
		free(resto);
		resto = temp;
		if (!resto)
			return (NULL);
	}
	if (bytes_read == 0 && !*resto)
	{
		free(resto);
		return (NULL);
	}
	return (resto);
}

char	*ft_extract_line(char *resto)
{
	int		i;
	char	*line;

	if (!resto || !*resto)
		return (NULL);
	i = 0;
	while (resto[i] && resto[i] != '\n')
		i++;
	if (resto[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (resto[i] && resto[i] != '\n')
	{
		line[i] = resto[i];
		i++;
	}
	if (resto[i] == '\n')
	{
		line[i] = resto[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_update_resto(char *resto)
{
	int		i;
	int		j;
	char	*new_resto;

	if (!resto)
		return (NULL);
	i = 0;
	while (resto[i] && resto[i] != '\n')
		i++;
	if (!resto[i])
	{
		free(resto);
		return (NULL);
	}
	new_resto = malloc((ft_strlen(resto) - i) * sizeof(char));
	if (!new_resto)
	{
		free(resto);
		return (NULL);
	}
	i++;
	j = 0;
	while (resto[i])
		new_resto[j++] = resto[i++];
	new_resto[j] = '\0';
	free(resto);
	return (new_resto);
}

char	*get_next_line(int fd)
{
	static char	*resto;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	resto = ft_read_and_store(fd, resto);
	if (!resto)
		return (NULL);
	line = ft_extract_line(resto);
	resto = ft_update_resto(resto);
	return (line);
}
