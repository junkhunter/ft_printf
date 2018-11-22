/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flagfunctions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:11:31 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/22 22:17:56 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <stdlib.h>

void print_int(int input)
{
	ft_putnbr(input);
}

void print_char(int input)
{
	ft_putchar(input);
}

void print_string(char *input)
{
	ft_putstr(input);
}

void print_unsigned_int(unsigned int input)
{
	if (input > 9) 
		ft_putnbr(input / 10);
	ft_putchar(input % 10 + 48);
}

void print_string_and_unprintable(unsigned char *input)
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
