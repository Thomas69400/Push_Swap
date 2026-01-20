/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:33:46 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/26 13:55:30 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_to_next(t_list **lst_a, t_list **lst_b, int index_bit,
		t_bench *bench)
{
	int	i;
	int	size;

	size = size_lst(*lst_a);
	i = 0;
	while (i < size)
	{
		if (!((*lst_a)->last_index & (1 << index_bit)))
			push(lst_a, lst_b, bench);
		else
			rotate(lst_a, bench);
		i++;
	}
}

t_list	*complex(t_list *lst_a, t_list *lst_b, t_bench *bench)
{
	int	index_bit;
	int	max_bit;

	if (is_sorted(lst_a, 'a'))
		return (lst_a);
	index_bit = 0;
	max_bit = get_size_of_bin(get_last_index_min_max(lst_a, "max"));
	while (index_bit <= max_bit)
	{
		rotate_to_next(&lst_a, &lst_b, index_bit, bench);
		while (lst_b)
			push(&lst_b, &lst_a, bench);
		index_bit++;
		if (is_sorted(lst_a, 'a'))
			return (lst_a);
	}
	return (lst_a);
}
