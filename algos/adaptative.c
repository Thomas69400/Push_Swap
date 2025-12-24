/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:26:42 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/24 18:53:06 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list *adaptative(t_list *lst_a, t_list *lst_b, t_bench *bench)
{
	float disorder;

	disorder = compute_disorder(lst_a) * 100;
	if (disorder < 20)
		return (simple(lst_a, lst_b, bench));
	else if (20 <= disorder && disorder < 50)
		return (medium(lst_a, lst_b, bench));
	else
		return (complex(lst_a, lst_b, bench));
}
