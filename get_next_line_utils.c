/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:50:11 by npentini          #+#    #+#             */
/*   Updated: 2024/05/24 01:00:55 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

int	newline_tracker(char *str)
{
	int	x;

	x = 0;
	if (str == NULL)
		return (0);
	while (str[x] != '\0' && str[x] != '\n')
		x++;
	if (str[x] == '\n')
		return (1);
	return (0);
}

void	*free_me(char *buffer, char *str)
{
	if (buffer != NULL)
		free(buffer);
	if (str != NULL)
		free(str);
	buffer = NULL;
	str = NULL;
	return (NULL);
}

int	newline_finder(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0' && str[x] != '\n')
		x++;
	if (str[x] == '\n')
		return (x);
	return (x);
}

char	*ft_strcpy(char *s1, char *s2, int s1_size, int s2_size)
{
	char	*dest;
	int		x;
	int		j;

	dest = (char *)malloc(s1_size + s2_size + 1);
	if (dest == NULL)
		return (NULL);
	x = -1;
	while (++x < s1_size)
		dest[x] = s1[x];
	j = -1;
	while (++j < s2_size)
		dest[x++] = s2[j];
	dest[x] = '\0';
	return (dest);
}
