/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:48:27 by rhunders          #+#    #+#             */
/*   Updated: 2018/10/23 11:42:47 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_tabclear(char ***tab)
{
	int i;

	i = 0;
	if (tab && *tab)
	{
		while ((*tab)[i])
		{
			free((*tab)[i]);
			(*tab)[i++] = 0;
		}
		free(*tab);
		*tab = NULL;
	}
	return (NULL);
}
