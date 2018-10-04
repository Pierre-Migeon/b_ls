/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_libft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:47:44 by pmigeon           #+#    #+#             */
/*   Updated: 2018/10/03 16:32:44 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_LIBFT_H
# define B_LIBFT_H
# include <sys/stat.h>
#include <stdlib.h>

typedef struct node {
	struct stat *data;
	struct node* next;
} t_node;
 
# endif
