/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:53:47 by npentini          #+#    #+#             */
/*   Updated: 2023/09/27 17:00:06 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>

int	main(void)
{
	const char	*filename;
	t_list		*current_node;
	t_list		*head;
	t_list		*new_node;
	t_list		*temp;
	char		*line;
	int			fd1;
	int			i;
	int			x;

	filename = "42_no_nl";
	fd1 = -1;
	fd1 = open(filename, O_RDONLY);
	i = 1;
	head = NULL;
	current_node = NULL;
	line = NULL;
	printf("\n\n|-+++++++++Main Function++++++++++-|");
	printf("\n|");
	printf("\n|");
	printf("\n|-->	THE GET NEXT LINE FUNCTION:");
	printf("\n|");
	printf("\n|");
	printf("\n|-->	Iteration %d of main function", i);
	printf("\n|");
	printf("\n|-->	File:		%s", filename);
	printf("\n|");
	printf("\n|-->	Argument/s:	fd1 = %i", fd1);
	printf("\n|");
	printf("\n|-->	Buffer size:	%i", BUFFER_SIZE);
	printf("\n|");
	printf("\n|-->	<Control flow>");
	printf("\n|");
	printf("\n|-->	Does the return value of get_next_line function");
	printf("\n|   	with argument fd1, non-zero or non-null?");
	printf("\n|");
	printf("\n|-->	If NO: it will ignore the while loop and continue.");
	printf("\n|-->	If YES: it will execute the statement of the loop.");
	printf("\n|");
	printf("\n|-+++++++++++++++++++++++++++++++++-|");
	while ((line = get_next_line(fd1)))
	{
		printf("\n\n\n\n");
		printf("\n\n|-+++++++++Main Function++++++++++-|");
		printf("\n|");
		printf("\n|->>>>>>>>>Loop Iteration %i>>>>>>>>-|", i);
		printf("\n|");
		x = 0;
		printf("\n|-->	Line %d.-> ", i);
		while (line[x] != '\0')
		{
			if (line[x] == '\n')
				printf("\\n");
			else
				putchar(line[x]);
			x++;
			if (line[x] == '\0')
				printf("\\0");
		}
		printf("\n|");
		printf("\n|-->	<Deallocated the memory of line");
		printf("\n|   	 using free function.>");
		printf("\n|");
		printf("\n|-->	free(line);");
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			perror("Error allocating memory!)");
			return (1);
		}
		new_node->content = strdup(line);
		new_node->next = NULL;
		if (head == NULL)
		{
			head = new_node;
			current_node = new_node;
		}
		else
		{
			current_node->next = new_node;
			current_node = new_node;
		}
		free(line);
		printf("\n|");
		printf("\n|");
		printf("\n|-<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-|");
		i++;
	}
	printf("\n\n\n\n");
	printf("\n\n|-+++++++++Main Function++++++++++-|");
	printf("\n|");
	printf("\n|->>>>>>>>>Loop Iteration %i>>>>>>>>-|", i);
	printf("\n|");
	printf("\n|-->	Line %i:	NULL", i);
	printf("\n|");
	printf("\n|");
	printf("\n|-->	<Close the fd1 by using close function.>");
	printf("\n|");
	printf("\n|-->	close(fd1);");
	printf("\n|");
	printf("\n|");
	printf("\n|-+++++++++End of Main Function++++++++++-|");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n|-++++++++++++++++Summary++++++++++++++++-|");
	printf("\n|");
	printf("\n|");
	printf("\n|-->	Lines read from \"%s\" file:", filename);
	printf("\n|");
	current_node = head;
	i = 1;
	while (current_node != NULL)
	{
		printf("\n|-->	Line %i:	", i);
		x = 0;
		while (current_node->content[x] != '\0')
		{
			if (current_node->content[x] == '\n')
				printf("\\n");
			else
				putchar(current_node->content[x]);
			x++;
			if (current_node->content[x] == '\0')
				printf("\\0");
		}
		i++;
		current_node = current_node->next;
	}
	if (current_node == NULL)
		printf("\n|-->	Line %i:	NULL", i);
	printf("\n|");
	printf("\n|");
	printf("\n|-++++++++++++End of Summary++++++++++++-|");
	printf("\n\n");
	close(fd1);
	current_node = head;
	while (current_node != NULL)
	{
		temp = current_node;
		current_node = current_node->next;
		free(temp->content);
		free(temp);
	}
	return (0);
}
