/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:13:00 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/09 13:49:32 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*clear_lst(t_list *lst)
{
	t_list	*temp;

	lst = first_lst(lst);
	while (lst)
	{
		temp = lst->next;
		lst = delone_lst(lst);
		lst = temp;
	}
	return (NULL);
}

void	*delone_lst(t_list *lst)
{
	if (!lst)
		return (NULL);
	if (lst->last_index_bin)
		free(lst->last_index_bin);
	free(lst);
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
