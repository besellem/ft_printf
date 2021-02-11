# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <besellem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 00:10:57 by besellem          #+#    #+#              #
#    Updated: 2021/02/12 00:37:07 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MUTE		=	
NAME		=	libftprintf.a

INCS		=	-Llibft -lft -Ilibft -Iincs
SRCS		=	family/*.c srcs/*.c

## Commands
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror

## TO REMOVE AFTER DEBUG
SFLAGS		=	-fsanitize=address
## END

LIBC		=	ar rc
RM			=	rm -f
RMRF		=	rm -rf

$(NAME):
			$(MUTE) $(MAKE) -C libft
			$(MUTE) $(CC) $(CFLAGS) $(SFLAGS) -g3 main.c $(SRCS) $(INCS)
			clear && ./a.out

all:		$(NAME)

leaks:
			$(MUTE) $(MAKE) -C libft
			$(MUTE) $(CC) $(CFLAGS) -g3 main.c $(SRCS) $(INCS)
			clear && leaks -atExit -- ./a.out

clean:
			$(MUTE) $(MAKE) -C libft clean

fclean:		clean
			$(MUTE) $(MAKE) -C libft fclean
			$(MUTE) $(RM) $(NAME)
			$(MUTE) $(RM) a.out
			$(MUTE) $(RMRF) a.out.dSYM

re:			fclean all

.PHONY:		$(NAME) all clean fclean re
