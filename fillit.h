/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:28:11 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/03/01 09:37:34 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 10

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "./libft/libft.h"

typedef struct		s_flist
{
	int				x[4];
	int				y[4];
	char			alpha;
	struct s_flist	*next;
}					t_flist;

int					ft_check_tetrimino(char **stetr);
int					ft_chars_in_line(char *str, int *i);
void				vision(char ***x, int i);
void				ft_create_board(t_flist *kok);
void				freemape(char ***x, int i);
void				del_str(char ***x);
void				del_list(t_flist	**list);
int					figonmape(char **x, t_flist *kok);
t_flist				*get_list(int fd);
t_flist				*ft_create_list(int len, char **str);

#endif
