/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:54:02 by rhunders          #+#    #+#             */
/*   Updated: 2019/01/11 11:20:57 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define NUMBER_OF_FLAG 14
# define HH 1
# define H  2
# define LL 3
# define L  4
# define L_MAJ  5
# define J	6
# define Z	7
# define D  0
# define C  1
# define S  2
# define O  3
# define I  4
# define U  5
# define X_LOW  6
# define X_UP  7
# define P  8
# define F  9
# define F_MAJ  10
# define PERC  11
# define O_MAJ 12
# define U_MAJ 13
# include "libft.h"
# include <stdarg.h>

typedef struct	s_conv
{
	char		sharp;
	char		space;
	char		zero;
	char		minus;
	char		plus;
	char		size;
	char		modifier;
	int			width;
	int			precision;
	int			one;
	int			index;
	int			neg_f;
}				t_conv;

typedef struct	s_flag_array
{
	char		flag_char;
	int			(*function)(va_list ap, t_conv conv);
}				t_flag_array;

int				ft_printf(const char *arg, ...);
int				printf_recurs(char *arg, va_list ap);
int				print_di(va_list ap, t_conv conv);
int				print_c(va_list ap, t_conv conv);
int				print_s(va_list ap, t_conv conv);
int				print_o(va_list ap, t_conv conv);
int				print_x_low(va_list ap, t_conv conv);
int				print_x_up(va_list ap, t_conv conv);
int				print_u(va_list ap, t_conv conv);
int				print_p(va_list ap, t_conv conv);
int				print_percent(va_list ap, t_conv conv);
int				print_f(va_list ap, t_conv conv);
int				invalid_conversion(char **arg, t_conv conv);

int				ft_bigger(int val1, int val2);
void			ft_width(int size_input, t_conv *conv);
long			ft_abs(long nb);
int				nb_len(long nb, int base);
int				nb_ulen(unsigned long nb, int base);
int				dot(t_conv conv, int modif_w);
int				ft_pow(int nb, int exp);
void			ft_putlong(long nb);
void			s_check_prec(t_conv conv, int *prec, int *ret, char *str);
int				ft_ischar_flag(char arg);
int				ft_isnum(char c);
int				ft_precision(char **arg, t_conv *conv);
void			create_conv(char **arg, t_conv *conv);
char			*ft_ltoa(long nb);
void			ft_putnbrlu_base(unsigned long nb, int precision,
		char *digit, int base);

long			va_arg_di(va_list ap, t_conv conv);
unsigned long	va_arg_oux(va_list ap, t_conv conv);
long double		va_arg_f(va_list ap, t_conv *conv);

#endif
