/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:19:08 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/27 20:19:03 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/printf.h"
#include <stdio.h>
#include <limits.h>
int main()
{
	int i;

	printf("\nret -> %d\n", ft_printf("%010.1o", 2500));
	printf("\nret -> %d\n", printf("%010.1o", 2500));
	//printf("\nret -> %d\n", printf("% -+Zoooo"));
	return (0);
}
