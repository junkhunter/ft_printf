/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:24:12 by rhunders          #+#    #+#             */
/*   Updated: 2018/12/19 02:08:13 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "include/printf.h"
#include "libft.h"

int		ft_smaller(int val1, int val2)
{
	return ((val1 < val2) ? val1 : val2);
}

int	print_s(va_list ap, t_conv conv)
{
	char	*str;
	int		ret;
	int		str_len;
	int		prec;

	(conv.precision == -1) ? conv.precision = 1: 1;
	str = va_arg(ap, char *);
	str_len = (str) ? ft_strlen(str): 0;
	if (conv.precision == 1)
	{
		prec = str_len;
		ret = (str) ? str_len: 6;
	}
	else if (conv.precision < str_len)
	{
		prec = conv.precision;
		ret = (str) ? conv.precision: 6;
	}
	else
	{
		prec = str_len;
		ret = (str) ? str_len: 6;
	}
	if (conv.minus) // put si ya un moins
		(str) ? write(1, str, prec) : ft_putstr("(null)");
	ft_width(ret, &conv);
	if (!conv.minus) // put si yavais pas de moins
		(str) ? write(1, str, prec) : ft_putstr("(null)");
	return (ft_bigger(ret, conv.width));
}

#include <stdio.h>
#include <stdlib.h>

int	print_c(va_list ap, t_conv conv)
{
	char c;

	c = (char)va_arg(ap, int);
	(conv.precision == -1) ? conv.precision = 1: 1;
	if (conv.minus)
	{
		write(1, &c, 1);
		ft_width(1, &conv);
	}
	else
	{
		ft_width(1, &conv);
		write(1, &c, 1);
	}
	return (ft_bigger(1, conv.width));
}

int	print_p(va_list ap, t_conv conv)
{
	unsigned long	ptr;
	int				ret;

	(conv.precision == -1) ? conv.precision = 1: 1;
	if (!(ptr = (unsigned long)va_arg(ap, void*)) && !conv.precision)
	{
		if (conv.minus)
			return (write(1, "0x", 2) + dot(conv, 2));
		return (dot(conv, 2) + write(1, "0x", 2));
	}
	ret = 2 + ft_bigger(nb_ulen(ptr, 16), conv.precision);
	if (conv.minus)
	{
		write(1, "0x", 2);
		ft_putnbrlu_base(ptr, conv.precision,"0123456789abcdef", 16);
		ft_width(ret, &conv);
	}
	else
	{
		ft_width(ret, &conv);
		write(1, "0x", 2);
		ft_putnbrlu_base(ptr, conv.precision,"0123456789abcdef", 16);
	}
	return (ft_bigger(conv.width, ret));
}

int	print_b(va_list ap, t_conv conv)
{
	long nbr;

	nbr = (long)va_arg(ap, void*);
	if (conv.minus)
		binary_converter(nbr);
	ft_width(72, &conv);
	if (!conv.minus)
		binary_converter(nbr);
	return (ft_bigger(72, conv.width));
}
