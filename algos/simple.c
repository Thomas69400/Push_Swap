/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:15:56 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/21 20:09:23 by tchemin          ###   ########.fr       */
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

t_list	*simple(t_list *lst_a, t_list *lst_b, t_bench *bench, int size)
{
	t_list	*tmp;

	if (is_sorted(lst_a, 'a'))
		return (lst_a);
	if (size == 2)
		return (sort_2_nb(lst_a, bench));
	else if (size == 3)
		return (sort_3_nb(lst_a, bench));
	while (lst_b)
		push(&lst_b, &lst_a, bench);
	return (lst_a);
}
