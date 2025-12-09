/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:33:46 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/09 20:02:16 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_list(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	ft_printf("\n");
	while (temp)
	{
		ft_printf("%d --> %c / %d / %d \n", temp->nb, temp->name, temp->origin,
			temp->last_index);
		temp = temp->next;
	}
}

t_list	*faster_next(t_list *lst, int index_bit)
{
	int	size;
	int	i;

	if (!lst)
		return (NULL);
	i = 0;
	size = size_lst(lst);
	while (lst)
	{
		if (lst->last_index & (1 << index_bit) && i <= size / 2)
		{
			rotate(&lst);
			return (lst);
		}
		else if (lst->last_index & (1 << index_bit) && i > size / 2)
		{
			reverse(&lst);
			return (lst);
		}
		lst = lst->next;
		i++;
	}
	return (NULL);
}

int	is_bit_at_index(t_list *lst, int index_bit)
{
	if (!lst)
		return (0);
	lst = first_lst(lst);
	while (lst)
	{
		if (lst->last_index & (1 << index_bit))
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_list	*complex(t_list *lst_a, t_list *lst_b)
{
	int	index_bit;
	int	i;

	i = 0;
	index_bit = 0;
	while (!is_sorted(lst_a))
	{
		while (is_bit_at_index(lst_a, index_bit) && !is_sorted(lst_a))
		{
			// print_list(lst_a);
			lst_a = faster_next(lst_a, index_bit);
			// print_list(lst_a);
			if (lst_a->last_index & (1 << index_bit))
				push(&lst_a, &lst_b);
			// return (lst_a);
		}
		ft_printf("\n ======= B ====== \n");
		print_list(lst_b);
		while (lst_b)
			push(&lst_b, &lst_a);
		ft_printf("\n ======= A ====== \n");
		print_list(lst_a);
		index_bit++;
		i++;
		if (i >= 10)
			return (lst_a);
	}
	return (lst_a);
}
