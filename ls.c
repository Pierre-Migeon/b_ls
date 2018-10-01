/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:40:00 by pmigeon           #+#    #+#             */
/*   Updated: 2018/10/01 15:00:00 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>
#include <dirent.h>

int		b_ls(void)
{
	DIR *dir;
    struct dirent *dp;

	if (!(dir = opendir(".")))
		return (1);
	while ((dp = readdir(dir)) != NULL)
	{
		printf("%s\t", dp->d_name);
	}
	printf("\n");
	closedir(dir);
	return (0);
}

int		main()
{
	b_ls();
	return (0);
}
