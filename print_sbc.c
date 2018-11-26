/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:24:12 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/26 01:24:20 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "include/printf.h"
#include "libft.h"

int		ft_smaller(int val1, int val2)
{
	return ((val1 < val2) ? val1 : val2);
}

int	print_s(va_list ap, t_conv conv)
{
	char	*str;
	int		ret;

	str = va_arg(ap, char *);
	ret = (str) ? ft_strlen(str): 6;
	if (conv.minus && str) // put si ya un moins
		write(1, str, ft_strlen(str));
	else if (conv.minus)
		ft_putstr("(null)");
	ft_width(ret, conv);
	if (!conv.minus && str) // put si yavais pas de moins
		write(1, str, ft_strlen(str));
	else if (!conv.minus)
		ft_putstr("(null)");
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
	if (conv.minus)
		binary_converter(nbr);
	ft_width(72, conv);
	if (!conv.minus)
		binary_converter(nbr);
	return (ft_bigger(72, conv.width));
}
