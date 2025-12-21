/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:33:46 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/21 16:56:09 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_list(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	ft_printf("\n======= COMPLEX ========\n", 2);
	while (temp)
	{
		ft_printf("%d --> %c / %d / %d \n", 2, temp->nb, temp->name,
			temp->origin, temp->last_index);
		temp = temp->next;
	}
}

int	get_max_last_index(t_list *lst)
{
	int	max;

	max = 0;
	while (lst)
	{
		if (lst->nb > max)
			max = lst->last_index;
		lst = lst->next;
	}
	return (max);
}

void	rotate_to_next(t_list **lst_a, t_list **lst_b, int index_bit,
		t_bench *bench)
{
	int	i;
	int	size;
	int	ret;

	size = size_lst(*lst_a);
	i = 0;
	while (i < size)
	{
		ret = ((*lst_a)->last_index & (1 << index_bit));
		if (ret == 0)
			push(lst_a, lst_b, bench);
		else
			rotate(lst_a, bench);
		i++;
	}


}

int	is_bit_at_index(t_list *lst, int index_bit)
{
	while (lst)
	{
		if ((lst->last_index & (1 << index_bit)))
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_list	*complex(t_list *lst_a, t_list *lst_b, t_bench *bench)
{
	int	index_bit;
	int	max_bit;

	if (is_sorted(lst_a, 'a'))
		return (lst_a);
	index_bit = 0;
	max_bit = get_size_of_bin(get_max_last_index(lst_a));
	while (index_bit <= max_bit)
	{
		rotate_to_next(&lst_a, &lst_b, index_bit, bench);
		while (lst_b)
			push(&lst_b, &lst_a, bench);
		index_bit++;
	}
	return (lst_a);
}
