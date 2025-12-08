/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:13:00 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/08 14:28:05 by tchemin          ###   ########.fr       */
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
		lst = new_lst(*nbr);
		if (!lst)
			return (NULL);
		return (lst);
	}
	new = new_lst(*nbr);
	if (!new)
		return (clear_lst(lst));
	new->origin = index++;
	add_back_lst(&lst, new);
	return (lst);
}

void	*clear_lst(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (lst)
	{
		temp = lst->next;
		free(lst);
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

void	add_front_lst(t_list **lst, t_list *new)
{
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = first_lst(*lst);
	new->prev = NULL;
	first_lst(*lst)->prev = new;
	*lst = new;
}

t_list	*new_lst(int nbr)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->name = 'a';
	new->nb = nbr;
	return (new);
}
