/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:29:20 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/20 18:51:18 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	print_error(t_list *a, t_list *b)
{
	clear_lst(a);
	clear_lst(b);
	ft_printf("Error\n", 2);
	return (1);
}

int	verif_duplicate(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (0);
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->nb == tmp->nb)
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}
