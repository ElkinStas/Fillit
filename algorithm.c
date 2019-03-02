/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <bhudson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 09:08:27 by bhudson           #+#    #+#             */
/*   Updated: 2019/03/02 13:00:15 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			freemape(char ***matrix, int i)
{
	int	j;

	j = i;
	while (j >= 0)
	{
		free((*matrix)[j]);
		(*matrix)[j] = NULL;
		j--;
	}
	free(*matrix);
	*matrix = NULL;
}

static	void	antifigus(char **matrix, int x, int y, t_flist *kok)
{
	int i;

	i = 0;
	while (i < 4)
	{
		matrix[y + kok->y[i]][x + kok->x[i]] = '.';
		i++;
	}
}

static	void	figus(char **matrix, int x, int y, t_flist *kok)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		matrix[y + kok->y[i]][x + kok->x[i]] = kok->alpha;
		i++;
	}
}

static	int		func_check(char ***matrix, int x, int y, t_flist *kok)
{
	int	i;
	int	a;
	int	k;
	int	count;

	count = 0;
	i = 0;
	a = 0;
	k = ft_strlen(**matrix);
	while (a <= 4)
	{
		if (count == 4)
			return (1);
		if ((y + kok->y[i] < k) && (x + kok->x[i] < k) &&
				(y + kok->y[i] >= 0) && (x + kok->x[i] >= 0))
		{
			if ((*matrix)[y + kok->y[i]][x + kok->x[i]] == '.')
			{
				count++;
				i++;
			}
		}
		a++;
	}
	return (0);
}

int				figonmape(char **matrix, t_flist *kok)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = ft_strlen(*matrix);
	if (!kok)
		return (1);
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (func_check(&matrix, j, i, kok))
			{
				figus(matrix, j, i, kok);
				if (figonmape(matrix, kok->next))
					return (1);
				antifigus(matrix, j, i, kok);
			}
			j++;
		}
		i++;
	}
	return (0);
}
