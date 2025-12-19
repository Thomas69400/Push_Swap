/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:26:55 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/18 17:54:44 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_list(t_list *lst, char *to_atoi)
{
	t_list		*new;
	int			*nbr;
	static int	index = 0;

	while (has_numbers(to_atoi))
	{
		nbr = ft_atoi(&to_atoi);
		if (!nbr || verif_duplicate(lst))
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
