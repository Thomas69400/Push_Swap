/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufeal <madufeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:05:48 by tchemin           #+#    #+#             */
/*   Updated: 2026/01/28 14:45:52 by madufeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_strategy(char *algo, float disorder)
{
	char	*strategy;

	if (disorder < 0.2)
		strategy = "O(n²)";
	else if (disorder < 0.5)
		strategy = "O(√n)";
	else
		strategy = "O(n log n)";
	if (ft_strcmp(algo, "--simple") == 0)
		ft_printf("[bench] strategy: \tSimple / O(n²)\n", 2);
	else if (ft_strcmp(algo, "--medium") == 0)
		ft_printf("[bench] strategy: \tMedium / O(√n)\n", 2);
	else if (ft_strcmp(algo, "--complex") == 0)
		ft_printf("[bench] strategy: \tComplex / O(n log n)\n", 2);
	else
		ft_printf("[bench] strategy: \tAdaptive / %s\n", 2, strategy);
}

void	benchmark(t_bench *bench, char *algo)
{
	int		dec;

	dec = (int)(((bench->disorder * 100) - (int)(bench->disorder * 100)) * 100);
	ft_printf("[bench] disorder: \t%d.", 2, (int)(bench->disorder * 100));
	if (dec == 0)
		ft_printf("%d%d%%\n", 2, 0, 0);
	else
		ft_printf("%d%%\n", 2, dec);
	print_strategy(algo, bench->disorder);
	ft_printf("[bench] total_ops: \t%d\n", 2, bench->total);
	ft_printf("[bench] sa : %d\tsb : %d\tss : %d\tpa : %d\tpb : %d\n", 2,
		bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("[bench] ra : %d\trb: %d\trr: %d\trra: %d\trrb: %d\trrr:%d\n", 2,
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}
