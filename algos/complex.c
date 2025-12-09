/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:33:46 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/09 17:27:13 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_bit_at_index(t_list *lst, int index)
{
	if (!lst)
		return (0);
	lst = first_lst(lst);
	if (lst->last_index_bin[index] == '0')
		return (1);
	while (lst)
	{
		if (lst->last_index_bin[index] == '0')
			return (2);
		lst = lst->next;
	}
	return (0);
}

int	faster_next(t_list *lst, int index)
{
	int	size;
	int	i;

	if (!lst)
		return (0);
	i = 0;
	lst = first_lst(lst);
	size = size_lst(lst);
	while (lst)
	{
		if (lst->last_index_bin[index] == '0' && i <= size / 2)
			return (1);
		else if (lst->last_index_bin[index] == '0' && i > size / 2)
			return (2);
		lst = lst->next;
		i++;
	}
	return (0);
}

t_list	*get_first_faster(t_list *lst, int last_index_pushed)
{
	if (faster_next(lst, last_index_pushed) == 1)
		rotate(&lst);
	else if (faster_next(lst, last_index_pushed) == 2)
		reverse(&lst);
	return (lst);
}

int	need_multiple_rr(t_list *lst, int index)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	lst = first_lst(lst);
	while (lst)
	{
		if (lst->last_index_bin[index] == '0')
			i++;
		if (i > 1)
			return (1);
		lst = lst->next;
	}
	return (0);
}

// static void	print_list(t_list *lst)
// {
// 	t_list	*temp;

// 	temp = lst;
// 	while (temp)
// 	{
// 		ft_printf("%d --> %c / %d / %d", temp->nb, temp->name, temp->origin,
// 			temp->last_index);
// 		ft_printf("/ %s\n", temp->last_index_bin);
// 		temp = temp->next;
// 	}
// }

t_list	*complex(t_list *lst_a, t_list *lst_b)
{
	int	index_bin;

	index_bin = ft_strlen(lst_a->last_index_bin) - 1;
	while (index_bin >= 0)
	{
		while (is_bit_at_index(lst_a, index_bin) == 2 && !is_sorted(lst_a))
			lst_a = get_first_faster(lst_a, index_bin);
		if (lst_a->last_index_bin[index_bin] == '0' && !is_sorted(lst_a))
			push(&lst_a, &lst_b);
		if (is_bit_at_index(lst_a, index_bin) != 0 && !is_sorted(lst_a))
			continue ;
		while (lst_b)
			push(&lst_b, &lst_a);
		index_bin--;
	}
	return (lst_a);
}
