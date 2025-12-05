/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:10:26 by tchemin           #+#    #+#             */
/*   Updated: 2025/11/24 15:19:34 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *len)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i++], 1);
		(*len)++;
	}
}

void	ft_puthexa(unsigned long nbr, char c, int *len)
{
	char		*hexa;
	static int	is_print = 0;

	if (!nbr && c == 'p')
	{
		write(1, "(nil)", 5);
		(*len) += 5;
		return ;
	}
	if (c == 'p' && !is_print)
	{
		ft_putstr("0x", len);
		is_print = 1;
	}
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	if (nbr / 16 != 0)
		ft_puthexa((nbr / 16), c, len);
	write(1, &hexa[nbr % 16], 1);
	is_print = 0;
	(*len)++;
}

void	ft_putnbr(long long nbr, int *len)
{
	char	buf;

	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		(*len)++;
	}
	if (nbr <= 9)
	{
		buf = nbr + '0';
		write(1, &buf, 1);
		(*len)++;
		return ;
	}
	ft_putnbr((nbr / 10), len);
	buf = (nbr % 10) + '0';
	write(1, &buf, 1);
	(*len)++;
}

void	filter_format(char c, va_list param, int *len)
{
	char	x;

	if (c == 'c')
	{
		x = va_arg(param, int);
		write(1, &x, 1);
		(*len)++;
	}
	else if (c == 's')
		ft_putstr(va_arg(param, char *), len);
	else if (c == 'x' || c == 'X')
		ft_puthexa(va_arg(param, unsigned int), c, len);
	else if (c == 'p')
		ft_puthexa(va_arg(param, unsigned long), c, len);
	else if (c == '%')
	{
		write(1, "%%", 1);
		(*len)++;
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(param, int), len);
	else if (c == 'u')
		ft_putnbr(va_arg(param, unsigned int), len);
}

int	ft_printf(const char *s, ...)
{
	va_list	param;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(param, s);
	while (s[i])
	{
		if (s[i] == '%')
			filter_format(s[i + 1], param, &len);
		else
		{
			write(1, &s[i], 1);
			len++;
		}
		if (s[i] == '%' && s[i + 1])
			i++;
		i++;
	}
	va_end(param);
	return (len);
}
