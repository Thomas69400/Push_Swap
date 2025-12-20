/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:05:48 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/20 19:34:38 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*benchmark(t_list **a, t_list **b, char *algo)
{
	float	disorder;
	t_bench	bench;

	init_bench(&bench);
	disorder = compute_disorder(*a);
	(*a) = choose_alg(algo, *a, *b, &bench);
	ft_printf("[bench] disorder: \t%d.%d%%\n", 2, (int)(disorder * 100),
		(int)(((disorder * 100) - (int)(disorder * 100)) * 100));
	if (!ft_strncmp(algo, "--simple", 8))
		ft_printf("[bench] strategy: \tSimple\n", 2);
	else if (!ft_strncmp(algo, "--medium", 8))
		ft_printf("[bench] strategy: \tMedium\n", 2);
	else if (!ft_strncmp(algo, "--complex", 9))
		ft_printf("[bench] strategy: \tComplex\n", 2);
	else
		ft_printf("[bench] strategy: \tAdaptive\n", 2);
	ft_printf("[bench] total_ops: \t%d\n", 2, bench.total);
	ft_printf("[bench] sa : %d\tsb : %d\tss : %d\tpa : %d\tpb : %d\n", 2,
		bench.sa, bench.sb, bench.ss, bench.pa, bench.pb);
	ft_printf("[bench] ra : %d\trb: %d\trr: %d\trra: %d\trrb: %d\trrr:%d\n", 2,
		bench.ra, bench.rb, bench.rr, bench.rra, bench.rrb, bench.rrr);
	return (*a);
}
