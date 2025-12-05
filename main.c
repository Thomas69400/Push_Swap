/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:14:28 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/05 19:14:18 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
        if (!nbr)
        {
            ft_printf("Error\n");
            clear_lst(a);
            return (1);
        }
        a = init_list(a, *nbr);
        free(nbr);
    }
    swap(&a);
    push(&a, &b);
    printf("\nA : \n");
    print_list(a);
    printf("\nB : \n");
    print_list(b);
    push(&b, &a);
    // printf("\nAPRES 2EME PUSH \nA : \n");
    // print_list(a);
    // printf("\n\nB : \n");
    // print_list(b);
    //     sort_lst(a);
    clear_lst(a);
    clear_lst(b);
    return (0);
}
