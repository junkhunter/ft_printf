/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:54:02 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/25 17:50:59 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define NUMBER_OF_FLAG 12
# define HH 1
# define H  2
# define LL 3
# define L  4
#include "libft.h"
#include <stdarg.h>

typedef struct	s_conv
{
	int			sharp;
	int			space;
	int			zero;
	int			minus;
	int			plus;
	int			width;
	int			precision;
	int			size;
	int			index;
	int			modifier;
}				t_conv;

typedef struct	s_flag_array
{
    char		flagChar;
    int 		(*flagFunction[12])(va_list, t_conv);
}				t_flag_array;

int				ft_printf(const char *arg, ...);
int				printf_recurs(char *arg, ...);
t_flag_array	*create_flag_array(void);

/* print */
int				print_di(va_list ap, t_conv conv);
int				print_c(va_list ap, t_conv conv);
int				print_s(va_list ap, t_conv conv);
int				print_s_unprintable(va_list ap, t_conv conv);
int				print_b(va_list ap, t_conv conv);
int				print_o(va_list ap, t_conv conv);
int				print_x_low(va_list ap, t_conv conv);
int				print_x_up(va_list ap, t_conv conv);
int				print_u(va_list ap, t_conv conv);
int				print_p(va_list ap, t_conv conv);

/* outils */
int     ft_bigger(int val1, int val2);
void    ft_width_di(int size_input, t_conv conv);
long    ft_abs(long nb);
int		nb_len(long nb, int base);

/* va_arg */
long			va_arg_di(va_list ap, t_conv conv);
unsigned long	va_arg_oux(va_list ap, t_conv conv);
long double		va_arg_f(va_list, t_conv conv);

/*
int special_case_check (char *arg, int index);
void ft_put_octal(int nb);
int prefix_case(char *arg, int index);
void sharp_octal_converter(int input);
void print_plus(int input);
void print_space(int input);
int index_prefix_case(char *arg, int index);
*/
#endif
