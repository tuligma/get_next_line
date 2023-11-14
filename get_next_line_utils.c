/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:18:29 by npentini          #+#    #+#             */
/*   Updated: 2023/10/02 13:02:31 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	newline_tracker(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i] && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

int	consolidation_len(t_list *list)
{
	int	i;
	int	x;

	if (!list)
		return (0);
	x = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				++x;
				return (x);
			}
			++i;
			++x;
		}
		list = list->next;
	}
	return (x);
}

void	transfer_str(t_list *list, char *s)
{
	int	i;
	int	x;

	if (!list)
		return ;
	x = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				s[x] = '\n';
				s[++x] = '\0';
				return ;
			}
			s[x++] = list->content[i++];
		}
		list = list->next;
	}
	s[x] = '\0';
}

void	ft_lstclear(t_list **list, t_list *clean_node, char *s)
{
	t_list	*tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (!s && !clean_node)
		return ;
	else if (clean_node->content[0])
		*list = clean_node;
	else
	{
		free(s);
		free(clean_node);
	}	
}
