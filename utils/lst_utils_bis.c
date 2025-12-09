/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:39:35 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/09 17:14:58 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

t_list	*new_lst(int nbr, char name, int origin, int last_index)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->origin = origin;
	new->last_index = last_index;
	new->name = name;
	new->nb = nbr;
	if (last_index != -1)
		new->last_index_bin = convert_final_index_to_binary(last_index, NULL);
	else
		new->last_index_bin = NULL;
	return (new);
}

int	size_lst(t_list *lst)
{
	int		i;
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = first_lst(lst);
	i = 1;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	place_final_index(t_list *array_sorted, t_list *lst)
{
	int	i;
	int	j;

	if (!lst && !array_sorted)
		return ;
	i = 0;
	while (i++ < size_lst(lst))
	{
		j = 0;
		while (j < size_lst(lst))
		{
			if (array_sorted[j].nb == lst->nb)
			{
				lst->last_index = j;
				lst->last_index_bin = convert_final_index_to_binary(j,
						lst);
				lst = lst->next;
				break ;
			}
			j++;
		}
	}
	if (array_sorted)
		free(array_sorted);
}

char	*convert_final_index_to_binary(int nbr, t_list *lst)
{
	char		*bin;
	char		*s;
	int			size;
	static int	highest_index = 0;

	if (nbr == -1)
		return (NULL);
	if (lst)
		highest_index = size_lst(lst);
	bin = "01";
	size = get_size_of_bin(highest_index);
	s = ft_calloc(size + 1, 1);
	s[size--] = '\0';
	if (!s)
		return (NULL);
	while (nbr / 2 != 0)
	{
		s[size--] = bin[nbr % 2];
		nbr = nbr / 2;
	}
	s[size--] = bin[nbr % 2];
	return (s);
}
