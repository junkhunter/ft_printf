/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_flagfunctions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:53:47 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/27 19:33:10 by rhunders         ###   ########.fr       */
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
