/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:43:32 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/28 03:10:02 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <limits.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
int main(int argc, char **argv)
{
	char str[] = "bonjour !\n";
	/*printf ("le mien ->\n");
	octal_converter(~(unsigned long)0);
	printf("\nprintf ->\n%lo\n le mien ->\n", ~(unsigned long)0);
	lower_hexa_converter(~(unsigned long)0);
	printf("\nprintf ->%lx\n le mien\n", ~(unsigned long)0);
	upper_hexa_converter(~(unsigned long)0);
	printf("\nprintf ->%lX\n", ~(unsigned long)0);*/
	//if (argc >= 3)
	//	ft_printf(argv[1] ,(ft_atoi(argv[2])) ? (ft_atoi(argv[2])) : (argv[2]));
	//printf("%.0s" , "bonjour");
	//ft_printf("@moulitest: %5.o %5.0o", 0, 0);
	//printf("ret -> %d\n", ft_printf("le mien -> %05c\n", 'a'));
	printf("size  -> %d\n", printf("%.50Lf", LDBL_MAX / (long double)pow(10, 50)));
	10151230354136153512.0 / 10
	//ft_putnbr(33);
	//printf ("%b\n",1);
	return(0);
}
