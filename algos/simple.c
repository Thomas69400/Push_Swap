/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:15:56 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/20 15:35:32 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*simple(t_list *lst_a, t_list *lst_b, t_bench *bench)
{
	t_list	*tmp;

	if (!lst_a)
		return (NULL);
	while (!is_sorted(lst_a, 'a'))
	{
		tmp = first_lst(lst_a);
		if (tmp->next && tmp->nb > tmp->next->nb)
			swap(&lst_a, bench);
		else if (tmp->next && tmp->nb < tmp->next->nb)
			push(&lst_a, &lst_b, bench);
		else if (tmp->next && tmp->nb < last_lst(lst_a)->nb)
			rotate(&lst_a, bench);
		else if (tmp->next && tmp->nb > last_lst(lst_a)->nb)
			reverse(&lst_a, bench);
	}
	while (lst_b)
		push(&lst_b, &lst_a, bench);
	if (!is_sorted(lst_a, 'a'))
		lst_a = simple(lst_a, lst_b, bench);
	return (lst_a);
}
