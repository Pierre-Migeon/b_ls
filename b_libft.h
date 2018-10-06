/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_libft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:47:44 by pmigeon           #+#    #+#             */
/*   Updated: 2018/10/03 22:10:57 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_LIBFT_H
# define B_LIBFT_H
# include <sys/stat.h>
#include <stdlib.h>

int		ft_strcmp(const char *s1, const char *s2);

typedef struct node {
	struct stat *data;
	char *name;
	struct node* next;
} t_node;
 
# endif
