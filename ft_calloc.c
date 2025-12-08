/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:12:10 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/08 22:12:20 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void *ret;

    if (size == 0 || nmemb == 0)
        return (malloc(0));
    ret = malloc(size * nmemb);
    if (!ret)
        return (NULL);
    ft_bzero(ret, nmemb * size);
    return (ret);
}
