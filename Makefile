# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 21:13:07 by besellem          #+#    #+#              #
#    Updated: 2020/11/02 21:28:22 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MUTE		=	@
NAME		=	libftprintf.a
EXEC		=	ft_printf_test

## Mandatory
INCS		=	includes/ft_printf.h

LIBFT		=	libft/libft.a

SRCS		+=	srcs/ft_alloc_c.c
SRCS		+=	srcs/ft_alloc_s.c
SRCS		+=	srcs/ft_alloc_d.c
SRCS		+=	srcs/ft_alloc_i.c
SRCS		+=	srcs/ft_alloc_u.c
SRCS		+=	srcs/ft_alloc_o.c
SRCS		+=	srcs/ft_alloc_hex_maj.c
SRCS		+=	srcs/ft_alloc_hex_min.c
SRCS		+=	srcs/ft_alloc_mod.c
SRCS		+=	srcs/ft_alloc_p.c
SRCS		+=	srcs/ft_common.c
SRCS		+=	srcs/ft_lst_common.c
SRCS		+=	srcs/init.c
SRCS		+=	srcs/ft_parser.c
SRCS		+=	srcs/ft_alloc_txt.c
SRCS		+=	srcs/ft_alloc_format.c
SRCS		+=	srcs/ft_format_checks.c
SRCS		+=	srcs/ft_padding.c
SRCS		+=	srcs/ft_printf.c
SRCS		+=	srcs/ft_dprintf.c
SRCS		+=	srcs/ft_asprintf.c

## Objects
OBJS		=	$(SRCS:.c=.o)

## Commands
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SFLAGS		=	-fsanitize=address
LIBC		=	ar rc
RM			=	rm -f

.c.o:
			$(MUTE) $(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME):	$(OBJS)
			$(MUTE) cd libft && make bonus && make clean
			$(MUTE) $(LIBC) $(NAME) $(OBJS)

all:		$(NAME)

test:		all
			$(MUTE) $(CC) $(CFLAGS) $(SFLAGS) test/main.c $(NAME) $(LIBFT) -o $(EXEC)

clean:
			$(MUTE) $(RM) $(OBJS)
			$(MUTE) cd libft && make clean

fclean:		clean
			$(MUTE) $(RM) $(NAME)
			$(MUTE) $(RM) $(LIBFT)
			$(MUTE) $(RM) $(EXEC)
			$(MUTE) cd libft && make fclean

re:			fclean all

.PHONY:		$(NAME) all test clean fclean re
