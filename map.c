/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <bhudson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:22:54 by bhudson           #+#    #+#             */
/*   Updated: 2019/03/02 13:02:38 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_number_list(t_flist *kok)
{
	int		count;

	count = 0;
	while (kok->next)
	{
		count++;
		kok = kok->next;
	}
	return (count);
}

static	int		ft_optimal_wide(t_flist *kok)
{
	int		wide;
	int		number;

	wide = 2;
	number = ft_number_list(kok);
	while ((wide * wide) < (number * 4))
		wide++;
	return (wide);
}

static	void	contain(char ***matrix, int i, int q, int k)
{
	int		z;

	z = 0;
	while (z <= i)
	{
		if (z == i)
		{
			(*matrix)[q][k] = '\0';
			break ;
		}
		(*matrix)[q][k] = '.';
		k++;
		z++;
	}
}

static	char	**mape(int i)
{
	char	**x;
	int		q;
	int		j;
	int		k;

	q = 0;
	j = i;
	x = (char**)malloc(sizeof(char*) * (i + 1));
	x[i] = NULL;
	while (j > 0)
	{
		k = 0;
		x[q] = (char*)malloc(sizeof(char) * (i + 1));
		contain(&x, i, q, k);
		j--;
		q++;
	}
	return (x);
}

void			ft_create_board(t_flist *kok)
{
	char	**matrix;
	int		sum;

	sum = ft_optimal_wide(kok);
	matrix = mape(sum);
	while (!figonmape(matrix, kok))
	{
		freemape(&matrix, sum);
		matrix = mape(++sum);
	}
	vision(&matrix, sum);
	freemape(&matrix, sum);
}