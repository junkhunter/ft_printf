/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:42:16 by rhunders          #+#    #+#             */
/*   Updated: 2018/10/23 10:50:55 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isascii(int c)
{
	return (c < 128 && c >= 0);
}
/*
**#include <stdio.h>
**
**int main()
**{
**	printf("%d\n",ft_isascii(0));
**	printf("%d\n",ft_isascii(127));
**	printf("%d\n",ft_isascii(128));
**	printf("%d",ft_isascii(2000));
**	return (0);
**}
*/
