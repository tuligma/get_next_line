/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:10:43 by npentini          #+#    #+#             */
/*   Updated: 2023/09/04 09:02:30 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}		t_list;

char	*get_next_line(int fd);
void	fetching(t_list **list, int fd);
void	ft_lstnewadd_back(t_list **list, char *s, int fd);
char	*finalize_str(t_list *list);
void	reset_list(t_list **list);
t_list	*ft_lstlast(t_list *list);
int		newline_tracker(t_list *list);
int		consolidation_len(t_list *list);
void	transfer_str(t_list *list, char *s);
void	ft_lstclear(t_list **list, t_list *clean_node, char *s);
#endif
