/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:33:46 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/20 18:50:14 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 *TODO Faire en sorte de chercher le plus rapide entre rotate ou reverse
 */
void	first_and_last(t_list *lst, int *first, int *last, int index_bit)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp && (tmp->last_index & (1 << index_bit)))
	{
		tmp = tmp->next;
		(*first)++;
	}
	tmp = last_lst(lst);
	while (tmp && (tmp->last_index & (1 << index_bit)))
	{
		tmp = tmp->prev;
		(*last)++;
	}
}

void	get_next(t_list **lst, int index_bit, t_bench *bench)
{
	int	size;
	int	first;
	int	last;

	size = size_lst(*lst);
	first = 0;
	last = 0;
	first_and_last(*lst, &first, &last, index_bit);
	if (first <= size / 2)
		while (first-- > 0)
			rotate(lst, bench);
	else
		while (first++ < size)
			reverse(lst, bench);
}

int	is_bit_at_index(t_list *lst, int index_bit)
{
	while (lst)
	{
		if (!(lst->last_index & (1 << index_bit)))
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	need_rotate(t_list *lst, int index_bit)
{
	int	is_next;

	is_next = 1;
	while (lst && !(lst->last_index & (1 << index_bit)))
		lst = lst->next;
	while (lst)
	{
		if (!(lst->last_index & (1 << index_bit)))
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_list	*complex(t_list *lst_a, t_list *lst_b, t_bench *bench)
{
	int	index_bit;

	index_bit = 0;
	while (!is_sorted(lst_a, 'a'))
	{
		while (is_bit_at_index(lst_a, index_bit) == 1)
		{
			get_next(&lst_a, index_bit, bench);
			// if (!need_rotate(lst_a, index_bit))
			// 	break ;
			push(&lst_a, &lst_b, bench);
			if (lst_b->next && lst_b->nb < lst_b->next->nb)
				swap(&lst_b, bench);
		}
		while (lst_b)
		{
			if (lst_b->next && lst_b->nb < lst_b->next->nb)
				swap(&lst_b, bench);
			push(&lst_b, &lst_a, bench);
		}
		index_bit++;
	}
	return (lst_a);
}
