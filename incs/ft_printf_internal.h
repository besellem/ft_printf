/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:10:51 by besellem          #+#    #+#             */
/*   Updated: 2021/08/23 02:15:06 by besellem         ###   ########.fr       */
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
// # ifdef BUFSIZ
// #  define PFT_BUFSIZ BUFSIZ
// # else
#  define PFT_BUFSIZ   16384 // 32768 // 16384 // 8192 // 4096
// # endif

# if defined(__APPLE__) && defined(__MACH__)
#  define PFT_NULL      "(null)"
#  define PFT_NULL_LEN  6
# else // Linux
#  define PFT_NULL      "(nil)"
#  define PFT_NULL_LEN  5
# endif

/*
** -- DATA STRUCTURES --
**
** flag_htag:		`#' optional flag
** flag_space:		` ' optional flag
** flag_plus:		`+' optional flag
** flag_minus:		`-' optional flag
** flag_zero:		`0' optional flag
** flag_width:			width integer
** flag_precision:	`.' optional flag
*/
enum	e_flags
{
	FLAG_HTAG = (1L << 0),
	FLAG_SPACE = (1L << 1),
	FLAG_PLUS = (1L << 2),
	FLAG_MINUS = (1L << 3),
	FLAG_ZERO = (1L << 4),
	FLAG_WIDTH = (1L << 5),
	FLAG_PRECISION = (1L << 6)
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
	IS_SPEC = (1L << 0),
	SPEC_HH = (1L << 1),
	SPEC_H = (1L << 2),
	SPEC_L = (1L << 3),
	SPEC_LL = (1L << 4),
	SPEC_J = (1L << 5),
	SPEC_Z = (1L << 6),
	SPEC_T = (1L << 7),
	SPEC_LF = (1L << 8)
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
	int			width;
	int			precision;
}				t_conv;

typedef struct s_pft
{
	int			fd;
	int			size;
	int			global_size;
	char		*ret;
	char		buffer[PFT_BUFSIZ + 1];
	int			(*write2buf)(struct	s_pft *, char *);
	t_conv		conversion;
	va_list		ap;
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
void			print_binary(const char *prefix, long long n);

/*
** Common
*/
int				ft_error(t_pft *pft);
void			write2buf_str(t_pft *pft, char *str);
int				ft_len_base(long long n, int base); 	// GOT THIS FROM OLD CODEBASE
void			ft_put_int(t_pft *pft, int64_t nb, const char *base);
void			ft_put_uint(t_pft *pft, uint64_t nb, const char *base);
void			print_char(t_pft *pft, char c, int len);

/*
** Parsing
*/
int				ft_parse_conversion(t_pft *pft, const char *fmt);

/*
** Specifiers
*/
int64_t			ft_get_val_int(t_pft *pft, char *sign);
uint64_t		ft_get_val_uint(t_pft *pft);
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
