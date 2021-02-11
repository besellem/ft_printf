/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:10:51 by besellem          #+#    #+#             */
/*   Updated: 2021/02/12 00:40:25 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

/*
** -- INCLUDES --
*/
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <libft.h>

/*
** -- DEFINES --
*/
# define PFT_BUFSIZ 4096

/*
** -- STRUCTS & TYPEDEFS --
*/
typedef	struct	s_types
{
	int8_t		int_8;
	uint8_t		uint_8;
	int16_t		int_16;
	uint16_t	uint_16;
	int32_t		int_32;
	uint32_t	uint_32;
	int64_t		int_64;
	uint64_t	uint_64;
	ptrdiff_t	ptr_diff;
	size_t		sizet;
	uintmax_t	uint_max;
}				t_types;

typedef	struct	s_pft
{
	char		buffer[PFT_BUFSIZ + 1];
	char		*ret;
	int			size;
	int			global_size;
	t_types		type;
}				t_pft;

/*
** -- PROTOTYPES --
*/
int				ft_get_conversion(t_pft *pft, const char *fmt);

/*
** Main
*/
int				ft_vdprintf_internal(int fd, const char *fmt, va_list ap);
int				ft_vasprintf_internal(char **ret, const char *fmt, va_list ap);

#endif
