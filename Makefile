# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 12:16:07 by ptorchbu          #+#    #+#              #
#    Updated: 2019/02/28 12:30:09 by ptorchbu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBRARY = libft.a

SRC = main.c get_list.c validation.c create_list.c map.c algorithm.c
OBJS = main.o get_list.o validation.o create_list.o map.o algorithm.o

HEAD = -I.

all: $(NAME)

$(NAME):
		make re -C ./libft
		gcc -c -Wall -Wextra -Werror $(SRC) $(HEAD)
		gcc -Wall -Wextra -Werror $(OBJS) -L. libft/$(LIBRARY) -o $(NAME)
		make fclean -C ./libft

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

