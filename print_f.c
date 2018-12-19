/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 04:14:51 by rhunders          #+#    #+#             */
/*   Updated: 2018/12/14 00:17:52 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <limits.h>
#include <unistd.h>

int		float_len(long double nb)
{
	int i;
	long long floor;
	long double nbr;

	nbr = nb;
	floor = (long long)nb;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	nbr -= floor; 
	while (nbr - (long long)nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	print_bit(char nb)
{
	char i = 8;

	while (i-- > 0)
		write(1, (nb & (1 << i) ? "1":"0"), 1);
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
	else if (plus)
		write(1, "+", 1);
	if (nb > 9)
		ft_putnbrl(nb / 10, 0, 0);
	ft_putchar('0' + nb % 10);
	/*while (i-- > 1)
	  {
	  print_bit(((char *)nb)[i]);
	  if (i != 1)
	  write(1, " ",1);
	  }*/
	/*short exponent;
	  long fraction;
	  int signe;

	  exponent = ((short*)nb)[1];
	  if (exponent < 0)
	  signe = -1;
	  exponent = ft_abs((long)exponent);
	  print_bit(exponent);
	//exponent = 0b0111111111110000 & exponent;
	fraction = ((long*)nb)[1];
	write(1, " ",1);
	print_bit(fraction);*/
}

#include <limits.h>
#include <float.h>

int main()
{
	long double nbr = 0.5;

	ft_putfloat((void*)&nbr,0,0);
	return (0);
}/*
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
