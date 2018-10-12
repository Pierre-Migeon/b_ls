/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_libft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:47:44 by pmigeon           #+#    #+#             */
/*   Updated: 2018/10/11 20:48:14 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_LIBFT_H
# define B_LIBFT_H
# include <sys/stat.h>
#include <stdlib.h>
#define BOOLEAN int

int		ft_strcmp(const char *s1, const char *s2);

typedef struct s_node {
	struct stat *data;
	char *name;
	struct s_node* next;
}				t_node;

typedef struct s_flags
{
	BOOLEAN lFLAG;
	BOOLEAN aFLAG;
	BOOLEAN rFLAG;
	BOOLEAN RFLAG;
	BOOLEAN tFLAG;
}				t_flags;

# endif
