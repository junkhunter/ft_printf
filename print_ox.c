/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 04:14:51 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/25 23:36:11 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <limits.h>
#include <unistd.h>

void    ft_putnbrlu_base(unsigned long nb, int precision, char *digit, int base)
{
	while (precision && precision-- > nb_len(nb, 16))
		ft_putchar('0');
	if (nb > base - 1)
		ft_putnbrlu_base(nb / base, 0, digit, base);
	ft_putchar(digit[nb % base]);
}

int	print_x_low(va_list ap, t_conv conv)
{
	unsigned long nb;
	int ret;

	nb = va_arg_oux(ap, conv);
	ret = ft_bigger(nb_ulen(nb, 16), conv.precision) + 2 * conv.sharp;
	if (conv.minus)
	{
		if (conv.sharp)
			write(1, "0x", 2);
		ft_putnbrlu_base(nb, conv.precision, "0123456789abcdef", 16);
	}
	ft_width(ret, conv);
	if (!conv.minus)
	{
		if (conv.sharp)
			write(1, "0x", 2);
		ft_putnbrlu_base(nb, conv.precision, "0123456789abcdef", 16);
	}
	return (ft_bigger(ret, conv.width));
}

int	print_x_up(va_list ap, t_conv conv)
{
	unsigned long nb;
	int ret;

	nb = va_arg_oux(ap, conv);
	ret = ft_bigger(nb_ulen(nb, 16), conv.precision) + 2 * conv.sharp;
	if (conv.minus)
	{
		if (conv.sharp)
			write(1, "0X", 2);
		ft_putnbrlu_base(nb, conv.precision, "0123456789ABCDEF", 16);
	}
	ft_width(ret, conv);
	if (!conv.minus)
	{
		if (conv.sharp)
			write(1, "0X", 2);
		ft_putnbrlu_base(nb, conv.precision, "0123456789ABCDEF", 16);
	}
	return (ft_bigger(ret, conv.width));
}

int	print_o(va_list ap, t_conv conv)
{
	unsigned long nb;
	int ret;

	nb = va_arg_oux(ap, conv);
	ret = ft_bigger(nb_ulen(nb, 8), conv.precision) + conv.sharp;
	if (conv.minus)
	{
		if (conv.sharp)
			write(1, "0", 1);
		ft_putnbrlu_base(nb, conv.precision,"012345678", 8);
	}
	ft_width(ret, conv);
	if (!conv.minus)
	{
		if (conv.sharp)
			write(1, "0", 1);
		ft_putnbrlu_base(nb, conv.precision,"012345678", 8);
	}
	return (ft_bigger(ret, conv.width));
}
/*#include <limits.h>

int	main()
{
	t_conv conv;

	conv.zero = 1;
	conv.space = 0;
	conv.minus = 0;
	conv.plus = 0;
	conv.precision = 0;
	conv.width = 5;
	conv.sharp = 1;

	//printf("\nret_x_up = %d\n", print_x_up(170, conv));
	printf("\nret_o = %d\n", print_o(87, conv));
	return (1);
}*/
