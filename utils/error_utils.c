/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:29:20 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/09 17:48:58 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	print_error(t_list *a, t_list *b)
{
	clear_lst(a);
	clear_lst(b);
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
		{
			ft_printf("%d\n", nbr);
			return (1);
		}lst = lst->next;
	}
	return (0);
}
