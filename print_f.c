/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 00:25:29 by rhunders          #+#    #+#             */
/*   Updated: 2018/12/20 01:35:40 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
/*
void	print_bit(char nb)
{
	char i = 8;

	while (i-- > 0)
		write(1, (nb & (1 << i) ? "1":"0"), 1);
}
*/
int		ft_pow(int nb, int exp)
{
	return ((!exp) ? 1: nb * ft_pow(nb, exp - 1));
}

int		rond_nbr(long double nb, int prec, char **comas)
{
//	long debut;
	long floor;

	floor = (long)nb;
	nb -= (long double)floor;
	*comas = ft_strnew(prec);
	nb *= ft_pow(10, prec + 1);
	floor = (long)nb;
	ft_memset(*comas, '0', prec);
	if (floor % 10 >= 5)
	{
		//debut = nb_len(floor, 10);
	//	printf("%d\n", *floor);
		floor -= floor % 10;
		floor += 10;
	//	printf("%d\n", *floor);
		if (prec + 1 < nb_len(floor, 10))
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

void    ft_putlong(long nb)
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

void	ft_putfloat(char *comas, long floor, t_conv conv, int flag)
{
	ft_putlong(floor);
	if (conv.precision)
		ft_putchar('.');
	if (!flag && conv.precision)
		ft_putstr(comas);
	else if (conv.precision)
		while (conv.precision--)
			ft_putstr(comas);
}

int		print_f(va_list ap, t_conv conv)
{
	long double nb;
	char		*comas;
	int			ret;
	int			flag;

	(conv.precision == -1) ? conv.precision = 6: 0;
	nb = va_arg_f(ap, conv);
	if ((flag = rond_nbr(nb, conv.precision, &comas)))
		nb += 1.0;
	ret = nb_ulen((long)nb, 10) + conv.precision + !!conv.precision;
	if (conv.minus)
	{
		ft_putfloat(comas, (long)nb, conv, flag);
		ft_width(ret, &conv);
	}
	else
	{
		ft_width(ret, &conv);
		ft_putfloat(comas, (long)nb, conv, flag);
	}
	return (ft_bigger(ret, conv.width));
}

/*
#include <limits.h>
#include <float.h>

int main()
{
	long double nbr = 0.9999999999;
	
	t_conv conv;
	conv.precision = 7;
	print_f(nbr, conv);
	return (0);
}*//*
#include <limits.h>
#include <float.h>
int main()
{
float aboat = 32000.0;
double abet = 5.32e-5;
long double dip = 5.32e-5;

printf("(long)aboat -> %ld", (long)aboat);
ft_putfloat(aboat, 6, 0, 0);
ft_putendl("");
ft_putfloat(abet,6,0,0);
ft_putendl("");
ft_putfloat(dip,6,0,0);
ft_putendl("");
return (0);
}*/
/*
#include <stdio.h>

int main(void)
{
float aboat = 32000.0;
double abet = 5.32e-5;
long double dip = 5.32e-5;

printf("%f\n", aboat);
printf("%lf\n", abet);
printf("%Lf\n", dip);

return 0;
}*/
/*int print_f(va_list ap, t_conv conv)
  {
  long double nb;
  int ret;

  (conv.precision == -1) ? conv.precision = 1: 1;
  nb = va_arg_f(ap, conv);
  ret = (ft_bigger(nb_len(nb, 10), conv.precision) + (nb < 0 || conv.space || conv.plus)) * (!!conv.precision);
  if ((nb < 0 || conv.space || conv.plus) && conv.zero)
  {
  if ((conv.plus && nb >= 0) || conv.space)
  write(1, (conv.plus) ? "+" : " ", 1);
  else
  write(1, "-", 1);
  conv.plus = 0;
  conv.space = 0;
  nb = ft_abs(nb);
  }
  if (conv.space > conv.plus && nb >= 0)
  ft_putchar(' ');
  if (conv.minus && ret)
  ft_putnbrl(nb, conv.precision, conv.plus);
  ft_width(ret, conv);
  if (!conv.minus && ret)
  ft_putnbrl(nb, conv.precision, conv.plus);
  return (ft_bigger(ret, conv.width));
  }*/
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
