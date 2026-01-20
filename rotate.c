/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:49:38 by tchemin           #+#    #+#             */
/*   Updated: 2026/01/20 11:02:20 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_rotate(char name, t_bench *bench)
{
	if (bench && bench->print_ope)
		ft_printf("r%c\n", 1, name);
	if (bench)
	{
		if (name == 'a')
			(*bench).ra++;
		else
			(*bench).rb++;
		(*bench).total++;
	}
}

int rotate(t_list **lst, t_bench *bench)
{
	t_list *tmp;

	if (!lst || !*lst)
		return (1);
	print_rotate((*lst)->name, bench);
	tmp = first_lst(*lst);
	*lst = tmp->next;
	tmp->next = NULL;
	add_back_lst(lst, tmp);
	(*lst)->prev = NULL;
	*lst = first_lst(*lst);
	return (0);
}

void d_rotate(t_list **a, t_list **b, t_bench *bench)
{
	if (!rotate(a, bench))
		(*bench).ra--;
	if (!rotate(b, bench))
		(*bench).rb--;
}
