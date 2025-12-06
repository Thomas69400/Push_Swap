/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:28:41 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/06 10:49:06 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_list **lst, t_list **lst_pushed_into)
{
    t_list *tmp;

    if (!(*lst))
        return;
    if (!(*lst_pushed_into))
    {
        *lst_pushed_into = new_lst((*lst)->nb);
        if (!lst_pushed_into)
            return;
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
        *lst = first_lst(tmp);
    }
    else
        *lst = NULL;
}
