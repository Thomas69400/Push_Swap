/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:26:55 by tchemin           #+#    #+#             */
/*   Updated: 2026/01/20 11:03:06 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *init_list(t_list *lst, char *to_atoi)
{
	t_list *new;
	int *nbr;
	static int index = 0;

	while (has_numbers(to_atoi))
	{
		nbr = ft_atoi(&to_atoi);
		if (!nbr || verif_duplicate(lst, nbr))
		{
			if (nbr)
				free(nbr);
			return (clear_lst(lst));
		}
		new = new_lst(*nbr, 'a', index++, -1);
		if (!new)
			return (clear_lst(lst));
		add_back_lst(&lst, new);
		free(nbr);
	}
	return (lst);
}

t_list *init_array(t_list *lst)
{
	t_list *array;
	int index;

	if (!lst)
		return (NULL);
	array = malloc(sizeof(t_list) * size_lst(lst));
	if (!array)
		return (NULL);
	index = 0;
	while (lst)
	{
		array[index] = *lst;
		lst = lst->next;
		index++;
	}
	return (array);
}

void init_bench(t_bench *bench)
{
	(*bench).pa = 0;
	(*bench).pb = 0;
	(*bench).sa = 0;
	(*bench).sb = 0;
	(*bench).ss = 0;
	(*bench).ra = 0;
	(*bench).rb = 0;
	(*bench).rr = 0;
	(*bench).rra = 0;
	(*bench).rrb = 0;
	(*bench).rrr = 0;
	(*bench).total = 0;
	(*bench).print_bench = 0;
	(*bench).print_ope = 1;
}
