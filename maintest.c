/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:19:08 by rhunders          #+#    #+#             */
/*   Updated: 2018/12/19 02:12:43 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/printf.h"
#include <stdio.h>
#include <limits.h>
int main()
{
	int i;
	int res1 = 0, res2 = 0;
	
	res1 = ft_printf("%.p", NULL);

	//res2 =/* printf("\nret -> %d\n",*/ printf("%.p", NULL);
	printf("res1 = %d\n", res1);
	//printf("\nret -> %d\n", printf("% -+Zoooo"));
	return (0);
}
