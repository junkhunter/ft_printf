/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:11:52 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/22 22:46:31 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "include/printf.h"

int		ft_printf(char *arg, ...)
{
	int				index;
	int				run;
	t_flag_array	*flagArray;
	va_list			ap;
	int				count;

	flagArray = create_flag_array();
	run = ft_strlen(arg);
	index = 0;
	va_start(ap, arg);
	while (/*arg[index] && run == 1*/index < run) 
	{
		index += special_case_check(arg, index);
		//run = (arg[index]) ? 1 : 0;
		if (arg[index] != '%'/* && run == 1*/)
			ft_putchar(arg[index]);
		else 
		{
			index = (arg[index + 1] == '#') ?
				index + prefix_case(arg, index) : index + 1;
			if (!arg[index]/* && run == 1*/)
				return (-1);
			count = -1;
			while (++count < NUMBER_OF_FLAG/* && run == 1*/)
				if (arg[index] == flagArray[count].flagChar)
					flagArray[count].flagFunction(va_arg(ap, void *));
		}
		index += index_prefix_case(arg, index);
	}
	free(flagArray);
	return (index);
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

t_flag_array	*create_flag_array(void)
{
	t_flag_array *flagArray = malloc(sizeof(t_flag_array) * NUMBER_OF_FLAG);
	char *allFlags = "dcsSboxXiup#+ ";
	int index;

	index = -1;
	while (++index < NUMBER_OF_FLAG)
		flagArray[index].flagChar = allFlags[index];
	flagArray[0].flagFunction = print_int;
	flagArray[1].flagFunction = print_char;
	flagArray[2].flagFunction = print_string;
	flagArray[3].flagFunction = print_string_and_unprintable;
	flagArray[4].flagFunction = binary_converter;
	flagArray[5].flagFunction = octal_converter;
	flagArray[5].flagFunction = octal_converter;
	flagArray[6].flagFunction = lower_hexa_converter;
	flagArray[7].flagFunction = upper_hexa_converter;
	flagArray[8].flagFunction = print_int;
	flagArray[9].flagFunction = print_unsigned_int;
	flagArray[10].flagFunction = print_address;
	flagArray[11].flagFunction = sharp_octal_converter;
	flagArray[12].flagFunction = print_plus;
	flagArray[13].flagFunction = print_space;
	return (flagArray);
}
