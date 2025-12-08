/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:28:41 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/08 19:01:23 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_push(t_list *lst)
{
	if (lst->name == 'a')
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
}

static char	change_name(char name)
{
	if (name == 'a')
		return ('b');
	return ('a');
}

void	push(t_list **lst, t_list **lst_pushed_into)
{
	t_list	*tmp;
	char	name;

	if (!(*lst))
		return ;
	name = change_name((*lst)->name);
	print_push(*lst);
	if (!(*lst_pushed_into))
	{
		*lst_pushed_into = new_lst((*lst)->nb, name, (*lst)->origin,
				(*lst)->last_index);
		if (!lst_pushed_into)
			return ;
	}
	else
	{
		add_front_lst(lst_pushed_into, new_lst((*lst)->nb, name,
				(*lst)->origin, (*lst)->last_index));
		*lst_pushed_into = first_lst(*lst_pushed_into);
	}
	tmp = (*lst)->next;
	free(*lst);
	if (tmp)
	{
		tmp->prev = NULL;
		*lst = first_lst(tmp);
	}
	else
		*lst = NULL;
}
