/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flagfunctions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:11:31 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/27 19:34:53 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <stdlib.h>

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
