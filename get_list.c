/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 09:56:27 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/03/01 09:43:59 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	char	**write_figure(char *str, int len)
{
	char	**figures;
	int		i;
	int		j;
	int		count;

	if (!(figures = (char **)malloc(sizeof(char *) * (len + 1))))
		return (0);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		j = 0;
		figures[count] = (char *)malloc(sizeof(char) * 21);
		while (i % 21 != 20)
			figures[count][j++] = str[i++];
		figures[count][j] = '\0';
		if (str[i] != '\0')
			i++;
		count++;
	}
	figures[count] = NULL;
	return (figures);
}

static	int		ft_isvalid_lines(char *str, int *len)
{
	int		lines;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		lines = 0;
		while (lines < 4)
		{
			if (ft_chars_in_line(str, &i) != 4)
				return (0);
			i++;
			lines++;
		}
		if (!(str[i] == '\0' || (str[i] == '\n' &&
						(str[i + 1] == '.' || str[i + 1] == '#'))))
			return (0);
		if (str[i] != '\0')
			i++;
		(*len)++;
	}
	if (i == 0)
		return (0);
	return (1);
}

static	char	*strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

static	char	*read_file(int fd)
{
	char	*str;
	char	*buf;
	int		ret;

	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		str = strjoin(str, buf);
	}
	free(buf);
	return (str);
}

t_flist			*get_list(int fd)
{
	char	*str;
	char	**stetr;
	int		len;
	t_flist	*list;

	len = 0;
	str = read_file(fd);
	if (!ft_isvalid_lines(str, &len) || len > 26)
	{
		ft_putendl("error");
		exit(-1);
	}
	stetr = write_figure(str, len);
	free(str);
	if (!ft_check_tetrimino(stetr))
	{
		ft_putendl("error");
		exit(-1);
	}
	list = ft_create_list(len, stetr);
	del_str(&stetr);
	return (list);
}
