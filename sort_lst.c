/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:15:56 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/08 22:10:31 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

	* Tri une liste sans faire des push swap et autres pour avoir leur index reel de FIN
 */
void sort(t_list *lst_a)
{
	t_list *array;
	t_list tmp;
	int i;
	int j;

	if (!lst_a)
		return;
	array = init_array(lst_a);
	i = 0;
	while (i++ < size_lst(lst_a))
	{
		j = 0;
		while (j < size_lst(lst_a) - 1)
		{
			if (array[j].nb > array[j + 1].nb)
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
	}
	place_final_index(array, lst_a);
	convert_final_index_to_binary(first_lst(lst_a));
}

/**
 *	Algo tout pouri qui fait de la merde (tri a bulle)
 */
t_list *simple(t_list *lst_a, t_list *lst_b)
{
	t_list *tmp;

	if (!lst_a)
		return (NULL);
	while (!is_sorted(lst_a))
	{
		tmp = first_lst(lst_a);
		if (tmp->next && tmp->nb > tmp->next->nb)
			swap(&lst_a);
		else if (tmp->next && tmp->nb < tmp->next->nb)
			push(&lst_a, &lst_b);
		else if (tmp->next && tmp->nb < last_lst(lst_a)->nb)
			rotate(&lst_a);
		else if (tmp->next && tmp->nb > last_lst(lst_a)->nb)
			reverse(&lst_a);
	}
	while (lst_b)
		push(&lst_b, &lst_a);
	if (!is_sorted(lst_a))
		lst_a = simple(lst_a, lst_b);
	return (lst_a);
}
