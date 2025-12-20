/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:38:34 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/20 13:31:17 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *lst, char order)
{
	if (!lst)
		return (1);
	lst = first_lst(lst);
	if (order == 'a')
	{
		while (lst->next)
		{
			if (lst->nb > lst->next->nb)
				return (0);
			lst = lst->next;
		}
	}
	else
	{
		while (lst->next)
		{
			if (lst->nb < lst->next->nb)
				return (0);
			lst = lst->next;
		}
	}
	return (1);
}

void	sort(t_list *lst_a)
{
	t_list	*array;
	t_list	tmp;
	int		i;
	int		j;

	if (!lst_a)
		return ;
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
}
