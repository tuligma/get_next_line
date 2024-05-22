/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:17:02 by npentini          #+#    #+#             */
/*   Updated: 2024/05/23 03:12:19 by npentini         ###   ########.fr       */
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
int		newline_counter(char *str);

#endif