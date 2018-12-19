/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_flag_array.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:25:53 by rhunders          #+#    #+#             */
/*   Updated: 2018/12/18 22:01:23 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_FLAG_ARRAY
# define G_FLAG_ARRAY
# include "include/printf.h"

t_flag_array    flag_array[11] = 
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
	{'f', NULL},
	{'%', print_percent},
};
#endif
