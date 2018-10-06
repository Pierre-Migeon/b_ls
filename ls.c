/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:40:00 by pmigeon           #+#    #+#             */
/*   Updated: 2018/10/03 22:10:59 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "b_libft.h"

void		ft_push(t_node **head, struct stat *input, char *name)
{
	t_node *new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return;
	new->data = input;
	new->name = name;
	new->next = *head;
	*head = new;
}

void	ft_swap(t_node *a, t_node *b)
{
	struct stat *temp;
	char *tempc;

	temp = a->data;
	a->data = b->data;
	b->data = temp;
	
	tempc = a->name;
	a->name = b->name;
	b->name = tempc;
}

void	ft_bubblesort(t_node *head)
{
	int swap;
	t_node *current;
	t_node *last; 
	
	swap = 1;
	last = NULL;
	while (swap == 1)
	{
		current = head;
		swap = 0;
		while (current->next != last)
		{
			if (ft_strcmp(current->name, current->next->name) > 1)
			{
				ft_swap(current, current->next);
				swap = 1;
			}
			current = current->next;
		}
		last = current;
	}
}

int		b_ls(void)
{
	DIR *dir;
	struct dirent *dp;
	struct stat *buf;
	t_node *head;

	head = NULL;
	if (!(dir = opendir(".")))
		return (1);
	while ((dp = readdir(dir)) != NULL)
	{
		if (!(buf = (struct stat *)malloc(sizeof(struct stat))))
			return (1);
		lstat(dp->d_name, buf);
		ft_push(&head, buf, dp->d_name);
	}	

	ft_bubblesort(head);

	while (head != NULL)
	{
		printf("%s\n", head->name);
		head = head->next;
	}

	closedir(dir);
	return (0);
}

int		main()
{
	b_ls();
	return (0);
}
