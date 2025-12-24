/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:05:48 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/24 18:33:56 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_strategy(char *algo, float disorder)
{
	char *strategy;

	if (disorder < 0.2)
		strategy = "O(n²)";
	else if (disorder < 0.5)
		strategy = "O(√n)";
	else
		strategy = "O(n log n)";
	if (!ft_strncmp(algo, "--simple", 8))
		ft_printf("[bench] strategy: \tSimple / O(n²)\n", 2);
	else if (!ft_strncmp(algo, "--medium", 8))
		ft_printf("[bench] strategy: \tMedium / O(√n)\n", 2);
	else if (!ft_strncmp(algo, "--complex", 9))
		ft_printf("[bench] strategy: \tComplex / O(n log n)\n", 2);
	else
		ft_printf("[bench] strategy: \tAdaptive / %s\n", 2, strategy);
}

t_list *benchmark(t_list **a, t_list **b, char *algo)
{
	float disorder;
	t_bench bench;

	init_bench(&bench);
	disorder = compute_disorder(*a);
	(*a) = choose_alg(algo, *a, *b, &bench);
	ft_printf("[bench] disorder: \t%d.%d%%\n", 2, (int)(disorder * 100),
			  (int)(((disorder * 100) - (int)(disorder * 100)) * 100));
	print_strategy(algo, disorder);
	ft_printf("[bench] total_ops: \t%d\n", 2, bench.total);
	ft_printf("[bench] sa : %d\tsb : %d\tss : %d\tpa : %d\tpb : %d\n", 2,
			  bench.sa, bench.sb, bench.ss, bench.pa, bench.pb);
	ft_printf("[bench] ra : %d\trb: %d\trr: %d\trra: %d\trrb: %d\trrr:%d\n", 2,
			  bench.ra, bench.rb, bench.rr, bench.rra, bench.rrb, bench.rrr);
	return (*a);
}
