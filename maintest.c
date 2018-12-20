/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:19:08 by rhunders          #+#    #+#             */
/*   Updated: 2018/12/20 01:36:04 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/printf.h"
#include <stdio.h>
#include <limits.h>
int main()
{
	int i;
	int res1 = 0, res2 = 0;
	
	res1 = ft_printf("%09.1f\n", 0.6);
	res2 = printf("%09.1f\n", 0.6);
	//res2 =/* printf("\nret -> %d\n",*/ printf("%.p", NULL);
	printf("res1 = %d\nres2 = %d\n", res1, res2);
	//printf("\nret -> %d\n", printf("% -+Zoooo"));
	return (0);
}
