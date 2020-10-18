# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 21:13:07 by besellem          #+#    #+#              #
#    Updated: 2020/10/17 21:13:09 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MUTE		=	@
NAME		=	libftprintf.a
EXEC		=	test_ft_printf

## Mandatory
INCS		=	includes/ft_printf.h

SRCS		+=	srcs/ft_common.c
SRCS		+=	srcs/ft_lst_common.c
SRCS		+=	srcs/ft_alloc_txt.c
SRCS		+=	srcs/ft_alloc_format.c
SRCS		+=	srcs/ft_alloc_s.c
SRCS		+=	srcs/ft_printf.c

## Objects
OBJS		=	$(SRCS:.c=.o)

## Commands
CC			=	gcc
CFLAGS		=	-fsanitize=address# -Wall -Wextra -Werror
LIBC		=	ar rc
RM			=	rm -f

.c.o:
			$(MUTE) $(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME):	$(OBJS)
			$(MUTE) $(LIBC) $(NAME) $(OBJS)

all:		$(NAME)

test:		all
			$(CC) $(CFLAGS) 

clean:
			$(MUTE) $(RM) $(OBJS)

fclean:		clean
			$(MUTE) $(RM) $(NAME)

re:			fclean all

.PHONY:		$(NAME) all bonus clean fclean re
