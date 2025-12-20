/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:10:26 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/20 18:53:55 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *len, int fd)
{
	int	i;

	if (!s)
	{
		write(fd, "(null)", 6);
		(*len) += 6;
		return ;
	}
	i = 0;
	while (s[i])
	{
		write(fd, &s[i++], 1);
		(*len)++;
	}
}

void	ft_puthexa(unsigned long nbr, char c, int *len, int fd)
{
	char		*hexa;
	static int	is_print = 0;

	if (!nbr && c == 'p')
	{
		write(fd, "(nil)", 5);
		(*len) += 5;
		return ;
	}
	if (c == 'p' && !is_print)
	{
		ft_putstr("0x", len, 1);
		is_print = 1;
	}
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	if (nbr / 16 != 0)
		ft_puthexa((nbr / 16), c, len, fd);
	write(fd, &hexa[nbr % 16], 1);
	is_print = 0;
	(*len)++;
}

void	ft_putnbr(long long nbr, int *len, int fd)
{
	char	buf;

	if (nbr < 0)
	{
		nbr *= -1;
		write(fd, "-", 1);
		(*len)++;
	}
	if (nbr <= 9)
	{
		buf = nbr + '0';
		write(fd, &buf, 1);
		(*len)++;
		return ;
	}
	ft_putnbr((nbr / 10), len, fd);
	buf = (nbr % 10) + '0';
	write(fd, &buf, 1);
	(*len)++;
}

void	filter_format(char c, va_list param, int *len, int fd)
{
	char	x;

	if (c == 'c')
	{
		x = va_arg(param, int);
		write(fd, &x, 1);
		(*len)++;
	}
	else if (c == 's')
		ft_putstr(va_arg(param, char *), len, fd);
	else if (c == 'x' || c == 'X')
		ft_puthexa(va_arg(param, unsigned int), c, len, fd);
	else if (c == 'p')
		ft_puthexa(va_arg(param, unsigned long), c, len, fd);
	else if (c == '%')
	{
		write(fd, "%%", 1);
		(*len)++;
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(param, int), len, fd);
	else if (c == 'u')
		ft_putnbr(va_arg(param, unsigned int), len, fd);
}

int	ft_printf(const char *s, int fd, ...)
{
	va_list	param;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(param, fd);
	while (s[i])
	{
		if (s[i] == '%')
			filter_format(s[i + 1], param, &len, fd);
		else
		{
			write(fd, &s[i], 1);
			len++;
		}
		if (s[i] == '%' && s[i + 1])
			i++;
		i++;
	}
	va_end(param);
	return (len);
}
