/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:21:19 by epandele          #+#    #+#             */
/*   Updated: 2026/02/07 13:00:16 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffer(int fd, char *buffer)
{
	char	*s1;
	ssize_t	bytes_read;

	s1 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s1)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, s1, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(s1), free(buffer), NULL);
		if (bytes_read == 0)
			return (free(s1), buffer);
		s1[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, s1);
	}
	free(s1);
	return (buffer);
}

static char	*get_line(char *buffer)
{
	char	*line;
	int		len;
	int		i;

	if (!buffer || !buffer[0])
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*get_new_buffer(char *buffer)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	new_buff = (char *)malloc(sizeof(char) * (ft_strlen(&buffer[i + 1]) + 1));
	if (!new_buff)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_buff[j++] = buffer[i++];
	new_buff[j] = '\0';
	free(buffer);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = get_new_buffer(buffer);
	return (line);
}
