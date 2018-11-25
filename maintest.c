/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:19:08 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/26 00:20:07 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/printf.h"
#include <stdio.h>
#include <limits.h>
int main()
{
	printf("\nret -> %d\n", ft_printf("12345 %+10.4ld 6156%s 16 qrt", LONG_MAX - 100, "**bonjour**"));
	return (0);
}
