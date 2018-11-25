/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_flagfunctions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:53:47 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/25 23:39:17 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdlib.h>
#include <limits.h>

void	binary_converter(int input)
{
	int i;

	i = 64;
	while (i-- > 0)
	{
		if (!((i + 1) % 8) && i < 63)
			ft_putchar(' ');
		ft_putchar((input & (1 << i)) ? '1' : '0');
	}
}
/*
void	u_octal_converter(unsigned long input)
{
	if (input >= 8)
		octal_converter(input / 8);
	ft_putchar('0' + input % 8);
}

void	lower_hexa_converter(unsigned long input)
{
	char			*result;
	unsigned long	number;
	char			*strbase;
	int				counter;

	strbase = ft_strdup("0123456789abcdef");
	number = input;
	counter = 0;
	while (number >= 16)
	{
		number /= 16;
		counter++;
	}
	result = ft_strnew(counter);
	while (counter >= 0)
	{
		result[counter--] = strbase[input % 16];
		input /= 16;
	}
	ft_putstr(result);
	free(result);
	free(strbase);
}

void	upper_hexa_converter(unsigned long input)
{
	char			*result;
	char			*strbase;
	unsigned long	number;
	int				counter;

	strbase = ft_strdup("0123456789ABCDEF");
	number = input;
	counter = 0;
	while (number >= 16)
	{
		number /= 16;
		counter++;
	}
	result = ft_strnew(counter);
	while (counter >= 0)
	{
		result[counter--] = strbase[input % 16];
		input /= 16;
	}
	ft_putstr(result);
	free(result);
	free(strbase);
}*/
