/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 09:53:50 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/03/01 09:29:43 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_flist	*first;

	if (argc != 2)
	{
		ft_putendl("usage ./fillit file");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putendl("error");
		return (-1);
	}
	first = get_list(fd);
	ft_create_board(first);
	del_list(&first);
	if (close(fd) == -1)
	{
		ft_putendl("error");
		return (-1);
	}
	return (0);
}
