/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:50:11 by npentini          #+#    #+#             */
/*   Updated: 2024/05/23 02:38:25 by npentini         ###   ########.fr       */
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

int	newline_counter(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0' && str[x] == '\n')
		x++;
	return (x);
}