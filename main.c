/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:14:28 by tchemin           #+#    #+#             */
/*   Updated: 2026/01/20 11:15:33 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*choose_alg(char *algo, t_list *a, t_list *b, t_bench *bench)
{
	float disorder;

	if (a)
		sort(a);
	disorder = compute_disorder(a);
	if (!ft_strncmp(algo, "--simple", 8))
		a = (simple(a, b, bench, size_lst(a)));
	else if (!ft_strncmp(algo, "--medium", 8))
		a = (medium(a, b, bench));
	else if (!ft_strncmp(algo, "--complex", 9))
		a = (complex(a, b, bench));
	else
		a = (adaptative(a, b, bench));
	if (bench && bench->print_bench)
		benchmark(algo, bench, disorder);
	return (a);
}

static int	success(t_list *a, t_list *b)
{
	if (a)
		clear_lst(a);
	if (b)
		clear_lst(b);
	return (0);
}

int	parse_arg(t_list **a, t_list **b, int argc, char **argv)
{
	int		i;
	t_bench	bench;

	i = 1;
	init_bench(&bench);
	if (argv[i] && !ft_strncmp(argv[i], "--bench", 7))
		i++;
	if (argv[i] && (!ft_strncmp(argv[i], "--simple", 8)
			|| !ft_strncmp(argv[i], "--complex", 9)
			|| !ft_strncmp(argv[i], "--adaptive", 10)
			|| !ft_strncmp(argv[i], "--medium", 8)))
		i++;
	while (i < argc)
		if (!((*a) = init_list(*a, argv[i++])))
			return (0);
	if (argv[1] && !ft_strncmp(argv[1], "--bench", 7))
		bench.print_bench = 1;
	(*a) = choose_alg(argv[i - 1], *a, *b, &bench);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (1);
	if (!parse_arg(&a, &b, argc, argv))
		return (print_error(a, b));
	return (success(a, b));
}
