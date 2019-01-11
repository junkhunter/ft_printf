/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 02:03:48 by rhunders          #+#    #+#             */
/*   Updated: 2019/01/11 11:14:28 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void	detect_flag(char **arg, t_conv *conv)
{
	int		var;

	var = 1;
	while (var)
	{
		var = 0;
		if (**arg == '-' && (var = 1))
			conv->minus = 1;
		else if (**arg == '+' && (var = 1))
			conv->plus = 1;
		else if (**arg == '0' && (var = 1))
			conv->zero = 1;
		else if (**arg == '#' && (var = 1))
			conv->sharp = 1;
		else if (**arg == ' ' && (var = 1))
			conv->space = 1;
		if (var)
			*arg += 1;
	}
}

void	detect_modifier(char **arg, t_conv *conv)
{
	if (**arg == 'h' && (*arg)[1] == 'h')
		conv->modifier = HH;
	else if (**arg == 'h')
		conv->modifier = H;
	else if (**arg == 'l' && (*arg)[1] == 'l')
		conv->modifier = LL;
	else if (**arg == 'l')
		conv->modifier = L;
	else if (**arg == 'L')
		conv->modifier = L_MAJ;
	else if (**arg == 'j')
		conv->modifier = J;
	else if (**arg == 'z')
		conv->modifier = Z;
	if (conv->modifier)
		*arg += (conv->modifier == LL || conv->modifier == HH) + 1;
}

void	create_conv(char **arg, t_conv *conv)
{
	detect_flag(arg, conv);
	if (ft_isnum(**arg) && (conv->width = ft_atoi(*arg)))
		*arg += nb_len(conv->width, 10);
	if (**arg == '.')
		*arg += 1 + ft_precision(arg, conv);
	detect_modifier(arg, conv);
	if (ft_strchr("dcsoOiuUxXpfF%", **arg))
		*arg += 1;
}

int		ft_isnum(char c)
{
	return (c <= '9' && c >= '0');
}
