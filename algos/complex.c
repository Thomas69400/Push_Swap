/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:33:46 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/10 14:41:56 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void print_list(t_list *lst)
{
	t_list *temp;

	temp = lst;
	ft_printf("\n");
	while (temp)
	{
		ft_printf("%d --> %c / %d / %d \n", temp->nb, temp->name, temp->origin,
				  temp->last_index);
		temp = temp->next;
	}
}

void faster_next(t_list **lst, int index_bit)
{
	int size = size_lst(*lst);
	int i = 0;
	t_list *tmp = *lst;

	while (tmp && (tmp->last_index & (1 << index_bit)))
	{
		tmp = tmp->next;
		i++;
	}
	if (!tmp)
		return;
	if (i <= size / 2)
		while (i-- > 0)
			rotate(lst);
	else
		while (i++ < size)
			reverse(lst);
}

int is_bit_at_index(t_list *lst, int index_bit)
{
	while (lst)
	{
		if (!(lst->last_index & (1 << index_bit)))
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_list *complex(t_list *lst_a, t_list *lst_b)
{
	int index_bit;

	index_bit = 0;
	while (!is_sorted(lst_a))
	{
		while (is_bit_at_index(lst_a, index_bit) == 1 && !is_sorted(lst_a))
		{
			faster_next(&lst_a, index_bit);
			push(&lst_a, &lst_b);
		}
		while (lst_b)
			push(&lst_b, &lst_a);
		print_list(lst_a);	
		index_bit++;
	}
	return (lst_a);
}
