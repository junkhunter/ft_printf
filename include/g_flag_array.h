/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_flag_array.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:25:53 by rhunders          #+#    #+#             */
/*   Updated: 2019/01/11 11:30:27 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_FLAG_ARRAY_H
# define G_FLAG_ARRAY_H
# include "printf.h"

t_flag_array	g_flag_array[14] =
{
	{'d', print_di},
	{'c', print_c},
	{'s', print_s},
	{'o', print_o},
	{'i', print_di},
	{'u', print_u},
	{'x', print_x_low},
	{'X', print_x_up},
	{'p', print_p},
	{'f', print_f},
	{'F', print_f},
	{'%', print_percent},
	{'O', print_o},
	{'U', print_u}
};

#endif
