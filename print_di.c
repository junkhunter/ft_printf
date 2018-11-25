/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 04:14:51 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/25 18:02:40 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <limits.h>
#include <unistd.h>

void    ft_putnbrl(long nb, int precision, int plus)
{
	if (nb < 0)
	{
		if (nb == LONG_MIN)
			ft_putstr("-9223372036854775808");
		nb = nb * -write(1, "-", 1);
	}
	else if (plus)
		write(1, "+", 1);
	while (precision && precision-- > nb_len(nb, 10))
		ft_putchar('0');
	if (nb > 9)
		ft_putnbrl(nb / 10, 0, 0);
	ft_putchar('0' + nb % 10);
}

int print_di(va_list ap, t_conv conv)
{
	long nb;
	int ret;

	nb = va_arg_di(ap, conv);
	ret = ft_bigger(nb_len(nb, 10), conv.precision) + (nb < 0 || conv.space || conv.plus);
	if (conv.space > conv.plus && nb >= 0)
		ft_putchar(' ');
	if (conv.minus)
		ft_putnbrl(nb, conv.precision, conv.plus);
	ft_width_di(ret, conv);
	if (!conv.minus)
		ft_putnbrl(nb, conv.precision, conv.plus);
	return (ft_bigger(ret, conv.width));
}

void    ft_putnbrlu(unsigned long nb, int precision)
{
	while (precision && precision-- > nb_len(nb, 10))
		ft_putchar('0');
	if (nb > 9)
		ft_putnbrl(nb / 10, 0, 0);
	ft_putchar('0' + nb % 10);
}

int	print_u(va_list ap, t_conv conv)
{
	unsigned long nb;
	int ret;

	nb = va_arg_oux(ap, conv);
	ret = ft_bigger(nb_ulen(nb, 10), conv.precision);
	if (conv.minus)
		ft_putnbrlu(nb, conv.precision);
	ft_width_di(ret, conv);
	if (!conv.minus)
		ft_putnbrlu(nb, conv.precision);
	return (ft_bigger(ret, conv.width));
}
/*
#include <limits.h>

int	main()
{
	t_conv conv;

	conv.zero = 1;
	conv.space = 1;
	conv.minus = 0;
	conv.plus = 0;
	conv.precision = 4;
	conv.width = 8;

	printf("\nret = %d\n", print_u(100, conv));
	return (1);
}*/
