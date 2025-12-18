/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:05:48 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/18 17:19:30 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* TODO
 */
void	benchmark(t_list *a, char *algo)
{
	ft_printf("[bench] disorder: %f%%\n", compute_disorder(a));
	if (!ft_strncmp(algo, "--simple", 8))
		ft_printf("[bench] strategy: Simple");
	else if (algo == "--medium")
		ft_printf("[bench] strategy:Medium");
	else if (!ft_strncmp(algo, "--complex", 9))
		ft_printf("[bench] strategy: Complex");
	else
		ft_printf("[bench] strategy: Adaptative");
	ft_printf("[bench] total_ops: %d\n", ops);
	ft_printf("[bench] sa: %d\t sb : %d \t ss : %d \t pa : %d \t pb : %d\n");
	ft_printf("[bench] ra: %d \t rb: %d \t rr: %d \t rra: %d \t rrb: %d \t rrr:
		%d \t \n");
}
