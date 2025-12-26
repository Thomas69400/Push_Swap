/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:33:57 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/26 13:55:35 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pos_max_index(t_list *lst, int max)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->last_index == max)
			return (i);
		lst = lst->next;
		i++;
	}
	return (i);
}

void	rotate_faster_to_max(t_list **lst, t_bench *bench)
{
	int	pos;
	int	size;

	pos = pos_max_index(*lst, get_last_index_min_max(*lst, "max"));
	size = size_lst(*lst);
	if (pos <= size / 2)
		while (pos-- > 0)
			rotate(lst, bench);
	else
		while (pos++ < size)
			reverse(lst, bench);
}

void	push_b_to_a(t_list **lst_a, t_list **lst_b, t_bench *bench)
{
	while (*lst_b)
	{
		rotate_faster_to_max(lst_b, bench);
		push(lst_b, lst_a, bench);
	}
}

t_list	*medium(t_list *lst_a, t_list *lst_b, t_bench *bench)
{
	int	n_bucket;
	int	n_pushed;
	int	index;

	n_bucket = ft_sqrt(size_lst(lst_a));
	index = 1;
	if (is_sorted(lst_a, 'a'))
		return (lst_a);
	while (lst_a)
	{
		n_pushed = 0;
		while (lst_a && n_pushed < n_bucket)
		{
			if (lst_a->last_index < index * n_bucket)
			{
				push(&lst_a, &lst_b, bench);
				n_pushed++;
			}
			else
				rotate(&lst_a, bench);
		}
		index++;
	}
	push_b_to_a(&lst_a, &lst_b, bench);
	return (lst_a);
}
