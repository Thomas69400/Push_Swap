/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:38:34 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/09 15:15:22 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
