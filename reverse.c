/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:14:03 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/06 11:20:27 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse(t_list **lst)
{
    t_list *tmp;

    if (!lst || !*lst || !(*lst)->next)
        return;
    tmp = last_lst(*lst);
    tmp->prev->next = NULL;
    add_front_lst(lst, tmp);
    (*lst)->prev = tmp->prev;
    *lst = tmp;
}

void d_reverse(t_list **first_lst, t_list **second_lst)
{
    reverse(first_lst);
    reverse(second_lst);
}
