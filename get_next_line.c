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

char	*finalize_str(t_list **list)
{
	char	*dest;

	if (!list || !*list)
		return (NULL);
	dest = malloc(consolidation_len(*list) + 1);
	if (!dest)
		return (NULL);
	transfer_str(*list, dest);
	reset_list(list);
	return (dest);
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

int	fetching(t_list **list, int fd)
{
	char	*bucket;
	int		state;

	state = 0;
	while (!newline_tracker(*list))
	{
		bucket = malloc(BUFFER_SIZE + 1);
		if (!bucket)
			return (state);
		state = read(fd, bucket, BUFFER_SIZE);
		if (state <= 0)
		{
			free(bucket);
			return (state);
		}
		bucket[state] = '\0';
		ft_lstnewadd_back(list, bucket);
	}
	return (state);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*str;
	int				state;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	state = fetching(&list, fd);
	if (state == -1)
	{
		ft_lstclear(&list, NULL, NULL);
		return (NULL);
	}
	str = finalize_str(&list);
	return (str);
}
