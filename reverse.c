/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:59:17 by madufeal          #+#    #+#             */
/*   Updated: 2026/01/28 15:53:18 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_reverse(char name, t_bench *bench)
{
	if (bench->to_print)
		ft_printf("rr%c\n", 1, name);
	if (name == 'a')
		(*bench).rra++;
	else
		(*bench).rrb++;
	(*bench).total++;
}

int	reverse(t_list **lst, t_bench *bench)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return (1);
	print_reverse((*lst)->name, bench);
	tmp = last_lst(*lst);
	tmp->prev->next = NULL;
	add_front_lst(lst, tmp);
	tmp->prev = NULL;
	*lst = first_lst(*lst);
	return (0);
}

void	d_reverse(t_list **a, t_list **b, t_bench *bench)
{
	if (!reverse(a, bench))
		(*bench).rra--;
	if (!reverse(b, bench))
		(*bench).rra--;
}
