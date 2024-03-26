/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:08:09 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/26 23:42:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ln_exists(char *buf)
{
	if (!buf)
		return (0);
	while (*buf && *buf != '\n')
		buf++;
	return (*buf == '\n');
}

char	*ft_get_remainder(char *line)
{
	char	*result;

	if (!ln_exists(line))
		return (free(line), NULL);
	result = ft_substr_2(line, ln_index(line) + 1, ft_strlen(line));
	free(line);
	return (result);
}

char	*ft_read_buffer(int fd, char *line)
{
	char	*buffer;
	ssize_t	lines_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	lines_read = 1;
	while (lines_read > 0 && !ln_exists(buffer))
	{
		lines_read = read(fd, buffer, BUFFER_SIZE);
		if (lines_read < 0)
			return (free(buffer), free(line), NULL);
		buffer[lines_read] = '\0';
		line = ft_strjoin_2(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*output;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_buffer(fd, line);
	if (!line || !line[0])
		return (NULL);
	output = ft_substr_2(line, 0, ln_index(line) + 1);
	line = ft_get_remainder(line);
	return (output);
}
