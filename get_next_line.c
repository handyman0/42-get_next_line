/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:27:17 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/07/29 13:09:15 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_and_store(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*temp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!stash)
	{
		stash = ft_strdup("");
		return (stash);
	}
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			ft_free(stash);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
		if (!stash)
			return (NULL);
	}
	if (bytes_read == 0 && !*stash)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

char	*ft_extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || !*stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
	{
		i++;
		if (stash[i] == '\n')
			i++;
	}
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, i + 1);
	return (line);
}

char	*ft_update_line(char *stash)
{
	int		i;
	int		j;
	char	*buffer;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	while (stash[i] && stash[i] == '\n')
		i++;
	if (!stash[i])
		ft_free(stash);
	buffer = malloc((ft_strlen(stash) - i) * sizeof(char));
	j = 0;
	while (stash[i])
		buffer[j++] = stash[i++];
	free(stash);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_and_store(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_extract_line(stash);
	stash = ft_update_line(stash);
	return (line);
}
