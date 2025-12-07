/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:29:20 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/07 15:14:19 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	ft_printf("Error\n");
	return (1);
}

int	verif_duplicate(t_list *lst, int nbr)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->nb == nbr)
			return (1);
		lst = lst->next;
	}
	return (0);
}
