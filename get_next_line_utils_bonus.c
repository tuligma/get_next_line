/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:18:29 by npentini          #+#    #+#             */
/*   Updated: 2023/09/04 09:01:40 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		while (list->content[i] && i < BUFFER_SIZE && list->content[i] != '\n')
			i++;
		if (list->content[i] == '\n')
			return (1);
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
		while (list->content[i] && list->content[i] != '\n')
			++i;
		if (list->content[i] == '\n')
			return (x += ++i);
		x += i;
		list = list->next;
	}
	return (x);
}

char	*transfer_str(t_list *list, char *s)
{
	int	i;
	int	x;

	if (!list)
		return (NULL);
	x = 0;
	while (list)
	{
		i = 0;
		while (list->content[i] && list->content[i] != '\n')
			s[x++] = list->content[i++];
		if (list->content[i] == '\n')
		{
			s[x] = '\n';
			s[++x] = '\0';
			return (s);
		}
		list = list->next;
	}
	s[x] = '\0';
	return (s);
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
	if (clean_node->content[0])
		*list = clean_node;
	else
	{
		free(s);
		free(clean_node);
	}
}
