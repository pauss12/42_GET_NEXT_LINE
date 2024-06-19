/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:50:06 by pmendez-          #+#    #+#             */
/*   Updated: 2023/10/06 17:57:17 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free_join(char *str, char *buffer)
{
	char	*aux;

	aux = ft_strjoin(str, buffer);
	free(str);
	return (aux);
}

static char	*ft_read_file(int fd, char *str)
{
	int		read_bytes;
	char	*buffer;

	if (str == NULL)
		str = ft_calloc(1, sizeof(char));
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = 0;
		str = ft_free_join(str, buffer);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

static char	*first_line(char *buffer)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	if (!buffer[0] || !buffer)
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = (char *)ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		line[i++] = '\n';
	}
	return (line);
}

static char	*pass_line(char *buffer)
{
	int		cont;
	int		j;
	char	*line;

	cont = 0;
	while (buffer[cont] && buffer[cont] != '\n')
		cont++;
	if (!buffer[cont])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - cont + 1), sizeof(char));
	if (!line)
		return (NULL);
	cont++;
	j = 0;
	while (buffer[cont])
		line[j++] = buffer[cont++];
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_read_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = first_line(buffer);
	buffer = pass_line(buffer);
	return (line);
}
