/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:25:10 by tchemin           #+#    #+#             */
/*   Updated: 2026/01/28 17:50:27 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	is_only_nbr_and_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
			if (('0' <= s[i + 1] && s[i + 1] <= '9'))
				return (1);
		if (!(('0' <= s[i] && s[i] <= '9') || s[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	has_numbers(char *to_atoi)
{
	int	i;

	i = 0;
	while (to_atoi[i])
	{
		if ('0' <= to_atoi[i] && to_atoi[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_minus(char **s)
{
	int	minus;

	minus = 1;
	if ((*s)[0] == '-' || (*s)[0] == '+')
	{
		if ((*s)[0] == '-')
			minus = -1;
		(*s)++;
	}
	return (minus);
}

int	*ft_atoi(char **s)
{
	int		minus;
	long	rslt;
	int		*ret;

	rslt = 0;
	if (!is_only_nbr_and_space((*s)))
		return (NULL);
	while ((*s)[0] && (*s)[0] == ' ')
		(*s)++;
	minus = check_minus(s);
	while (('0' <= (*s)[0] && (*s)[0] <= '9') && (*s)[0])
		rslt = (rslt * 10) + ((*s)++[0] - 48);
	if (rslt * minus < -2147483648 || rslt * minus > 2147483647)
		return (NULL);
	ret = malloc(sizeof(int));
	if (!ret)
		return (NULL);
	*ret = (int)(rslt * minus);
	if ((*s)[0])
		(*s)++;
	return (ret);
}
