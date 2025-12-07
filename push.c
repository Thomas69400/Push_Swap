/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:28:41 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/07 19:59:12 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*change_name(t_list *lst)
{
	if (lst->name == 'a')
		lst->name = 'b';
	else
		lst->name = 'a';
	return (lst);
}

void	print_push(t_list *lst)
{
	if (lst->name == 'a')
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
}

void	push(t_list **lst, t_list **lst_pushed_into)
{
	t_list	*tmp;

	if (!(*lst))
		return ;
	print_push(*lst);
	if (!(*lst_pushed_into))
	{
		*lst_pushed_into = new_lst((*lst)->nb);
		if (!lst_pushed_into)
			return ;
	}
	else
	{
		add_front_lst(lst_pushed_into, new_lst((*lst)->nb));
		*lst_pushed_into = first_lst(*lst_pushed_into);
	}
	tmp = (*lst)->next;
	free(*lst);
	if (tmp)
	{
		tmp->prev = NULL;
		tmp = change_name(tmp);
		*lst = first_lst(tmp);
	}
	else
		*lst = NULL;
}
