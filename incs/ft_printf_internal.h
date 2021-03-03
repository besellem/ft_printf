/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:10:51 by besellem          #+#    #+#             */
/*   Updated: 2021/03/03 02:06:33 by besellem         ###   ########.fr       */
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
# include <stdint.h>
# include <stddef.h>
# include <wchar.h>
# include <unistd.h>
# include <libft.h>

/*
** -- DEFINES --
*/
# define PFT_BUFSIZ 4096

/*
** -- DATA STRUCTURES --
**
** flag_arg_nbr:	`$' optional flag
** flag_htag:		`#' optional flag
** flag_space:		` ' optional flag
** flag_plus:		`+' optional flag
** flag_minus:		`-' optional flag
** flag_zero:		`0' optional flag
** flag_width:			found width integer
** flag_precision:	`.' optional flag
*/
enum	e_flags
{
	flag_arg_nbr = (1L << 0),
	flag_htag = (1L << 1),
	flag_apostrophe = (1L << 2),
	flag_space = (1L << 3),
	flag_plus = (1L << 4),
	flag_minus = (1L << 5),
	flag_zero = (1L << 6),
	flag_width = (1L << 7),
	flag_precision = (1L << 8)
};

/*
** is_spec:		found a specifier
** spec_h:		`h'  specifier
** spec_hh:		`hh' specifier
** spec_l:		`l'  specifier
** spec_ll:		`ll' specifier
** spec_lf:		`L'  specifier
** spec_j:		`j'  specifier
** spec_z:		`z'  specifier
** spec_t:		`t'  specifier
*/
enum	e_specifiers
{
	is_spec = (1L << 0),
	spec_h = (1L << 1),
	spec_hh = (1L << 2),
	spec_l = (1L << 3),
	spec_ll = (1L << 4),
	spec_lf = (1L << 5),
	spec_j = (1L << 6),
	spec_z = (1L << 7),
	spec_t = (1L << 8)
};

/*
** `flags' and `specifiers' are used with `e_flag' and `e_specifiers' flags
**
** arg_nbr:		contains a valid integer parsed from ft_printf's `format'
** width:		contains a valid integer parsed from ft_printf's `format'
** precision:	contains a valid integer parsed from ft_printf's `format'
*/
typedef	struct	s_conv
{
	uint16_t	flags;
	uint16_t	specifiers;
	int			arg_nbr;
	int			width;
	int			precision;
}				t_conv;

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
	t_conv		conversion;
	int			(*write2buf)();
}				t_pft;

/*
** -- PROTOTYPES --
*/
int				ft_parse_conversion(t_pft *pft, const char *fmt);

/*
** Main
*/
void			ft_printf_process(const char *fmt, va_list ap, t_pft *pft);

int				ft_vdprintf_internal(int fd, const char *fmt, va_list ap);
int				ft_vasprintf_internal(char **ret, const char *fmt, va_list ap);

#endif
