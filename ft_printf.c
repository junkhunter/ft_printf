/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:11:52 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/23 18:20:38 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "include/printf.h"

int		ft_printf(char *arg, ...)
{
	int				index;
	int				run;
	t_flag_array	*flag_array;
	va_list			ap;
	int				count;
	int				size;

	flag_array = create_flag_array();
	run = ft_strlen(arg);
	index = 0;
	size = 0;
	va_start(ap, arg);
	while (/*arg[index] && run == 1*/index < run) 
	{
		index += special_case_check(arg, index);
		//run = (arg[index]) ? 1 : 0;
		if (arg[index] != '%'/* && run == 1*/ && ++size)
			ft_putchar(arg[index]);
		else 
		{
			index = (arg[index + 1] == '#') ?
				index + prefix_case(arg, index) : index + 1;
			if (index > run)
				return (-1);
			count = -1;
			while (++count < NUMBER_OF_FLAG/* && run == 1*/)
				if (arg[index] == flag_array[count].flagChar)
					size += flag_array[count].flagFunction(ap);
		}
		index += index_prefix_case(arg, index);
	}
	free(flag_array);
	return (index);
}

void	create_conv(char **arg, t_conv *conv)
{
	if (**arg == '#' && (conv->sharp = 1))
	{
		*arg += 1;
		return (create_conv(arg, conv));
	}
	if (**arg == '0' && (conv->zero = 1))
	{
		*arg += 1;
		return (create_conv(arg, conv));
	}
	if (**arg == ' ' && (conv->space = 1))
	{
		*arg += 1;
		return (create_conv(arg, conv));
	}
	if (ft_isnum(**arg) && (conv->width = ft_atoi(*arg)))
		*arg += nb_len(conv->width, 10);
	if (**arg == '.' && ft_isnum((*arg)[1]) && (conv->precision = ft_atoi((*arg) + 1)))
		*arg += 1 + nb_len(conv->precision);
}

int		check_valid_flag(char *arg, t_conv *conv, size)
{
	int count;

	count = -1;
	conv->index = -1;
	arg++;
	while (*arg)
	{
		while (++count < NUMBER_OF_FLAG)
			if (*arg == flag_array[count].flagChar)
			{
				conv->index = count;
				return (1);
			}
		count = 0;
		arg++;
	}
	return (0);
}

int		ft_ischar_flag(char arg)
{
	return (ft_strchr("#. -+0123456789dcsSboxXiupfhl", arg) && arg);
}

int		search_flag(va_list ap, char **arg, t_flag_array flag_array)
{
	int		count;
	int		size;
	t_conv	conv;

	size = 0;
	count = 0;
	ft_memset((void*)&conv, 0, sizeof(t_conv));
	while (((*arg)[size] != '%' && (*arg)[size]) || !(count = -1))
		size++;						 				   // taille du flag au max
	if (check_valid_flag(arg + 1, &conv, size) != 1)  // met dans conv le type de conversion
		error();
	create_conv(&arg, &conv);	 			  	    // organisation des info sur les flag
	return (flag_array[conv->index].function(ap, conv));
}

void	error()
{
	ft_putstr("\n*** Invalid_flag ***\n");
	exit(0);
}

int		printf_recurs(char *arg, va_list ap, t_flag_array flag_array)
{
	int		size;
	int		count;
	char	*percent;

	percent = NULL;
	if (!*arg)
		return (0);
	if (*arg == '%' && (arg++))
		return (search_flag(ap, &arg, flag_array) + printf_recurs(arg, ap, flag_array));
	else if (!(size = 0))
	{
		if ((percent = ft_strchr(arg, '%'))
			write(1, arg, percent - arg);
		else
			ft_putstr(arg);
		size = (percent) ? (percent - arg) : ft_strlen(arg);
		arg += size;
		return ((percent) ? (size + printf(arg, ap, flag_array)) : (size));	
	}
}

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
}
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
	char *allFlags = "dcsSboxXiupf";
	int index;

	index = -1;
	while (++index < NUMBER_OF_FLAG)
		flag_array[index].flagChar = allFlags[index];
	flag_array[0].flagFunction = print_int;
	flag_array[1].flagFunction = print_char;
	flag_array[2].flagFunction = print_string;
	flag_array[3].flagFunction = print_string_and_unprintable;
	flag_array[4].flagFunction = binary_converter;
	flag_array[5].flagFunction = octal_converter;
	flag_array[5].flagFunction = octal_converter;
	flag_array[6].flagFunction = lower_hexa_converter;
	flag_array[7].flagFunction = upper_hexa_converter;
	flag_array[8].flagFunction = print_int;
	flag_array[9].flagFunction = print_unsigned_int;
	flag_array[10].flagFunction = print_address;
	flag_array[11].flagFunction = print_float;
	return (flag_array);
}
