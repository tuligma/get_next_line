/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:17:02 by npentini          #+#    #+#             */
/*   Updated: 2024/05/24 01:01:52 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

// extern int next_read_error;

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		newline_tracker(char *str);
void	*free_me(char *buffer, char *str);
int		newline_finder(char *str);
char	*ft_strcpy(char *s1, char *s2, int s1_size, int s2_size);

#endif