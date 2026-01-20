/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:27:19 by tchemin           #+#    #+#             */
/*   Updated: 2026/01/20 11:02:17 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_swap(char name, t_bench *bench)
{
	if (bench && bench->print_ope)
		ft_printf("s%c\n", 1, name);
	if (bench)
	{
		if (name == 'a')
			(*bench).sa++;
		else
			(*bench).sb++;
		(*bench).total++;
	}
}

int swap(t_list **lst, t_bench *bench)
{
	t_list *tmp;

	if (!(*lst)->next || !(*lst))
		return (1);
	print_swap((*lst)->name, bench);
	*lst = first_lst((*lst));
	tmp = (*lst)->next;
	tmp->prev = NULL;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	(*lst)->prev = tmp;
	(*lst) = tmp;
	return (0);
}

void d_swap(t_list *a, t_list *b, t_bench *bench)
{
	if (!swap(&a, bench))
		(*bench).sa--;
	if (swap(&b, bench))
		(*bench).sb--;
}
