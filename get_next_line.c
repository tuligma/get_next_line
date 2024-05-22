/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:16:44 by npentini          #+#    #+#             */
/*   Updated: 2024/05/23 03:41:09 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_calloc(int size)
{
	char	*dest;
	int		x;

	dest = (char *)malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (NULL);
	x = -1;
	while (++x < size + 1)
		dest[x] = 0;
	return (dest);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		s1_size;
	int		s2_size;
	int		x;
	int		j;

	if (s2 == NULL)
		return (NULL);
	s1_size = 0;
	if (s1 != NULL)
		s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	if (s1_size + s2_size == 0)
		return (free_me(s1, s2));
	dest = (char *)malloc(s1_size + s2_size + 1);
	if (dest == NULL)
		return (free_me(s1, s2));
	x = -1;
	while (++x < s1_size)
		dest[x] = s1[x];
	j = -1;
	while (++j < s2_size)
		dest[x++] = s2[j];
	dest[x] = '\0';
	if (s1 != NULL)
		free(s1);
	return (dest);
}

static char	*ft_strdup(char *buffer, int size)
{
	char	*dest;
	int		x;

	if (buffer == NULL || size == 0)
		return (free_me(buffer, NULL));
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (free_me(buffer, NULL));
	x = -1;
	while (++x < size)
		dest[x] = buffer[x];
	dest[x] = '\0';
	return (dest);
}

static char	*read_file(int fd, char *buffer, int *buff_size)
{
	char	*dest;

	while (newline_tracker(buffer) == 0 && *buff_size > 0)
	{
		dest = ft_calloc(BUFFER_SIZE);
		if (dest == NULL)
			return (free_me(buffer, NULL));
		*buff_size = read(fd, dest, BUFFER_SIZE);
		if (*buff_size == -1)
			return (free_me(NULL, dest));
		else
			dest[*buff_size] = '\0';
		if (*buff_size == 0)
		{
			dest = free_me(NULL, dest);
			break ;
		}
		buffer = ft_strjoin(buffer, dest);
		if (buffer == NULL)
			return (NULL);
		free(dest);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;
	int			buff_size;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (free_me(buffer, NULL));
	buff_size = 1;
	str = NULL;
	str = read_file(fd, buffer, &buff_size);
	if (buff_size == -1 || str == NULL || (str == NULL && buff_size == 0))
	{
		buffer = free_me(buffer, NULL);
		return (NULL);
	}
	buff_size = newline_finder(str);
	if (newline_tracker(str) == 1)
		buff_size++;
	if (ft_strlen(str + buff_size) > 0)
		buffer = ft_strdup(str + buff_size, ft_strlen(str + buff_size));
	else
		buffer = NULL;
	line = ft_strdup(str, buff_size);
	if (str != NULL)
		free(str);
	return (line);
}
