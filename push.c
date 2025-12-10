/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:28:41 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/10 14:20:59 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_push(t_list *lst)
{
	if (lst->name == 'a')
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
}

static char change_name(char name)
{
	if (name == 'a')
		return ('b');
	return ('a');
}

void push(t_list **lst, t_list **lst_pushed_into)
{
	t_list *tmp;
	char name;

	if (!lst || !(*lst))
		return;

	name = (*lst)->name;
	print_push(*lst);
	tmp = *lst;
	*lst = tmp->next;
	if (*lst)
		(*lst)->prev = NULL;

	tmp->next = *lst_pushed_into;
	if (*lst_pushed_into)
		(*lst_pushed_into)->prev = tmp;
	*lst_pushed_into = tmp;
	(*lst_pushed_into)->name = change_name(name);
}
