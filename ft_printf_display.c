/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 00:00:22 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/22 22:35:23 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "include/printf.h"

void ft_put_octal(int nb)
{
	int zero_number;
	int index;

	index = 0;
	zero_number = 2;
	if (nb > 7)
		zero_number = (nb > 77) ? 0 : 1;
	ft_putchar(92);
	while (index++ < zero_number)
		ft_putchar('0');
	ft_putnbr(nb);
}
