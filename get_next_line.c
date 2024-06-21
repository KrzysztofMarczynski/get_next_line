/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarczyn <kmarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:28:23 by kmarczyn          #+#    #+#             */
/*   Updated: 2024/06/21 12:36:21 by kmarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *c)
{
	unsigned int	i;

	i = 0;
	while (c[i++] != '\0');
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char	*newline_pos;
	char	*buffer;

	ssize_t bytesRead;   // przechowuje liczbe bajtów
	char *line = NULL;   // przechowuje wskaźnik do alokowania
	size_t line_len = 0; // przechowuje długość odczytanej linijki
	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		if (fd == -1)
			return (NULL);
	bytesRead = read(fd, buffer, BUFFER_SIZE);
	if (bytesRead == -1)
		return (free(buffer), NULL);
	buffer[bytesRead] = '\0';
	newline_pos = ft_strchr(buffer, '\n');
	if (newline_pos != NULL)
		*newline_pos = '\0';
	line_len = ft_strlen(buffer);
	line = malloc(line_len + 1);
	if (!line)
		return (free(buffer), free(line), NULL);
	ft_strcpy(line, buffer);
	return (line);
}
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*test;

	fd = open("text.txt", O_RDONLY);
	test = get_next_line(fd);
	printf("test: %s", test);
	return (0);
}
