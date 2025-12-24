/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:15:56 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/24 19:04:27 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// t_list *simple(t_list *lst_a, t_list *lst_b, t_bench *bench)
// {
// 	t_list *tmp;

// 	if (!lst_a)
// 		return (NULL);
// 	while (!is_sorted(lst_a, 'a'))
// 	{
// 		tmp = first_lst(lst_a);
// 		if (tmp->next && tmp->nb > tmp->next->nb)
// 			swap(&lst_a, bench);
// 		else if (tmp->next && tmp->nb < tmp->next->nb)
// 			push(&lst_a, &lst_b, bench);
// 		else if (tmp->next && tmp->nb < last_lst(lst_a)->nb)
// 			rotate(&lst_a, bench);
// 		else if (tmp->next && tmp->nb > last_lst(lst_a)->nb)
// 			reverse(&lst_a, bench);
// 	}
// 	while (lst_b)
// 		push(&lst_b, &lst_a, bench);
// 	if (!is_sorted(lst_a, 'a'))
// 		lst_a = simple(lst_a, lst_b, bench);
// 	return (lst_a);
// }

int pos_min_index(t_list *lst, int min)
{
	int i;

	i = 0;
	while (lst)
	{
		if (lst->last_index == min)
			return (i);
		lst = lst->next;
		i++;
	}
	return (i);
}

void rotate_faster_to_min(t_list **lst, t_bench *bench)
{
	int pos;
	int size;

	pos = pos_min_index(*lst, get_last_index_min_max(*lst, "min"));
	size = size_lst(*lst);
	if (pos <= size / 2)
		while (pos-- > 0)
			rotate(lst, bench);
	else
		while (pos++ < size)
			reverse(lst, bench);
}

t_list *simple(t_list *lst_a, t_list *lst_b, t_bench *bench)
{
	while (lst_a)
	{
		rotate_faster_to_min(&lst_a, bench);
		push(&lst_a, &lst_b, bench);
	}
	while (lst_b)
		push(&lst_b, &lst_a, bench);
	return (lst_a);
}
