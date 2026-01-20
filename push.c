/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:28:41 by tchemin           #+#    #+#             */
/*   Updated: 2026/01/20 11:02:13 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_push(char name, t_bench *bench)
{
	if (bench && bench->print_ope)
	{
		if (name == 'a')
			ft_printf("pb\n", 1);
		else
			ft_printf("pa\n", 1);
	}
	if (bench)
	{
		if (name == 'a')
			(*bench).pb++;
		else
			(*bench).pa++;
		(*bench).total++;
	}
}

static char change_name(char name)
{
	if (name == 'a')
		return ('b');
	return ('a');
}

int push(t_list **lst, t_list **lst_pushed_into, t_bench *bench)
{
	t_list *tmp;
	char name;

	if (!lst || !(*lst))
		return (1);
	name = (*lst)->name;
	print_push(name, bench);
	tmp = *lst;
	*lst = tmp->next;
	if (*lst)
		(*lst)->prev = NULL;
	tmp->next = *lst_pushed_into;
	if (*lst_pushed_into)
		(*lst_pushed_into)->prev = tmp;
	*lst_pushed_into = tmp;
	(*lst_pushed_into)->name = change_name(name);
	return (0);
}
