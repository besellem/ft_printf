# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 21:13:07 by besellem          #+#    #+#              #
#    Updated: 2020/11/16 16:32:53 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MUTE		=	@
NAME		=	libftprintf.a
EXEC		=	ft_printf_test

## Mandatory
INCS		=	inc/ft_printf.h

LIBFT		=	libft/libft.a

SRCS		+=	srcs/ft_common.c
SRCS		+=	srcs/ft_common2.c
SRCS		+=	srcs/ft_common3.c
SRCS		+=	srcs/ft_lst_common.c
SRCS		+=	srcs/ft_lst_common2.c
SRCS		+=	srcs/ft_init_conversions.c
SRCS		+=	srcs/ft_parser.c
SRCS		+=	srcs/ft_specifiers.c
SRCS		+=	srcs/ft_alloc_txt.c
SRCS		+=	srcs/ft_alloc_format.c
SRCS		+=	srcs/ft_format_checks.c
SRCS		+=	srcs/ft_format_checks2.c
SRCS		+=	srcs/ft_alloc_mod.c
SRCS		+=	srcs/ft_alloc_c.c
SRCS		+=	srcs/ft_alloc_s.c
SRCS		+=	srcs/ft_alloc_p.c
SRCS		+=	srcs/ft_alloc_d.c
SRCS		+=	srcs/ft_alloc_i.c
SRCS		+=	srcs/ft_alloc_u.c
SRCS		+=	srcs/ft_alloc_hex_maj.c
SRCS		+=	srcs/ft_alloc_hex_min.c
SRCS		+=	srcs/ft_alloc_f.c
SRCS		+=	srcs/ft_alloc_f_utils.c
SRCS		+=	srcs/ft_alloc_n.c
SRCS		+=	srcs/ft_alloc_o.c
SRCS		+=	srcs/ft_alloc_b.c

SRCS		+=	ft_printf_family/ft_printf.c
SRCS		+=	ft_printf_family/ft_sprintf.c
SRCS		+=	ft_printf_family/ft_snprintf.c
SRCS		+=	ft_printf_family/ft_asprintf.c
SRCS		+=	ft_printf_family/ft_dprintf.c
SRCS		+=	ft_printf_family/ft_vprintf.c
SRCS		+=	ft_printf_family/ft_vsprintf.c
SRCS		+=	ft_printf_family/ft_vsnprintf.c
SRCS		+=	ft_printf_family/ft_vasprintf.c
SRCS		+=	ft_printf_family/ft_vdprintf.c

## Objects
OBJS		=	$(SRCS:.c=.o)

## Commands
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
SFLAGS		=	-fsanitize=address
LIBC		=	ar rc
RM			=	rm -f

.c.o:
			$(MUTE) $(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME):	$(OBJS)
			$(MUTE) cd libft && make
			$(MUTE) cp $(LIBFT) . && mv libft.a $(NAME)
			$(MUTE) $(LIBC) $(NAME) $(OBJS)

all:		$(NAME)

test:		all
			$(MUTE) $(CC) $(CFLAGS) $(SFLAGS) test/main.c $(NAME) -o $(EXEC)

clean:
			$(MUTE) $(RM) $(OBJS)
			$(MUTE) cd libft && make clean

fclean:		clean
			$(MUTE) $(RM) $(NAME)
			$(MUTE) $(RM) $(EXEC)
			$(MUTE) cd libft && make fclean

re:			fclean all

.PHONY:		$(NAME) all test clean fclean re
