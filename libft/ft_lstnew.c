/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 19:11:10 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/22 19:51:33 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*pax;

	if (!(pax = (t_list*)malloc(sizeof(*pax))))
		return (NULL);
	if (content == NULL)
	{
		pax->content = NULL;
		pax->content_size = 0;
	}
	else
	{
		if ((pax->content = malloc(content_size)) == NULL)
		{
			free(pax);
			return (pax);
		}
		ft_memcpy(pax->content, content, content_size);
		pax->content_size = content_size;
	}
	pax->next = NULL;
	return (pax);
}
