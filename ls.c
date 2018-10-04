/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:40:00 by pmigeon           #+#    #+#             */
/*   Updated: 2018/10/03 19:43:22 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "b_libft.h"

void		ft_push(t_node **head, struct stat *input)
{
	t_node *new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return;
	new->data = input;
	new->next = *head;
	*head = new;
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
		buf = (struct stat *)malloc(sizeof(struct stat));
		lstat(dp->d_name, buf);
		ft_push(&head, buf);
	}
	while (head != NULL)
	{
		printf("%llu\n", head->data->st_ino);
		head = head->next;
	}
	printf("\n");
	closedir(dir);
	return (0);
}

int		main()
{
	b_ls()
	return (0);
}
