# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <besellem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 00:10:57 by besellem          #+#    #+#              #
#    Updated: 2021/06/10 21:30:44 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MUTE		=	@
NAME		=	libftprintf.a

INCS		=	-Llibft -lft -Ilibft -Iincs
SRCS		=	family/*.c srcs/*.c

## Commands
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address

LIBC		=	ar rc
RM			=	rm -f
RMRF		=	rm -rf

$(NAME):
			@echo "Compiling Libft..."
			$(MUTE) $(MAKE) -C libft >/dev/null 2>&1
			@echo "Compiling executable..."
			$(MUTE) $(CC) $(CFLAGS) main.c $(SRCS) $(INCS)
			clear && ./a.out

all:		$(NAME)


## TO REMOVE AFTER DEBUG
leaks:
			$(MUTE) $(MAKE) -C libft >/dev/null 2>&1
			$(MUTE) $(CC) -Wall -Wextra -Werror -g3 main.c $(SRCS) $(INCS)
			clear && leaks -quiet -atExit -- ./a.out
## END


clean:
			@echo "cleaning..."
			$(MUTE) $(MAKE) -C libft clean >/dev/null 2>&1

fclean:		clean
			@echo "cleaning the lib..."
			$(MUTE) $(MAKE) -C libft fclean >/dev/null 2>&1
			$(MUTE) $(RM) $(NAME)
			$(MUTE) $(RM) a.out
			$(MUTE) $(RMRF) a.out.dSYM

re:			fclean all

.PHONY:		all clean fclean re
