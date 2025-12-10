/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:14:03 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/10 13:25:08 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse(t_list **lst)
{
	t_list *tmp;

	if (!lst || !*lst)
		return;
	ft_printf("rr%c\n", (*lst)->name);
	tmp = last_lst(*lst);
	tmp->prev->next = NULL;
	add_front_lst(lst, tmp);
	tmp->prev = NULL;
	*lst = first_lst(*lst);
}

void d_reverse(t_list **first_lst, t_list **second_lst)
{
	reverse(first_lst);
	reverse(second_lst);
}
