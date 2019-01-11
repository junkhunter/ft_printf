/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:26:24 by rhunders          #+#    #+#             */
/*   Updated: 2018/12/20 03:24:19 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_bigger(int val1, int val2)
{
	return ((val1 > val2) ? val1 : val2);
}

void	ft_width(int size_input, t_conv *conv)
{
	char	c;
	int		c_width;
	char	*str;

	c_width = conv->width - size_input;
	if (c_width > 0)
		str = malloc(sizeof(char) * c_width + 1);
	else
		return ;
	str[c_width] = 0;
	if (!conv->minus &&
		((conv->precision == 1 && !conv->one) || conv->index == F))
		c = (!conv->zero) ? ' ' : '0';
	else
		c = ' ';
	ft_memset(str, c, c_width);
	write(1, str, c_width);
	free(str);
}

long	ft_abs(long nb)
{
	return ((nb < 0) ? -nb : nb);
}

int		nb_len(long nb, int base)
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

int		nb_ulen(unsigned long nb, int base)
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
