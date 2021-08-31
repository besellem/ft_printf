# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <besellem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 00:10:57 by besellem          #+#    #+#              #
#    Updated: 2021/08/31 22:07:40 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MUTE		=	@
NAME		=	libftprintf.a

INCS		=	-Llibft -lft -Ilibft/incs -Iincs
SRCS		=	family/*.c srcs/*.c

## Commands
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g3# -fsanitize=address #-O1

LIBC		=	ar rc
RM			=	rm -f
RMRF		=	rm -rf

$(NAME):
			@echo "Compiling executable..."
			$(MUTE) $(CC) $(CFLAGS) main.c $(SRCS) $(INCS)
			clear && ./a.out

all:		$(NAME)


## TO REMOVE AFTER DEBUG
leaks:
			$(MUTE) $(CC) -Wall -Wextra -Werror -g3 main.c $(SRCS) $(INCS)
			clear && leaks -quiet -atExit -- ./a.out
## END


clean:
			@echo "cleaning..."

fclean:		clean
			@echo "cleaning the lib..."
			$(MUTE) $(RM) $(NAME)
			$(MUTE) $(RM) a.out
			$(MUTE) $(RMRF) a.out.dSYM

re:			fclean all

.PHONY:		all clean fclean re
