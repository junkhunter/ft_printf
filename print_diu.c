/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:38:00 by rhunders          #+#    #+#             */
/*   Updated: 2019/01/14 08:46:29 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_make_precision(int size_input, int precision)
{
	char	*str;
	int		size;

	if ((size = precision - size_input) <= 0)
		return ;
	str = malloc(size + 1);
	str[size] = 0;
	ft_memset(str, '0', size);
	write(1, str, size);
	free(str);
}

void	ft_putnbrl(long nb, int precision, int plus)
{
	if (nb < 0)
	{
		if (nb == LONG_MIN)
		{
			ft_putchar('-');
			ft_make_precision(19, precision);
			return (ft_putstr("9223372036854775808"));
		}
		nb *= -write(1, "-", 1);
	}
	else if (plus)
		write(1, "+", 1);
	if (precision)
		ft_make_precision(nb_len(nb, 10), precision);
	if (nb > 9)
		ft_putnbrl(nb / 10, 0, 0);
	ft_putchar('0' + nb % 10);
}

int		print_di(va_list ap, t_conv conv)
{
	long	nb;
	int		ret;

	(conv.precision == -1) ? conv.precision = 1 : 1;
	if (!(nb = va_arg_di(ap, conv)) && !conv.precision)
		return (dot(conv, conv.plus));
	ret = ft_bigger(nb_len(nb, 10), conv.precision) +
		(nb < 0 || conv.space || conv.plus);
	if ((nb < 0 || conv.space ||
		(conv.plus && conv.precision == 1 && !conv.one)) && conv.zero)
	{
		if ((conv.plus && nb >= 0) || conv.space)
			conv.plus = write(1, (conv.plus) ? "+" : " ", 1) - 1;
		else
			conv.plus = write(1, "-", 1) - 1;
		nb = ft_abs(nb);
	}
	else if (conv.space > conv.plus && nb >= 0)
		ft_putchar(' ');
	if (conv.minus && ret)
		ft_putnbrl(nb, conv.precision, conv.plus);
	ft_width(ret, &conv);
	if (!conv.minus && ret)
		ft_putnbrl(nb, conv.precision, conv.plus);
	return (ft_bigger(ret, conv.width));
}

void	ft_putnbrlu(unsigned long nb, int precision)
{
	if (precision)
		ft_make_precision(nb_ulen(nb, 10), precision);
	if (nb > 9)
		ft_putnbrl(nb / 10, 0, 0);
	ft_putchar('0' + nb % 10);
}

int		print_u(va_list ap, t_conv conv)
{
	unsigned long	nb;
	int				ret;

	(conv.precision == -1) ? conv.precision = 1 : 1;
	if (!(nb = va_arg_oux(ap, conv)) && !conv.precision)
		return (dot(conv, 0));
	ret = ft_bigger(nb_ulen(nb, 10), conv.precision);
	if (conv.minus)
		ft_putnbrlu(nb, conv.precision);
	ft_width(ret, &conv);
	if (!conv.minus)
		ft_putnbrlu(nb, conv.precision);
	return (ft_bigger(ret, conv.width));
}
