/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 14:52:04 by rhunders          #+#    #+#             */
/*   Updated: 2018/10/16 19:17:52 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **begin)
{
	if (begin && *begin)
	{
		ft_lstclear(&begin[0]->next);
		if (begin[0]->content)
			free(begin[0]->content);
		free(begin[0]);
	}
}
