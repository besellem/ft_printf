/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:10:51 by besellem          #+#    #+#             */
/*   Updated: 2021/03/02 23:27:44 by besellem         ###   ########.fr       */
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
# include <stdint.h>
# include <unistd.h>
# include <libft.h>

/*
** -- DEFINES --
*/
# define PFT_BUFSIZ 4096

/*
** -- STRUCTS, UNIONS & TYPEDEFS --
*/
typedef	union	u_types
{
	int8_t		var_int8;
	uint8_t		var_uint8;
	int16_t		var_int16;
	uint16_t	var_uint16;
	int32_t		var_int32;
	uint32_t	var_uint32;
	int64_t		var_int64;
	uint64_t	var_uint64;
	ptrdiff_t	var_ptrdiff;
	size_t		var_size_t;
	ssize_t		var_ssize_t;
	intmax_t	var_intmax;
	uintmax_t	var_uintmax;
}				t_types;

typedef	struct	s_pft
{
	char		*ret;
	char		buffer[PFT_BUFSIZ + 1];
	int			fd;
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
