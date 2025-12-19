/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:14:28 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/19 13:54:18 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_list(t_list *lst)
{
	t_list	*temp;

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
static t_list	*choose_alg(char *algo, t_list *a, t_list *b)
{
	if (a)
		sort(a);
	if (!ft_strncmp(algo, "--simple", 8))
		return (simple(a, b));
	// else if (algo == "--medium")
	// 	return (medium(a, b));
	else if (!ft_strncmp(algo, "--complex", 9))
		return (complex(a, b));
	// else
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


int	parse_arg(t_list **a, t_list **b, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argv[1] && !ft_strncmp(argv[1], "--bench", 7))
		i++;
	while (++i < argc)
	{
		(*a) = init_list(*a, argv[i]);
		if (!(*a))
			return (0);
	}
	// if (argv[1] && !ft_strncmp(argv[1], "--bench", 7))
	// {
	// 	benchmark(*a, argv[2]);
	// 	(*a) = choose_alg(argv[2], *a, *b);
	// }
	// else
	(*a) = choose_alg(argv[1], *a, *b);
	//print_list(*a);
	return (1);
}

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc <= 2)
		return (print_error(a, b));
	if (!parse_arg(&a, &b, argc, argv))
		return (print_error(a, b));
	return (success(a, b));
}
