/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:14:11 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/05 19:02:59 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "ft_printf.h"
#include <stdlib.h>
#include <stddef.h>

typedef struct s_list
{
    int nb;
    struct s_list *prev;
    struct s_list *next;
} t_list;

int *ft_atoi(char *s);

void clear_lst(t_list *lst);
void add_back_lst(t_list **lst, t_list *new);
void add_front_lst(t_list **lst, t_list *new);
t_list *new_lst(int nbr);
t_list *last_lst(t_list *lst);
t_list *init_list(t_list *lst, int nbr);
t_list *first_lst(t_list *lst);

void swap(t_list **lst);
void push(t_list **lst, t_list **lst_pushed_into);
#endif