/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:14:58 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/03/01 10:20:55 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			del_list(t_flist **list)
{
	t_flist	*alst;
	t_flist *start;

	if (list == NULL)
		return ;
	alst = *list;
	while (alst != NULL)
	{
		start = alst->next;
		free(alst);
		alst = start;
	}
	*list = NULL;
}

void			vision(char ***x, int i)
{
	int		q;
	int		j;

	q = 0;
	j = 0;
	while (q < i)
	{
		while (j < i)
		{
			ft_putendl(x[q][j]);
			j++;
		}
		q++;
	}
}

void			del_str(char ***x)
{
	int		j;

	j = 0;
	while ((*x)[j])
	{
		free((*x)[j]);
		(*x)[j] = NULL;
		j++;
	}
	free(*x);
	*x = NULL;
}

static	t_flist	*ft_create_coordin(char *stetr)
{
	t_flist	*tetr;
	int		count;
	int		i;
	int		start;

	i = 0;
	while (stetr[i] != '#')
		i++;
	start = i;
	tetr = (t_flist*)malloc(sizeof(t_flist));
	tetr->x[0] = 0;
	tetr->y[0] = 0;
	count = 1;
	while (count < 4)
	{
		i++;
		if (stetr[i] == '#')
		{
			tetr->x[count] = (i % 5) - (start % 5);
			tetr->y[count] = (i / 5) - (start / 5);
			count++;
		}
	}
	return (tetr);
}

t_flist			*ft_create_list(int len, char **str)
{
	t_flist	*new;
	t_flist	*list;
	t_flist	*start;
	int		i;

	i = 1;
	new = ft_create_coordin(str[0]);
	new->next = NULL;
	new->alpha = 'A';
	start = new;
	while (i < len)
	{
		list = ft_create_coordin(str[i]);
		list->alpha = 'A' + i;
		list->next = NULL;
		start->next = list;
		start = list;
		i++;
	}
	return (new);
}
