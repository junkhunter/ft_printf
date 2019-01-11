/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:31:11 by rhunders          #+#    #+#             */
/*   Updated: 2019/01/11 11:29:03 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "include/printf.h"
#include <unistd.h>
#include "g_flag_array.h"

int		ft_printf(const char *arg, ...)
{
	int				ret;
	va_list			ap;

	if (!arg)
		return (0);
	va_start(ap, arg);
	ret = printf_recurs((char *)arg, ap);
	va_end(ap);
	return (ret);
}

int		check_valid_flag(char **arg, t_conv *conv)
{
	int count;
	int i;

	i = -1;
	conv->index = -1;
	while ((*arg)[++i] && (count = -1))
	{
		while (++count < NUMBER_OF_FLAG)
			if ((*arg)[i] == g_flag_array[count].flag_char)
			{
				conv->index = count;
				conv->precision = -1;
				create_conv(arg, conv);
				return (1);
			}
		if (!ft_ischar_flag((*arg)[i]))
			return (0);
	}
	return (0);
}

int		dot(t_conv conv, int modif_w)
{
	int		ret;

	conv.width = conv.width - modif_w;
	ret = (conv.width < 0) ? 0 : conv.width;
	if (conv.sharp && g_flag_array[conv.index].flag_char == 'o')
	{
		if (conv.minus)
			write(1, "0", 1);
		if (conv.width > (ret += !ret))
			ft_width(1, &conv);
		if (!conv.minus)
			write(1, "0", 1);
	}
	else if (ret)
	{
		if (conv.plus && (g_flag_array[conv.index].flag_char == 'd' ||
			g_flag_array[conv.index].flag_char == 'i') && conv.minus)
			write(1, "+", 1);
		ft_width(0, &conv);
		if (conv.plus && (g_flag_array[conv.index].flag_char == 'd' ||
			g_flag_array[conv.index].flag_char == 'i') && !conv.minus)
			write(1, "+", 1);
	}
	return (ret);
}

int		search_flag(va_list ap, char **arg)
{
	int		count;
	t_conv	conv;

	ft_memset((void*)&conv, 0, sizeof(t_conv));
	if (!(count = check_valid_flag(arg, &conv)))
	{
		if (**arg)
			create_conv(arg, &conv);
		return (invalid_conversion(arg, conv));
	}
	return (g_flag_array[conv.index].function(ap, conv));
}

int		printf_recurs(char *arg, va_list ap)
{
	int		size;
	char	*percent;

	percent = NULL;
	if (!*arg)
		return (0);
	if (*arg == '%' && (arg++))
		return (search_flag(ap, &arg) + printf_recurs(arg, ap));
	if ((percent = ft_strchr(arg, '%')))
		size = write(1, arg, percent - arg);
	else
		size = write(1, arg, ft_strlen(arg));
	arg += size;
	return ((percent) ? (size + printf_recurs(arg, ap)) : (size));
}
