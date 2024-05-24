/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:42:47 by npentini          #+#    #+#             */
/*   Updated: 2024/05/25 03:05:43 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char		*get_next_line(int fd);
static char	*read_file(int fd, char *buffer, int *buff_size);
static char	*ft_strdup(char *buffer, int size, int state);
static char	*ft_strjoin(char *s1, char *s2);
static char	*ft_calloc(int size);
int			ft_strlen(char *str);
int			newline_tracker(char *str);
void		*free_me(char *buffer, char *str);
int			newline_finder(char *str);
char		*ft_strcpy(char *s1, char *s2, int s1_size, int s2_size);

#endif