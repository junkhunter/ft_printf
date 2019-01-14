/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 04:14:51 by rhunders          #+#    #+#             */
/*   Updated: 2019/01/14 08:46:55 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>
#include <unistd.h>

int	print_percent(va_list ap, t_conv conv)
{
	int ret;

	(void)ap;
	(conv.precision == -1) ? conv.precision = 1 : 1;
	ret = 1;
	if (conv.minus)
		write(1, "%", 1);
	if (conv.width)
		ft_width(ret, &conv);
	if (!conv.minus)
		write(1, "%", 1);
	return (ft_bigger(ret, conv.width));
}
