/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:49:38 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/09 19:41:44 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	ft_printf("r%c\n", (*lst)->name);
	tmp = first_lst(*lst);
	*lst = tmp->next;
	add_back_lst(lst, tmp);
	(*lst)->prev = NULL;
	tmp->next = NULL;
}

void	d_rotate(t_list **first_lst, t_list **second_lst)
{
	rotate(first_lst);
	rotate(second_lst);
}
