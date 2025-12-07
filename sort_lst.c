/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:15:56 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/07 19:09:27 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (lst->nb > lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list	*sort_lst(t_list *lst_a, t_list *lst_b)
{
	t_list	*tmp;

	if (!lst_a)
		return (NULL);
	while (!is_sorted(lst_a))
	{
		tmp = first_lst(lst_a);
		if (tmp->next && tmp->nb < tmp->next->nb)
			push(&lst_a, &lst_b);
		else if (tmp->next && tmp->nb < last_lst(lst_a)->nb)
			rotate(&lst_a);
		else if (tmp->next && tmp->nb > last_lst(lst_a)->nb)
			reverse(&lst_a);
		else if (tmp->next && tmp->nb > tmp->next->nb)
			swap(&lst_a);
	}
	while (lst_b)
		push(&lst_b, &lst_a);
	if (!is_sorted(lst_a))
		lst_a = sort_lst(lst_a, lst_b);
	return (lst_a);
}
