/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:13:00 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/08 20:15:39 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_list(t_list *lst, int *nbr)
{
	t_list		*new;
	static int	index = 0;

	if (!nbr || verif_duplicate(lst, *nbr))
	{
		if (nbr)
			free(nbr);
		return (clear_lst(lst));
	}
	if (!lst)
	{
		lst = new_lst(*nbr, 'a', index++, 0);
		if (!lst)
			return (NULL);
		return (lst);
	}
	new = new_lst(*nbr, 'a', index++, 0);
	if (!new)
		return (clear_lst(lst));
	add_back_lst(&lst, new);
	return (lst);
}

void	*clear_lst(t_list *lst)
{
	t_list	*temp;

	lst = first_lst(lst);
	temp = lst;
	while (lst)
	{
		if (lst->last_index_bin)
			free(lst->last_index_bin);
		temp = lst->next;
		free(lst);
		lst = NULL;
		lst = temp;
	}
	return (NULL);
}

t_list	*last_lst(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*first_lst(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

void	add_back_lst(t_list **lst, t_list *new)
{
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->prev = last_lst(*lst);
	last_lst(*lst)->next = new;
}
