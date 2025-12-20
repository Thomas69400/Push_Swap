/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:25:10 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/19 13:56:00 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static int is_only_nbr_and_space(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!(('0' <= s[i] && s[i] <= '9') || s[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int has_numbers(char *to_atoi)
{
	int i;

	i = 0;
	while (to_atoi[i])
	{
		if ('0' <= to_atoi[i] && to_atoi[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int *ft_atoi(char **s)
{
	int minus;
	long rslt;
	int *ret;

	minus = 1;
	rslt = 0;
	if ((*s)[0] == '-' || (*s)[0] == '+')
	{
		if ((*s)[0] == '-')
			minus = -1;
		(*s)++;
	}
	if (!is_only_nbr_and_space((*s)))
		return (NULL);
	while ((*s)[0] && (*s)[0] == ' ')
		(*s)++;
	while (('0' <= (*s)[0] && (*s)[0] <= '9') && (*s)[0])
		rslt = (rslt * 10) + ((*s)++[0] - 48);
	if (rslt < -2147483648 || rslt > 2147483647)
		return (NULL);
	ret = malloc(sizeof(int));
	if (!ret)
		return (NULL);
	*ret = (int)(rslt * minus);
	return (ret);
}
