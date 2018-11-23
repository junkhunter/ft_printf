/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 04:18:20 by rhunders          #+#    #+#             */
/*   Updated: 2018/10/22 22:48:48 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list *alst, t_list *new)
{
	if (alst && new)
	{
		while (alst->next != NULL)
			alst = alst->next;
		alst->next = new;
		new->next = NULL;
	}
}
