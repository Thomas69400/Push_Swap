/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:15:56 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/26 13:55:43 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*sort_3_nb(t_list *lst, t_bench *bench)
{
	int	disorder;

	disorder = (int)compute_disorder(lst) * 100;
	if (disorder == 100)
	{
		swap(&lst, bench);
		reverse(&lst, bench);
	}
	else
	{
		if (lst->nb > lst->next->next->nb
			&& lst->next->nb < lst->next->next->nb)
			rotate(&lst, bench);
		else if (lst->nb > lst->next->nb && lst->nb < lst->next->next->nb)
			swap(&lst, bench);
		else if (lst->nb < lst->next->nb && lst->nb > lst->next->next->nb)
			reverse(&lst, bench);
		else if (lst->nb < lst->next->nb && lst->nb < lst->next->next->nb)
		{
			swap(&lst, bench);
			rotate(&lst, bench);
		}
	}
	return (lst);
}

t_list	*sort_2_nb(t_list *lst, t_bench *bench)
{
	rotate(&lst, bench);
	return (lst);
}

int	pos_min_index(t_list *lst, int min)
{
	int	i;

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

void	rotate_faster_to_min(t_list **lst, t_bench *bench)
{
	int	pos;
	int	size;

	pos = pos_min_index(*lst, get_last_index_min_max(*lst, "min"));
	size = size_lst(*lst);
	if (pos <= size / 2)
		while (pos-- > 0)
			rotate(lst, bench);
	else
		while (pos++ < size)
			reverse(lst, bench);
}

t_list	*simple(t_list *lst_a, t_list *lst_b, t_bench *bench, int size)
{
	if (is_sorted(lst_a, 'a'))
		return (lst_a);
	if (size == 2)
		return (sort_2_nb(lst_a, bench));
	if (size == 3)
		return (sort_3_nb(lst_a, bench));
	while (lst_a)
	{
		rotate_faster_to_min(&lst_a, bench);
		push(&lst_a, &lst_b, bench);
	}
	while (lst_b)
		push(&lst_b, &lst_a, bench);
	return (lst_a);
}
