/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 00:22:35 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/26 00:33:31 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <stdarg.h>

long			va_arg_di(va_list ap, t_conv conv)
{
	if (!conv.modifier)
		return ((long)((int)va_arg(ap, int)));
	else if (conv.modifier == L)
		return (va_arg(ap, long));
	else if (conv.modifier == H)
		return ((long)((short)va_arg(ap, int)));
	else if (conv.modifier == HH)
		return ((long)((char)va_arg(ap, int)));
	return ((long)va_arg(ap, long long));
}

unsigned long   va_arg_oux(va_list ap, t_conv conv)
{
	if (!conv.modifier)
		return ((unsigned long)((unsigned int)va_arg(ap, int)));
	else if (conv.modifier == L)
		return (va_arg(ap, unsigned long));
	else if (conv.modifier == H)
		return ((unsigned long)((unsigned short)va_arg(ap, int)));
	else if (conv.modifier == HH)
		return ((unsigned long)((unsigned char)va_arg(ap, int)));
	return ((unsigned long)va_arg(ap, unsigned long long));
}

long double		va_arg_f(va_list ap, t_conv conv)
{
	if (!conv.modifier || conv.modifier == L)
		return ((long double)va_arg(ap, double));
	return (va_arg(ap, long double));
}
