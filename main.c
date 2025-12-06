/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:14:28 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/06 11:46:42 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_list *lst)
{
    t_list *temp = lst;
    while (temp)
    {
        ft_printf("%d\n", temp->nb);
        temp = temp->next;
    }
}

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;
    int i;
    int *nbr;

    if (argc <= 1)
        return (1);
    i = 0;
    a = NULL;
    b = NULL;
    while (++i < argc)
    {
        nbr = ft_atoi(argv[i]);
        a = init_list(a, nbr);
        if (!a)
        {
            ft_printf("Error\n");
            return (1);
        }
        free(nbr);
    }
    // sort_lst(a, b);
    clear_lst(a);
    clear_lst(b);
    return (0);
}
