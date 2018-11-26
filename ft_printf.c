/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:11:52 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/26 01:13:11 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "include/printf.h"
#include <unistd.h>

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
	t_flag_array	*flag_array;
	va_list			ap;

	flag_array = create_flag_array();
	va_start(ap, arg);
	run = printf_recurs((char *)arg, ap, flag_array);
	va_end(ap);
	free(flag_array);
	return (run);
}

void	create_conv(char **arg, t_conv *conv)
{
	if ((**arg == '-' && (conv->minus = 1)) ||
		(**arg == '+' && (conv->plus = 1)) ||
		(**arg == '0' && (conv->zero = 1)) ||
		(**arg == '#' && (conv->sharp = 1)) ||
		(**arg == ' ' && (conv->space = 1)))
	{
		*arg += 1;
		return (create_conv(arg, conv));
	}
	if (ft_isnum(**arg) && (conv->width = ft_atoi(*arg)))
		*arg += nb_len(conv->width, 10);
	if (**arg == '.' && ft_isnum((*arg)[1]) &&
		(conv->precision = ft_atoi((*arg) + 1)))
		*arg += 1 + nb_len(conv->precision, 10);
	if (**arg &&
		((**arg == 'h' && (*arg)[1] == 'h' && (conv->modifier = HH)) ||
		(**arg == 'h' && (conv->modifier = H)) ||
		(**arg == 'l'  && (*arg)[1] == 'l' && (conv->modifier = LL)) ||
		(**arg == 'l' && (conv->modifier = L))))
		*arg += (conv->modifier == LL || conv->modifier == HH) + 1;
	*arg += 1;
}

int		check_valid_flag(char **arg, t_conv *conv, t_flag_array *flag_array, int size)
{
	int count;
	int i;

	i = -1;
	count = -1;
	conv->index = -1;
	while (++i < size)
	{
		if ((*arg)[i] == '%')
		{
			create_conv(arg, conv);
			return (-1);
		}
		while (++count < NUMBER_OF_FLAG)
			if ((*arg)[i] == flag_array[count].flagChar)
			{
				conv->index = count;
				create_conv(arg, conv);
				return (1);
			}
		count = -1;
	}
	return (0);
}

int		ft_ischar_flag(char arg)
{
	return (arg && ft_strchr("#. -+0123456789dcsoxXiupfhl", arg));
}



int		search_flag(va_list ap, char **arg, t_flag_array *flag_array)
{
	int		count;
	int		size;
	t_conv	conv;

	ft_memset((void*)&conv, (size = 0), sizeof(t_conv));
	while (ft_ischar_flag((*arg)[size]) || ((*arg)[size] == '%' && !++size))
		size++;						 				   // taille du flag au max
	if ((count = check_valid_flag(arg, &conv, flag_array, size)) == 0)  // met dans conv le type de conversion
		error();
	else if (count < 0)
	{
		write(1, "%", conv.minus);
		ft_width(1, conv);
		write(1, "%", !conv.minus);
		return (ft_bigger(1, conv.width));
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
/*
int		special_case_check(char *arg, int index)
{
	int value;

	value = 0;
	if (arg[index] == 92 && arg[index + 1] == 'n')
	{
		ft_putchar('\n');
		value = 2;
	}
	if (arg[index] == '%' && arg[index + 1] == '%')
	{
		ft_putchar('%');
		value = 2;
	}
	return (value);
}*/
/*
int		prefix_case(char *arg, int index)
{
	int result;

	result = 0;
	(arg[index + 1] == '+'
	 && (arg[index + 2] == 'd' || arg[index] == 'i')) ? result = 1 : 1;
	(arg[index + 1] == ' '
	 && (arg[index + 2] == 'd' || arg[index] == 'i')) ? result = 1 : 1;
	(arg[index + 1] == '#' && arg[index + 2] == 'o') ? result = 1 : 1;
	(arg[index + 1] == '#' && arg[index + 2] == 'x') ? ft_putstr("0x") : 1;
	(arg[index + 1] == '#' && arg[index + 2] == 'X') ? ft_putstr("0X") : 1;
	if (arg[index + 1] == '#' &&
			(arg[index + 2] == 'x' || arg[index + 2] == 'X'))
		result = 2;
	return (result);
}

int		index_prefix_case(char *arg, int index)
{
	int result;

	result = 1;
	if (arg[index - 1] == '%' && arg[index - 2] != '%') {
		if (arg[index] == '#' || arg[index] == '+')
			result = 2;
		if (arg[index] == ' ' &&
				(arg[index + 1] == 'd' || arg[index + 1] == 'i'))
			result = 2;
	}
	return (result);
}
*/

t_flag_array	*create_flag_array(void)
{
	t_flag_array *flag_array = malloc(sizeof(t_flag_array) * NUMBER_OF_FLAG);
	char *allFlags = "dcsoxXiupf";
	int index;

	index = -1;
	while (++index < NUMBER_OF_FLAG)
		flag_array[index].flagChar = allFlags[index];
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
	return (flag_array);
}
