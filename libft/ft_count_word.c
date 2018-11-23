/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 03:15:37 by rhunders          #+#    #+#             */
/*   Updated: 2018/10/22 22:47:00 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_word(const char *s, char c)
{
	int i;
	int i2;
	int count;

	if (!s)
		return (0);
	count = 0;
	i = -1;
	i2 = 0;
	while (s[++i])
		if (s[i] != c)
		{
			count++;
			while (s[i + 1] && s[i] != c)
				i++;
		}
	return (count);
}
