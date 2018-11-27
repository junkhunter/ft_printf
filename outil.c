/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:26:24 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/27 20:24:50 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <limits.h>
#include <unistd.h>

int     ft_bigger(int val1, int val2)
{
	return ((val1 > val2) ? val1 : val2);
}

void    ft_width(int size_input, t_conv conv)
{
	char c;

	if (!conv.minus && conv.precision == 1)
		c = (!conv.zero) ? ' ' : '0';
	else
		c = ' ';
	while (conv.width-- > size_input)
		ft_putchar(c);
}

long    ft_abs(long nb)
{
	return ((nb < 0) ? -nb : nb);
}

int nb_len(long nb, int base)
{
	int i;
	int signe;

	if (nb == 0 || (i = 0))
		return (1);
	if (nb < 0)
		signe = 1;
	else 
		signe = 0;
	while (nb > 0 || (nb < 0 && signe))
	{
		nb /= base;
		i++;
	}
	return (i);
}

int nb_ulen(unsigned long nb, int base)
{
	int i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}
