/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:38:34 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/08 20:10:51 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	if (!lst)
		return (1);
	lst = first_lst(lst);
	while (lst->next)
	{
		if (lst->nb > lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list	*init_array(t_list *lst)
{
	t_list	*array;
	int		index;

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
