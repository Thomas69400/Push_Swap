/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:14:28 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/10 14:28:52 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list *choose_alg(char *algo, t_list *a, t_list *b)
{
	if (a)
		sort(a);
	if (!ft_strncmp(algo, "--simple", 8))
		return (simple(a, b));
	// else if (algo == "--medium")
	// 	return (medium(a, b));
	else if (!ft_strncmp(algo, "--complex", 9))
		return (complex(a, b));
	// else if (algo == "--adaptive")
	// 	return (adaptive(a, b));
	print_error(a, b);
	return (NULL);
}

static int success(t_list *a, t_list *b)
{
	if (a)
		clear_lst(a);
	if (b)
		clear_lst(b);
	return (0);
}

static void print_list(t_list *lst)
{
	t_list *temp;

	temp = lst;
	ft_printf("\n======= MAIN ========\n");
	while (temp)
	{
		ft_printf("%d --> %c / %d / %d \n", temp->nb, temp->name, temp->origin,
				  temp->last_index);
		temp = temp->next;
	}
	ft_printf("sortie print\n");
}

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	int i;
	int *nbr;

	a = NULL;
	b = NULL;
	if (argc <= 2)
		return (print_error(a, b));
	i = 1;
	while (++i < argc)
	{
		nbr = ft_atoi(argv[i]);
		a = init_list(a, nbr);
		if (!a)
			return (print_error(a, b));
		free(nbr);
	}
	a = choose_alg(argv[1], a, b);
	print_list(a);
	if (!a)
		return (1);
	return (success(a, b));
}
