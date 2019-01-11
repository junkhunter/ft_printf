/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:35:22 by rhunders          #+#    #+#             */
/*   Updated: 2019/01/11 11:28:39 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include <stdlib.h>

int	invalid_conversion(char **arg, t_conv conv)
{
	char *str;

	if (conv.width > 1)
	{
		if (**arg && conv.minus)
			*arg += write(1, *arg, 1);
		str = (char*)malloc(sizeof(char) * conv.width - 1);
		ft_memset(str, ' ', conv.width - 1);
		write(1, str, conv.width - 1);
		free(str);
		if (**arg && !conv.minus)
			*arg += write(1, *arg, 1);
		return (conv.width - !**arg);
	}
	return (0);
}
