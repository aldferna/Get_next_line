/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianafernandez <adrianafernandez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:33:50 by aldferna          #+#    #+#             */
/*   Updated: 2024/10/19 17:52:20 by adrianafern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*join_bufs(char *buffer, char *read_buffer)
{
	char	*str;

	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	str = ft_strjoin(buffer, read_buffer);
	if (!str)
		return (NULL);
	free (buffer);
	free (read_buffer);
	return (str);
}

char *last_line(char *buffer)
{
	char *lastline;
	
	if (buffer[0] != '\0')
	{
		lastline = buffer;
		free(buffer);
		return (lastline);
	}
	return (free(buffer), NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*read_buffer;
	char		*line;
	int			bytesread;
	char		*ptr;
	char		*aux;
	int 		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytesread = 1;
	while (bytesread > 0)
	{
		read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!read_buffer)
			return (NULL);
		bytesread = read(fd, read_buffer, BUFFER_SIZE);
		if (bytesread == 0)
			return (last_line(buffer));
		if (bytesread < 0)
			return (free(read_buffer), NULL);
		buffer = join_bufs(buffer, read_buffer);
		if ((ptr = ft_strchr(buffer, '\n')))
		{
			len = ft_strlen(buffer) - ft_strlen(ptr);
			line = ft_substr(buffer, 0, len + 1);
			aux = buffer;
			ptr++;
			buffer = ft_substr(ptr, 0, ft_strlen(ptr));
			free(aux);
			return (line);
		}
	}
	return (NULL); 
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}
