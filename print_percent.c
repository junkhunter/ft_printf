/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 04:14:51 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/27 20:25:10 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <limits.h>
#include <unistd.h>

int print_percent(va_list ap, t_conv conv)
{
	int ret;

	(void)ap;
	(conv.precision == -1) ? conv.precision = 1: 1;
	conv.precision = (conv.precision) ? conv.precision : 1;
	ret = conv.precision;
	if (conv.minus)
		while (conv.precision-- > 0)
			write(1, (conv.precision) ? "0": "%", 1);
	ft_width(ret, conv);
	if (!conv.minus)
		while (conv.precision-- > 0)
			write(1, (conv.precision) ? "0": "%", 1);
	return (ft_bigger(ret, conv.width));
}
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
