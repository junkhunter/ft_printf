/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:17:11 by rhunders          #+#    #+#             */
/*   Updated: 2018/10/07 16:54:23 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(const char *s1, const char *s2)
{
	if (s1 != NULL && s2 != NULL)
		while (*s1 == *s2)
		{
			if (!*s1)
				return (1);
			s1++;
			s2++;
		}
	return (0);
}