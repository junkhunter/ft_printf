/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 02:03:48 by rhunders          #+#    #+#             */
/*   Updated: 2019/01/14 08:46:10 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <unistd.h>
#include "printf.h"

int		ft_ischar_flag(char arg)
{
	return (arg && ft_strchr("#. -+0123456789hljz", arg));
}

int		ft_precision(char **arg, t_conv *conv)
{
	if (ft_isnum((*arg)[1]))
	{
		conv->precision = ft_atoi((*arg) + 1);
		if (conv->precision == 1)
			conv->one = 1;
		return (nb_len(conv->precision, 10));
	}
	return ((conv->precision = 0));
}

void	s_check_prec(t_conv conv, int *prec, int *ret, char *str)
{
	int str_len;

	str_len = (str) ? ft_strlen(str) : 6;
	if (conv.precision == -1)
	{
		*prec = str_len;
		*ret = str_len;
	}
	else if (conv.precision < str_len)
	{
		*prec = conv.precision;
		*ret = conv.precision;
	}
	else
	{
		*prec = str_len;
		*ret = str_len;
	}
}

int		ft_pow(int nb, int exp)
{
	return ((!exp) ? 1 : nb * ft_pow(nb, exp - 1));
}

void	ft_putlong(long nb)
{
	if (nb < 0)
	{
		if (nb == LONG_MIN)
		{
			ft_putchar('-');
			return (ft_putstr("9223372036854775808"));
		}
		nb = nb * -write(1, "-", 1);
	}
	if (nb > 9)
		ft_putlong(nb / 10);
	ft_putchar('0' + nb % 10);
}
