/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:14:28 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/07 19:50:12 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	print_list(t_list *lst)
// {
// 	t_list	*temp;

// 	temp = lst;
// 	while (temp)
// 	{
// 		ft_printf("%d\n", temp->nb);
// 		temp = temp->next;
// 	}
// }

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		*nbr;

	if (argc <= 1)
		return (print_error());
	i = 0;
	a = NULL;
	b = NULL;
	while (++i < argc)
	{
		nbr = ft_atoi(argv[i]);
		a = init_list(a, nbr);
		if (!a)
			return (print_error());
		free(nbr);
	}
	// print_list(a);
	a = sort_lst(a, b);
	// print_list(a);
	clear_lst(a);
	clear_lst(b);
	return (0);
}
