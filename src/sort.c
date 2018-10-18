/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:01:33 by pmigeon           #+#    #+#             */
/*   Updated: 2018/10/17 16:22:11 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/b_libft.h"

t_node	*ft_findend(t_node *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

t_node  *join(t_node *left_list, t_node *pivot, t_node *right_list)
{
	t_node *left_tail;
	pivot->next = right_list;
	if (left_list == NULL)    
    	return pivot;
	left_tail = ft_findend(left_list);
	left_tail->next = pivot;
	return (left_list);
}

void	secondsort(t_info *info, t_flags flags)
{
	if (ft_determinesort(info->pivot, info->current_node, flags) >= 0)
	{
		info->current_node->next = info->left_list;
		info->left_list = info->current_node;
	}
	else
	{
		info->current_node->next = info->right_list;
		info->right_list = info->current_node;
	}
}

t_node	*ft_qsort(t_node *list, t_flags flags)
{
	t_info info;

	if (list == NULL || list->next == NULL)
		return (list);
	info.pivot = ft_findend(list);
	info.left_list = NULL;
	info.right_list = NULL;
	info.current_node = list;
	while (info.current_node != NULL)
	{
		info.next_node = info.current_node->next;
		if (info.current_node != info.pivot)
		{
			secondsort(&info, flags);
		}
		info.current_node = info.next_node;
	}
	return (join(ft_qsort(info.left_list, flags), info.pivot, ft_qsort(info.right_list, flags)));
}
