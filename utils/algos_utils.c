/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:38:34 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/19 14:25:13 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int is_sorted(t_list *lst, char order)
{
	if (!lst)
		return (1);
	lst = first_lst(lst);
	if (order == 'a')
	{
		while (lst->next)
		{
			if (lst->nb > lst->next->nb)
				return (0);
			lst = lst->next;
		}
	}
	else
	{
		while (lst->next)
		{
			if (lst->nb < lst->next->nb)
				return (0);
			lst = lst->next;
		}
	}
	return (1);
}
