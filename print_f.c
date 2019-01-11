/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 00:25:29 by rhunders          #+#    #+#             */
/*   Updated: 2018/12/20 02:12:13 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <limits.h>
#include <unistd.h>

long double	ft_fabs(long double nb)
{
	return ((nb < 0) ? -nb : nb);
}

int			rond_nbr(long double nb, int prec, char **comas)
{
	long debut;
	long floor;

	floor = (long)nb;
	nb -= (long double)floor;
	*comas = ft_strnew(prec);
	nb *= ft_pow(10, prec + 1);
	floor = (long)nb;
	ft_memset(*comas, '0', prec);
	if (floor % 10 > 5)
	{
		debut = nb_len(floor, 10);
		floor -= floor % 10;
		floor += 10;
		if (debut < nb_len(floor, 10))
			return (1);
	}
	floor /= 10;
	while (floor)
	{
		comas[0][--prec] = floor % 10 + '0';
		floor /= 10;
	}
	return (0);
}

void		ft_putfloat(char *comas, long floor, t_conv conv, int flag)
{
	ft_putlong(ft_fabs(floor));
	if (conv.precision)
		ft_putchar('.');
	if (!flag && conv.precision)
		ft_putstr(comas);
	else if (conv.precision)
		while (conv.precision--)
			ft_putstr(comas);
}

void		signe_f(t_conv conv)
{
	if (conv.plus && !conv.neg_f)
		ft_putchar('+');
	else if (conv.space && !conv.neg_f)
		ft_putchar(' ');
	else if (conv.neg_f)
		write(1, "-", 1);
}

int			print_f(va_list ap, t_conv conv)
{
	long double nb;
	char		*comas;
	int			ret;
	int			flag;

	(conv.precision == -1) ? conv.precision = 6 : 0;
	nb = va_arg_f(ap, &conv);
	if ((flag = rond_nbr(ft_fabs(nb), conv.precision, &comas)))
		nb += 1.0;
	ret = nb_len((long)nb, 10) + conv.precision + 1 * !!conv.precision +
		(nb < 0 || conv.space || conv.plus);
	if (conv.minus)
	{
		signe_f(conv);
		ft_putfloat(comas, (long)nb, conv, flag);
		ft_width(ret, &conv);
	}
	else
	{
		signe_f(conv);
		ft_width(ret, &conv);
		ft_putfloat(comas, (long)nb, conv, flag);
	}
	return (ft_bigger(ret, conv.width));
}
