/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:27:19 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/07 19:21:03 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	t_list	*tmp;

	if (!(*lst)->next || !(*lst))
		return ;
	ft_printf("s%c\n", (*lst)->name);
	*lst = first_lst((*lst));
	tmp = (*lst)->next;
	if (!lst || !tmp)
		return ;
	tmp->prev = NULL;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	(*lst)->prev = tmp;
	(*lst) = tmp;
}

void	d_swap(t_list *first_lst, t_list *second_lst)
{
	swap(&first_lst);
	swap(&second_lst);
}
