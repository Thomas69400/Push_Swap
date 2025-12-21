/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:26:42 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/21 18:17:21 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*adaptative(t_list *lst_a, t_list *lst_b, t_bench *bench)
{
	float	disorder;
	int		size;

	disorder = compute_disorder(lst_a) * 100;
	size = size_lst(lst_a);
	if (disorder < 20 || size <= 5)
		return (simple(lst_a, lst_b, bench, size));
	// else if (20 <= disorder && disorder < 50)
	// 	return (medium(lst_a, lst_b, bench));
	else
		return (complex(lst_a, lst_b, bench));
}
