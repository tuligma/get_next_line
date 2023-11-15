/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:17:04 by npentini          #+#    #+#             */
/*   Updated: 2023/10/06 09:26:39 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	reset_list(t_list **list)
{
	char	*new_line;
	t_list	*clean_node;
	t_list	*last_node;
	int		x;
	int		i;

	if (!list || !*list)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	new_line = malloc((BUFFER_SIZE - i) + 1);
	clean_node = malloc(sizeof(t_list));
	if (!new_line || !clean_node)
		return ;
	x = 0;
	while (last_node->content[i] && last_node->content[++i])
		new_line[x++] = last_node->content[i];
	new_line[x] = '\0';
	clean_node->content = new_line;
	clean_node->next = NULL;
	ft_lstclear(list, clean_node, new_line);
}

void	ft_lstnewadd_back(t_list **list, char *s)
{
	t_list	*new_node;

	if (!s)
		return ;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = s;
	new_node->next = NULL;
	if (!*list)
		*list = new_node;
	else
		ft_lstlast(*list)->next = new_node;
}

void	fetching(t_list **list, int fd)
{
	char	*bucket;
	int		state;

	while (!newline_tracker(*list))
	{
		bucket = malloc(BUFFER_SIZE + 1);
		if (!bucket)
			return ;
		state = read(fd, bucket, BUFFER_SIZE);
		if (state <= 0)
		{
			free(bucket);
			if (state == -1)
				ft_lstclear(list, NULL, NULL);
			return ;
		}
		bucket[state] = '\0';
		ft_lstnewadd_back(list, bucket);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	fetching(&list, fd);
	if (!list)
		return (NULL);
	str = malloc(consolidation_len(list) + 1);
	if (!str)
		return (NULL);
	str = transfer_str(list, str);
	if (!str)
		return (NULL);
	reset_list(&list);
	return (str);
}
