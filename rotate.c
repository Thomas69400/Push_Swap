/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:49:38 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/10 13:30:15 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_list **lst)
{
	t_list *tmp;

	if (!lst || !*lst)
		return;
	ft_printf("r%c\n", (*lst)->name);
	tmp = first_lst(*lst);
	*lst = tmp->next;
	tmp->next = NULL;
	add_back_lst(lst, tmp);
	(*lst)->prev = NULL;
	*lst = first_lst(*lst);
}

void d_rotate(t_list **first_lst, t_list **second_lst)
{
	rotate(first_lst);
	rotate(second_lst);
}
