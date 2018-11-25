/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 04:14:51 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/25 04:54:55 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <limits.h>
#include <unistd.h>

int     ft_bigger(int val1, int val2)
{
	return ((val1 > val2) ? val1 : val2);
}

void    ft_width_di(int size_input, t_conv conv)
{
	char c;

	c = (!conv.zero) ? ' ' : '0';
	while (conv.width-- > size_input)
		ft_putchar(c);
}

long    ft_abs(long nb)
{
	return ((nb < 0) ? -nb : nb);
}

int nb_len(long nb, int base)
{
	int i;

	i = 0;
	while (ft_abs(nb) > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

void    ft_putnbrl(long nb, int precision)
{
	if (nb < 0)
	{
		if (nb == LONG_MIN)
			ft_putstr("-9223372036854775808");
		nb = nb * -write(1, "-", 1);
	}
	while (precision && precision-- > nb_len(nb, 10))
		ft_putchar('0');
	if (nb > 9)
		ft_putnbrl(nb / 10, 0);
	ft_putchar('0' + nb % 10);
}

int print_di(long nb,/*va_list ap, */t_conv conv)
{
	//long nb;
	int ret;

	//nb = va_arg_di(ap, conv);
	ret = nb_len(nb, 10);
	printf ("ret print_int = %d\n", ret);
	ret = ft_bigger(conv.precision, ret);
	if (conv.space && nb > 0)
		ft_putchar(' ');
	ret += (nb < 0) ? 1 : conv.space;
	if (conv.minus)
	{
		if (!conv.space && ++ret)
			write(1, "+", (nb > 0) ? conv.plus : 0);
		ft_putnbrl(nb, conv.precision);
	}
	printf ("\nret + ... = %d\n",ret + (conv.space | conv.plus) * (nb > 0));
	ft_width_di(ret + (conv.space | conv.plus) * (nb > 0), conv);
	if (!conv.minus)
	{
		if (!conv.space && ++ret)
			write(1, "+", (nb > 0) ? conv.plus : 0);
		ft_putnbrl(nb, conv.precision);
	}
	return (ft_bigger(ret, conv.width));
}

int	main()
{
	t_conv conv;

	conv.zero = 0;
	conv.space = 0;
	conv.minus = 0;
	conv.plus = 1;
	conv.precision = 5;
	conv.width = 10;

	printf("\nret = %d\n",print_di(11, conv));
	return (1);
}
