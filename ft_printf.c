/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:31:11 by rhunders          #+#    #+#             */
/*   Updated: 2018/12/19 02:13:45 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "include/printf.h"
#include <unistd.h>
#include "g_flag_array.h"

void	error()
{
	ft_putstr("\n*** Invalid_flag ***\n");
	exit(0);
}

int		ft_isnum(char c)
{
	return (c <= '9' && c >= '0');
}

int		ft_printf(const char *arg, ...)
{
	int				run;
//	t_flag_array	*flag_array;
	va_list			ap;

	if (!arg)
		return (0);
//	flag_array = create_flag_array();
	va_start(ap, arg);
	run = printf_recurs((char *)arg, ap, flag_array);
	va_end(ap);
//	free(flag_array);
	return (run);
}
//#include <stdio.h>

int		ft_precision(char **arg, t_conv *conv)
{
	if (ft_isnum((*arg)[1]))
	{
		conv->precision = ft_atoi((*arg) + 1);
		if (conv->precision == 1)
			conv->one = 1;
		return (nb_len(conv->precision, 10));
	}
	//conv->dot = 1;
	return ((conv->precision = 0));
}

void	create_conv(char **arg, t_conv *conv)
{
	while ((**arg == '-' && (conv->minus = 1)) ||
		(**arg == '+' && (conv->plus = 1)) ||
		(**arg == '0' && (conv->zero = 1)) ||
		(**arg == '#' && (conv->sharp = 1)) ||
		(**arg == ' ' && (conv->space = 1)))
		*arg += 1;
	if (ft_isnum(**arg) && (conv->width = ft_atoi(*arg)))
		*arg += nb_len(conv->width, 10);
	if (**arg == '.')
		*arg += 1 + ft_precision(arg, conv);
	if (**arg &&
		((**arg == 'h' && (*arg)[1] == 'h' && (conv->modifier = HH)) ||
		(**arg == 'h' && (conv->modifier = H)) ||
		(**arg == 'l'  && (*arg)[1] == 'l' && (conv->modifier = LL)) ||
		(**arg == 'l' && (conv->modifier = L))))
		*arg += (conv->modifier == LL || conv->modifier == HH) + 1;
	if (ft_strchr("dcsoiuxXpf%", **arg))
		*arg += 1;
}

int		check_valid_flag(char **arg, t_conv *conv, t_flag_array *flag_array, int size)
{
	int count;
	int i;

	i = -1;
	conv->index = -1;
	while (++i < size && (count = -1))
		while (++count < NUMBER_OF_FLAG)
			if ((*arg)[i] == flag_array[count].flag_char)
			{
				conv->index = count;
				conv->precision = -1;
				create_conv(arg, conv);
				return (1);
			}
	return (0);
}

int		ft_ischar_flag(char arg)
{
	return (arg && ft_strchr("#. -+0123456789hl", arg));
}

int		dot(t_conv conv, int modif_w)
{
	int		ret;

	conv.width = conv.width - modif_w;
	ret = (conv.width < 0) ? 0: conv.width;
	if (conv.sharp && flag_array[conv.index].flag_char == 'o')
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
		if (conv.plus && (flag_array[conv.index].flag_char == 'd' ||
			flag_array[conv.index].flag_char == 'i') && conv.minus)
			write(1, "+", 1);
		ft_width(0, &conv);
		if (conv.plus && (flag_array[conv.index].flag_char == 'd' ||
			flag_array[conv.index].flag_char == 'i') && !conv.minus)
			write(1, "+", 1);
	}
	return (ret);
}

int		search_flag(va_list ap, char **arg, t_flag_array *flag_array)
{
	int		count;
	int		size;
	t_conv	conv;

	ft_memset((void*)&conv, (size = 0), sizeof(t_conv));
	while (ft_ischar_flag((*arg)[size]) || (ft_strchr("dcsoiuxXpf%",(*arg)[size]) && !++size))
		size++;						 				   // taille du flag au max
	if (!(count = check_valid_flag(arg, &conv, flag_array, size)))  // met dans conv le type de conversion
	{
		while (ft_ischar_flag(**arg))
			*arg += 1;
		return (0);
	}
	return (flag_array[conv.index].function(ap, conv));
}

int		printf_recurs(char *arg, va_list ap, t_flag_array *flag_array)
{
	int		size;
	char	*percent;

	percent = NULL;
	if (!*arg)
		return (0);
	if (*arg == '%' && (arg++))
		return (search_flag(ap, &arg, flag_array) + printf_recurs(arg, ap, flag_array));
	if ((percent = ft_strchr(arg, '%')))
		size = write(1, arg, percent - arg);
	else
		size = write(1, arg, ft_strlen(arg));
	arg += size;
	return ((percent) ? (size + printf_recurs(arg, ap, flag_array)) : (size));	
}

t_flag_array	*create_flag_array(void)
{
	t_flag_array *flag_array = malloc(sizeof(t_flag_array) * NUMBER_OF_FLAG);
	char *all_flags = "dcsoxXiupf%";
	int index;

	index = -1;
	while (++index < NUMBER_OF_FLAG)
		flag_array[index].flag_char = all_flags[index];
	flag_array[0].function = print_di;
	flag_array[1].function = print_c;
	flag_array[2].function = print_s;
	flag_array[3].function = print_o;
	flag_array[4].function = print_x_low;
	flag_array[5].function = print_x_up;
	flag_array[6].function = print_di;
	flag_array[7].function = print_u;
	flag_array[8].function = print_p;
	//flag_array[9].function = print_f;
	flag_array[10].function = print_percent;
	return (flag_array);
}
