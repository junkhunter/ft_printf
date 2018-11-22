/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_flagfunctions_long.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:13:35 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/22 22:34:59 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include "printf.h"

void    l_binary_converter(long input)
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

void octal_converter(long input)
{
	if (input < 0)
	{
		if (input == LONG_MIN)
			ft_putstr("1000000000000000000000");
		else
			octal_converter(-input);
		return ;
	}
	if (input >= 8)
		octal_converter(input / 8);
	ft_putchar('0' + input % 8);
}
