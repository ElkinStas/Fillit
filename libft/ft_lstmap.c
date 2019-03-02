/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:48:38 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/27 14:41:24 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *d, size_t n)
{
	n = 0;
	ft_memdel(&d);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*newl;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = f(lst);
	newl = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		if (!tmp->next)
		{
			ft_lstdel(&newl, &del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (newl);
}
