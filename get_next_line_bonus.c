/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:17:04 by npentini          #+#    #+#             */
/*   Updated: 2023/09/04 08:52:52 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	reset_list(t_list **list)
{
	char	*new_line;
	t_list	*clean_node;
	t_list	*last_node;
	int		i;
	int		x;

	new_line = malloc(BUFFER_SIZE);
	clean_node = malloc(sizeof(t_list));
	if (!new_line || !clean_node)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	x = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] && last_node->content[++i])
		new_line[x++] = last_node->content[i];
	new_line[x] = '\0';
	clean_node->content = new_line;
	clean_node->next = NULL;
	ft_lstclear(list, clean_node, new_line);
}

char	*finalize_str(t_list *list)
{
	char	*dest;

	if (!list)
		return (NULL);
	dest = malloc(consolidation_len(list) + 1);
	if (!dest)
		return (NULL);
	transfer_str(list, dest);
	return (dest);
}

void	ft_lstnewadd_back(t_list **list, char *s, int fd)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = s;
	new_node->next = NULL;
	if (!list[fd])
		list[fd] = new_node;
	else
		ft_lstlast(list[fd])->next = new_node;
}

void	fetching(t_list **list, int fd)
{
	char	*dest;
	int		state;

	while (!newline_tracker(list[fd]))
	{
		dest = malloc(BUFFER_SIZE + 1);
		if (!dest)
			return ;
		state = read(fd, dest, BUFFER_SIZE);
		if (state <= 0)
		{
			free(dest);
			if (state == -1)
				ft_lstclear(&list[fd], NULL, NULL);
			return ;
		}
		dest[state] = '\0';
		ft_lstnewadd_back(list, dest, fd);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list[4096];
	char			*str;

	if (BUFFER_SIZE < 0 || fd < 0 || fd > 4096)
		return (NULL);
	fetching(list, fd);
	if (!list[fd])
		return (NULL);
	str = finalize_str(list[fd]);
	reset_list(&list[fd]);
	return (str);
}
