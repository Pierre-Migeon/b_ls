/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:40:00 by pmigeon           #+#    #+#             */
/*   Updated: 2018/10/11 21:04:21 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "./includes/b_libft.h"

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

void	ft_bubblesort(t_node *head, t_flags flags)
{
	int swap;
	t_node *current;
	t_node *last; 
flags.lFLAG = 0;	
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

int		ft_flaghandler(char **argv, t_flags *flags)
{
	int i;
	int k;

	i = 1;
	k = 1;
	while (argv[i++])			
	{
		if (argv[i][0] != '-')
			return(i);
		if (argv[i][0] == '-' && argv[i][1] == '-')
			return (i + 1);
		while (argv[i][0] == '-' && argv[i][k++])
		{
			if (argv[i][k] == 'l')
				flags->lFLAG = 1;
			if (argv[i][k] == 'a')
				flags->aFLAG = 1;
			if (argv[i][k] == 'r')
				flags->rFLAG = 1;
			if (argv[i][k] == 't')
				flags->tFLAG = 1;
		}
	}
	return(i);
}

int		b_ls(char *dirname, t_flags flags)
{
	DIR *dir;
	struct dirent *dp;
	struct stat *buf;
	t_node *head;

	head = NULL;
	if (!(dir = opendir(dirname)))
		return (1);
	while ((dp = readdir(dir)) != NULL)
	{
		if (!(buf = (struct stat *)malloc(sizeof(struct stat))))
			return (1);
		lstat(dp->d_name, buf);
		ft_push(&head, buf, dp->d_name);
	}	
	ft_bubblesort(head, flags);

	while (head != NULL)
	{
		printf("%s\n", head->name);
		head = head->next;
	}

	closedir(dir);
	return (0);
}

int		main(int argc, char **argv)
{
	t_flags	flags;
	int i;

	i = ft_flaghandler(argv, &flags);
	if (!argv[i] || argc == 1)
		b_ls(".", flags);
	while(argv[i])
		b_ls(argv[i++], flags);
	return (0);
}
