/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 00:22:35 by rhunders          #+#    #+#             */
/*   Updated: 2019/01/14 08:45:39 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>

long			va_arg_di(va_list ap, t_conv conv)
{
	if (!conv.modifier)
		return ((long)((int)va_arg(ap, int)));
	else if (conv.modifier == L || conv.modifier == Z)
		return (va_arg(ap, long));
	else if (conv.modifier == H)
		return ((long)((short)va_arg(ap, int)));
	else if (conv.modifier == HH)
		return ((long)((char)va_arg(ap, int)));
	return ((long)va_arg(ap, long long));
}

unsigned long	va_arg_oux(va_list ap, t_conv conv)
{
	if (conv.index == O_MAJ || conv.index == U_MAJ)
		return (va_arg(ap, unsigned long));
	if (!conv.modifier)
		return ((unsigned long)((unsigned int)va_arg(ap, int)));
	else if (conv.modifier == L || conv.modifier == Z)
		return (va_arg(ap, unsigned long));
	else if (conv.modifier == H)
		return ((unsigned long)((unsigned short)va_arg(ap, int)));
	else if (conv.modifier == HH)
		return ((unsigned long)((unsigned char)va_arg(ap, int)));
	return ((unsigned long)va_arg(ap, unsigned long long));
}

long double		va_arg_f(va_list ap, t_conv *conv)
{
	long double ret;

	if (!conv->modifier || conv->modifier == L)
		ret = (long double)va_arg(ap, double);
	else
		ret = va_arg(ap, long double);
	conv->neg_f = (ret < 0) ? 1 : 0;
	return (ret);
}
