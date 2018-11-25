/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:24:12 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/25 23:37:18 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "include/printf.h"
#include "libft.h"

int	print_s(va_list ap, t_conv conv)
{
	char	*str;
	int		ret;

	str = va_arg(ap, char *);
	ret = ft_strlen(str);
	if (conv.minus)
		write(1, str, ft_strlen(str));
	ft_width(ret, conv);
	if (!conv.minus)
		write(1, str, ft_strlen(str));
	return (ft_bigger(ret, conv.width));
}

int	print_c(va_list ap, t_conv conv)
{
	char c;

	c = (char)va_arg(ap, int);
	if (conv.minus)
		write(1, &c, 1);
	ft_width(1,conv);
	if (!conv.minus)
		write(1, &c, 1);
	return (ft_bigger(1, conv.width));
}

int	print_p(va_list ap, t_conv conv)
{
	unsigned long	ptr;
	int				ret;

	ptr = (unsigned long)va_arg(ap, void*);
	ret = 2 + nb_ulen(ptr, 16);
	if (conv.minus)
	{
		write(1, "0x", 2);
		ft_putnbrlu_base(ptr, 0,"0123456789abcdef", 16);
	}
	ft_width(ret,conv);
	if (conv.minus)
	{
		write(1, "0x", 2);
		ft_putnbrlu_base(ptr, 0,"0123456789abcdef", 16);
	}
	return (ft_bigger(conv.width, ret));
}

int	print_b(va_list ap, t_conv conv)
{
	long nbr;

	nbr = (long)va_arg(ap, void*);
	binary_converter(nbr);
	return (64);
}
