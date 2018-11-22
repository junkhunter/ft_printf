/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:28:51 by rhunders          #+#    #+#             */
/*   Updated: 2018/10/16 19:17:43 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;

	while (alst && *alst != NULL && del)
	{
		next = alst[0]->next;
		(*del)(alst[0]->content, alst[0]->content_size);
		free(*alst);
		*alst = next;
	}
}
