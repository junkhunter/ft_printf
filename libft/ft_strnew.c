/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:49:56 by rhunders          #+#    #+#             */
/*   Updated: 2018/10/23 10:51:51 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = -1;
	if ((str = (char *)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	while (++i <= size)
		str[i] = '\0';
	return (str);
}
