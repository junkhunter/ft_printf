/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 04:14:51 by rhunders          #+#    #+#             */
/*   Updated: 2018/12/20 02:54:35 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <limits.h>
#include <unistd.h>

void	ft_putnbrlu_base(unsigned long nb, int precision, char *digit, int base)
{
	int len;

	if (precision)
		len = nb_len(nb, base);
	while (precision && (precision-- > len))
		ft_putchar('0');
	if (nb > (unsigned long)base - 1)
		ft_putnbrlu_base(nb / base, 0, digit, base);
	ft_putchar(digit[nb % base]);
}

int		print_x_low(va_list ap, t_conv conv)
{
	unsigned long	nb;
	int				ret;

	(conv.precision == -1) ? conv.precision = 1 : 1;
	if (!(nb = va_arg_oux(ap, conv)) && conv.precision == 0)
		return (dot(conv, 0));
	ret = ft_bigger(nb_ulen(nb, 16), conv.precision) + 2 * conv.sharp * !!nb;
	if (conv.sharp && nb && conv.zero)
		write(1, "0x", 2);
	if (conv.minus)
	{
		if (conv.sharp && nb && !conv.zero)
			write(1, "0x", 2);
		ft_putnbrlu_base(nb, conv.precision, "0123456789abcdef", 16);
	}
	ft_width(ret, &conv);
	if (!conv.minus)
	{
		if (conv.sharp && nb && !conv.zero)
			write(1, "0x", 2);
		ft_putnbrlu_base(nb, conv.precision, "0123456789abcdef", 16);
	}
	return (ft_bigger(ret, conv.width));
}

int		print_x_up(va_list ap, t_conv conv)
{
	unsigned long	nb;
	int				ret;

	(conv.precision == -1) ? conv.precision = 1 : 1;
	if (!(nb = va_arg_oux(ap, conv)) && conv.precision == 0)
		return (dot(conv, 0));
	ret = ft_bigger(nb_ulen(nb, 16), conv.precision) + 2 * conv.sharp * !!nb;
	if (conv.sharp && nb && conv.zero)
		write(1, "0X", 2);
	if (conv.minus)
	{
		if (conv.sharp && nb && !conv.zero)
			write(1, "0X", 2);
		ft_putnbrlu_base(nb, conv.precision, "0123456789ABCDEF", 16);
	}
	ft_width(ret, &conv);
	if (!conv.minus)
	{
		if (conv.sharp && nb && !conv.zero)
			write(1, "0X", 2);
		ft_putnbrlu_base(nb, conv.precision, "0123456789ABCDEF", 16);
	}
	return (ft_bigger(ret, conv.width));
}

int		print_o(va_list ap, t_conv conv)
{
	unsigned long	nb;
	int				ret;

	(conv.precision == -1) ? conv.precision = 1 : 1;
	if (!(nb = va_arg_oux(ap, conv)) && conv.precision == 0)
		return (dot(conv, 0));
	ret = ft_bigger(nb_ulen(nb, 8), conv.precision) + conv.sharp * !!nb;
	if (conv.sharp && nb && conv.zero)
		write(1, "0", 1);
	if (conv.minus)
	{
		if (conv.sharp && nb && !conv.zero)
			write(1, "0", 1);
		ft_putnbrlu_base(nb, conv.precision, "012345678", 8);
	}
	if (conv.width > ret)
		ft_width(ret, &conv);
	if (!conv.minus)
	{
		if (conv.sharp && nb && !conv.zero)
			write(1, "0", 1);
		ft_putnbrlu_base(nb, conv.precision, "012345678", 8);
	}
	return (ft_bigger(ret, conv.width));
}
