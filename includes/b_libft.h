/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_libft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:47:44 by pmigeon           #+#    #+#             */
/*   Updated: 2018/10/17 16:22:16 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_LIBFT_H
# define B_LIBFT_H
# include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#define BOOLEAN int

typedef struct s_node {
	struct stat *data;
	char *name;
	struct s_node* next;
}				t_node;

typedef struct s_info
{
    t_node *pivot;
    t_node *left_list;
    t_node *right_list;
    t_node *current_node;
    t_node *next_node;
}   t_info;

typedef struct s_flags
{
	BOOLEAN lFLAG;
	BOOLEAN aFLAG;
	BOOLEAN rFLAG;
	BOOLEAN RFLAG;
	BOOLEAN tFLAG;
}				t_flags;

int		ft_strcmp(const char *s1, const char *s2);
int		timesort(t_node *a, t_node *b);
int		ft_determinesort(t_node *current, t_node *next, t_flags flags);
int		ft_flaghandler(char **argv, t_flags *flags);
int		b_ls(char *dirname, t_flags flags);
void	ft_push(t_node **head, struct stat *input, char *name);
void	ft_swap(t_node *a, t_node *b);
void	ft_bubblesort(t_node *head, t_flags flags);
void	ft_printls(t_node *head, t_flags flags);
void  secondsort(t_info *info, t_flags flags);
t_node    *ft_findend(t_node *list);
t_node  *join(t_node *left_list, t_node *pivot, t_node *right_list);
t_node	*ft_qsort(t_node *list, t_flags flags);

# endif
