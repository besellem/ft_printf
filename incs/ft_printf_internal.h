/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:10:51 by besellem          #+#    #+#             */
/*   Updated: 2021/03/18 00:08:42 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

/*
** -- INCLUDES --
*/
# include <stdio.h> // To remove
# include <stdarg.h>
# include <stdlib.h>
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
	flag_space = (1L << 2),
	flag_plus = (1L << 3),
	flag_minus = (1L << 4),
	flag_zero = (1L << 5),
	flag_width = (1L << 6),
	flag_precision = (1L << 7)
};

/*
** is_spec:		found a specifier
** spec_hh:		`hh' specifier
** spec_h:		`h'  specifier
** spec_l:		`l'  specifier
** spec_ll:		`ll' specifier
** spec_j:		`j'  specifier
** spec_z:		`z'  specifier
** spec_t:		`t'  specifier
** spec_lf:		`L'  specifier
*/
enum	e_specifiers
{
	is_spec = (1L << 0),
	spec_hh = (1L << 1),
	spec_h = (1L << 2),
	spec_l = (1L << 3),
	spec_ll = (1L << 4),
	spec_j = (1L << 5),
	spec_z = (1L << 6),
	spec_t = (1L << 7),
	spec_lf = (1L << 8)
};

/*
** `flags' and `specifiers' are used with `e_flag' and `e_specifiers' flags
**
** arg_nbr:		contains a valid integer parsed from ft_printf's `format'
** width:		contains a valid integer parsed from ft_printf's `format'
** precision:	contains a valid integer parsed from ft_printf's `format'
*/
typedef struct s_conv
{
	uint16_t	flags;
	uint16_t	specifiers;
	int			arg_nbr;
	void		*arg;
	int			width;
	int			precision;
}				t_conv;

typedef struct s_pft
{
	va_list		ap_cpy;
	va_list		ap;
	char		*ret;
	char		buffer[PFT_BUFSIZ + 1];
	int			fd;
	int			size;
	int			global_size;
	t_conv		conversion;
	int			(*write2buf)(struct	s_pft *, char *);
}				t_pft;

/*
** Used in ft_get_conversion() to execute the right function for
** the right conversion
*/
typedef struct s_conv_ptrs
{
	char	conversion;
	void	(*f)(struct	s_pft *);
}				t_conv_ptrs;

/*
** -- PROTOTYPES --
** Utils
*/
void			print_flags(t_pft *pft);

/*
** Common
*/
void			write2buf_str(t_pft *pft, char *str);
void			ft_put_int(t_pft *pft, int64_t nb, const char *base);
void			ft_put_uint(t_pft *pft, uint64_t nb, const char *base);

/*
** Parsing
*/
int				ft_parse_conversion(t_pft *pft, const char *fmt);
int				ft_parse_flags(t_pft *pft, const char *fmt);

/*
** Specifiers
*/
t_int64			ft_get_val_int(t_pft *pft, char *sign);
t_uint64		ft_get_val_uint(t_pft *pft);
long double		ft_get_val_float(t_pft *pft, char *sign);

/*
** Conversions
*/
void			conv_c(t_pft *pft);
void			conv_s(t_pft *pft);
void			conv_d(t_pft *pft);
void			conv_i(t_pft *pft);
void			conv_u(t_pft *pft);
void			conv_o(t_pft *pft);
void			conv_b(t_pft *pft);
void			conv_x_min(t_pft *pft);
void			conv_x_max(t_pft *pft);
void			conv_p(t_pft *pft);

/*
** Main
*/
void			ft_printf_process(const char *fmt, t_pft *pft);

/*
** Internals
*/
int				ft_vdprintf_internal(int fd, const char *fmt, va_list ap);
int				ft_vasprintf_internal(char **ret, const char *fmt, va_list ap);

#endif
