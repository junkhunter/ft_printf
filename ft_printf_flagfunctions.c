/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flagfunctions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:11:31 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/25 02:20:18 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <stdlib.h>

int	ft_option_di(long nb, t_conv conv)
{
	int ret;
	int prec;
	int width;

	ret = 0;
	if (nb_len(nb, 10) < conv.precision)
	{
		prec = conv.precision;
		conv.precision = 0;
		ft_option_di(nb, conv);
	}
}

int print_di(va_list ap, t_conv conv)
{
	long nb;
	int ret;

	nb = va_arg_di(ap, conv);
	ret = 0;
	if (nb_len(nb, 10) < conv.precision)
	{
		
	}
	return ();
}

int print_c(va_list ap, t_conv conv)
{
	
}

int print_s(va_list ap, t_conv conv)
{

}

int print_u(va_list ap, t_conv conv)
{
	if (input > 9) 
		ft_putnbr(input / 10);
	ft_putchar(input % 10 + 48);
}

int print_s_unprintable(va_list ap, t_conv conv)
{
	int index;
	int octalNb;
	int	octalIndex;

	index = 0;
	octalNb = 0;
	octalIndex = -1;
	while (input[index] != '\0') 
	{
		if (input[index] < 32 || input[index] >= 127) 
		{
			while (++octalIndex < input[index])
			{
				octalNb++;
				if ((octalNb % 10) > 7)
					octalNb = (octalNb - 8) + 10;
				if ((octalNb % 100) > 77)
					octalNb = (octalNb - 80) + 100;
			}
			ft_put_octal(octalNb);
		}
		else
			ft_putchar(input[index]);
		index++;
	}
}
