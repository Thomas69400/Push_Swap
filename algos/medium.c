/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:33:57 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/23 14:42:13 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int get_max_index(t_list *lst)
{
    int max;

    max = 0;
    while (lst)
    {
        if (lst->last_index > max)
            max = lst->last_index;
        lst = lst->next;
    }
    return (max);
}

int pos_max_index(t_list *lst, int max)
{
    int i;

    i = 0;
    while (lst)
    {
        if (lst->last_index == max)
            return (i);
        lst = lst->next;
        i++;
    }
    return (i);
}

void rotate_faster_to_max(t_list **lst, t_bench *bench)
{
    int pos;
    int size;

    pos = pos_max_index(*lst, get_max_index(*lst));
    size = size_lst(*lst);
    if (pos <= size)
        while (pos-- > 0)
            rotate(lst, bench);
    else
        while (pos++ <= size)
            reverse(lst, bench);
}

void push_b_to_a(t_list **lst_a, t_list **lst_b, t_bench *bench)
{
    while (*lst_b)
    {
        rotate_faster_to_max(lst_b, bench);
        push(lst_b, lst_a, bench);
    }
}

t_list *medium(t_list *lst_a, t_list *lst_b, t_bench *bench)
{
    int n_bucket;
    int n_pushed;
    int index;

    n_bucket = ft_sqrt(size_lst(lst_a));
    index = 1;
    if (is_sorted(lst_a, 'a'))
        return (lst_a);
    while (lst_a)
    {
        n_pushed = 0;
        while (lst_a && n_pushed < n_bucket)
        {
            if (lst_a->last_index < index * n_bucket)
            {
                push(&lst_a, &lst_b, bench);
                n_pushed++;
            }
            else
                rotate(&lst_a, bench);
        }
        index++;
    }
    push_b_to_a(&lst_a, &lst_b, bench);
    return (lst_a);
}
