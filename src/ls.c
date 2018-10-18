/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:40:00 by pmigeon           #+#    #+#             */
/*   Updated: 2018/10/18 13:00:05 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "../includes/b_libft.h"

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

int		timesort(t_node *a, t_node *b)
{
	if (a->data->st_mtimespec.tv_sec < b->data->st_mtimespec.tv_sec)
		return (1);
	else if (a->data->st_mtimespec.tv_sec == b->data->st_mtimespec.tv_sec)
	{
		if (a->data->st_mtimespec.tv_nsec < b->data->st_mtimespec.tv_nsec)
			return (1);
		else if (a->data->st_mtimespec.tv_nsec == b->data->st_mtimespec.tv_nsec)
			return (ft_strcmp(a->name, b->name));
	}
	return (0);
}

int		ft_determinesort(t_node *a, t_node *b, t_flags flags)
{
	if (flags.tFLAG)
	{
		if (flags.rFLAG)
			return (timesort(b, a));
		return (timesort(a, b));
	}
	else if (flags.rFLAG)
		return (ft_strcmp(b->name, a->name));
	else
		return (ft_strcmp(a->name, b->name));
	return (0);
}

int		ft_flaghandler(char **argv, t_flags *flags)
{
	int i;
	int k;

	i = 0;
	k = -1;
	while (argv[++i])
	{
		if (argv[i][0] != '-')
			return(i);
		if (argv[i][0] == '-' && argv[i][1] == '-')
			return (i + 1);
		while (argv[i][0] == '-' && argv[i][++k])
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

void	ft_printls(t_node *head, t_flags flags)
{
	while (head != NULL)
	{
		if (flags.aFLAG)
		{
			if (flags.lFLAG)
				printf("%s\n", head->name);
			else 
				printf("%s\t", head->name);
		}
		else if (head->name[0] != '.')
		{
			if (flags.lFLAG)
				printf("%s\n", head->name);
			else
				printf("%s\t", head->name);
		}
		head = head->next;
	}
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
	head = ft_qsort(head, flags);
	ft_printls(head, flags);
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
