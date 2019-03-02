/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:26:19 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/02/28 13:37:18 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	ft_count_contact(char *str, int num)
{
	int	count;

	count = 0;
	if (num < 20 && str[num + 1] == '#')
		count++;
	if (num > 0 && str[num - 1] == '#')
		count++;
	if (num < 15 && str[num + 5] == '#')
		count++;
	if (num > 4 && str[num - 5] == '#')
		count++;
	return (count);
}

static	int	ft_check_figure(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			count += ft_count_contact(str, i);
		i++;
	}
	if (count >= 5)
		return (1);
	return (0);
}

int			ft_chars_in_line(char *str, int *i)
{
	int	count;

	count = 0;
	while (str[*i] != '\n')
	{
		if (str[*i] == '\0')
			return (0);
		count++;
		(*i)++;
	}
	return (count);
}

static	int	ft_is_valid_chars(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		if (str[i] == '#')
			count++;
		i++;
	}
	if (count != 4)
		return (0);
	return (1);
}

int			ft_check_tetrimino(char **stetr)
{
	int	i;

	i = 0;
	while (stetr[i] != NULL)
	{
		if (!ft_is_valid_chars(stetr[i]) || !ft_check_figure(stetr[i]))
			return (0);
		i++;
	}
	return (1);
}
