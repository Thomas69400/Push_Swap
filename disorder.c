/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:13:18 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/26 14:07:38 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_list *lst)
{
	float	mistakes;
	float	pairs;
	t_list	*tmp;

	mistakes = 0;
	pairs = 0;
	if (size_lst(lst) <= 1)
		return (0);
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			pairs++;
			if (lst->nb > tmp->nb)
				mistakes++;
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (mistakes / pairs);
}
