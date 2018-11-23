/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:54:02 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/23 16:14:17 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define NUMBER_OF_FLAG 14
#include "libft.h"

typedef struct	s_flag_array
{
    char flagChar;
    void (*flagFunction)();
}				t_flag_array;

typedef struct	s_conv
{
	int	sharp;
	int	space;
	int zero;
	int	minus;
	int plus;
	int width;
	int	precision;
	int size;
	int	index;
}				t_conv;

int ft_printf(char *arg, ...);
t_flag_array *create_flag_array(void);
int special_case_check (char *arg, int index);
void ft_put_octal(int nb);
void print_int(int input);
void print_char(int input);
void print_string(char *input);
void print_string_and_unprintable(unsigned char *input);
void binary_converter(int input);
void octal_converter(long input);
void lower_hexa_converter(unsigned long input);
void upper_hexa_converter(unsigned long input);
int prefix_case(char *arg, int index);
void print_unsigned_int(unsigned int input);
void print_address(unsigned long input);
void sharp_octal_converter(int input);
void print_plus(int input);
void print_space(int input);
int index_prefix_case(char *arg, int index);

#endif
