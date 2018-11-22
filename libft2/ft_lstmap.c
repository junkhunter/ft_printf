/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:38:53 by rhunders          #+#    #+#             */
/*   Updated: 2018/10/17 01:46:06 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_lst;
	t_list	*current;

	if (lst == NULL || !f)
		return (NULL);
	begin_lst = (*f)(lst);
	current = begin_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		if (!(current->next = (*f)(lst)))
		{
			ft_lstclear(&begin_lst);
			return (begin_lst);
		}
		current = current->next;
		lst = lst->next;
	}
	current->next = NULL;
	return (begin_lst);
}
