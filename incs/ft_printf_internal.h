/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:10:51 by besellem          #+#    #+#             */
/*   Updated: 2021/09/02 16:28:57 by besellem         ###   ########.fr       */
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
# define PFT_ERR        (-1)

# ifdef BUFSIZ
#  define PFT_BUFSIZ    BUFSIZ
# else
#  define PFT_BUFSIZ    16384 // 32768 // 16384 // 8192 // 4096
# endif

# define PFT_NULL       "(null)"

/*
** printf("%p", NULL):
**   macOS -> "(null)"
**   Linux -> "(nil)"
*/
# if defined(__APPLE__) && defined(__MACH__)
#  define PFT_NULL_PTR  PFT_NULL
# else
#  define PFT_NULL_PTR  "(nil)"
# endif

# define DEC_CHARSET    "0123456789"
# define OCT_CHARSET    "01234567"
# define HEX_CHARSET    "0123456789abcdef"
# define HEX_CHARSET_UP "0123456789ABCDEF"

/* UNUSED */
#define PFT_CHARSET        "$#* -+0123456789hljztL.sducpxXiobfgean%"
#define PFT_END_CONVERSION "sducpxXiobfgean"
/* END UNUSED */

/*
** -- DATA STRUCTURES --
**
** flag_htag:		`#' optional flag
** flag_space:		` ' optional flag
** flag_plus:		`+' optional flag
** flag_minus:		`-' optional flag
** flag_zero:		`0' optional flag
*/
# define FLAG_HTAG  0x01
# define FLAG_SPACE 0x02
# define FLAG_PLUS  0x04
# define FLAG_MINUS 0x08
# define FLAG_ZERO  0x10

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
# define IS_SPEC    0x01
# define SPEC_HH    0x02
# define SPEC_H     0x04
# define SPEC_L     0x08
# define SPEC_LL    0x10
# define SPEC_J     0x20
# define SPEC_Z     0x40
# define SPEC_T     0x80
# define SPEC_LF    0x100

/*
** is used internally to get all the right padding infos
*/
typedef struct s_padding
{
	char	_pre_char[3];
	int		_sign;
	int		_len;
	int		_pre;
	int		_width;
	int		_prec;
}				t_padding;

# define POS        1    /* positive number - used in `t_padding' _sign */
# define NEG        (-1) /* negative number - used in `t_padding' _sign */

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
	int			(*write2buf_s)(struct	s_pft *, const char *);
	t_conv		conversion;
	va_list		ap;
}				t_pft;

/*
** -- PROTOTYPES --
** Utils
*/
void			print_flags(t_conv conv);
void			print_binary(const char *prefix, long long n);

/*
** Common
*/
int				ft_error(t_pft *pft);
void			write2buf_str(t_pft *pft, char *str);
int				ft_uint_base(uintmax_t n, int base);
int				ft_dbl_base(t_pft *pft, double n, int base);
void			ft_put_int(t_pft *pft, intmax_t nb, const char *base);
void			ft_put_uint(t_pft *pft, uintmax_t nb, const char *base);
void			ft_put_float(t_pft *pft, double nb, const char *base);
int				ft_print_special_fp(t_pft *pft, double nb);
void			print_char(t_pft *pft, char c, int n);
int				isflag(t_pft *pft, unsigned int flag);
void			__int_padding__(t_pft *pft, t_padding *pad, intmax_t val);
void			__uint_padding__(t_pft *pft, t_padding *pad, uintmax_t val);
void			__dbl_padding__(t_pft *pft, t_padding *pad, double val);

/*
** Parsing
*/
int				check_wdt(const char *fmt, va_list ap, t_conv *conversion);
int				check_zero(const char *fmt, va_list ap, t_conv *conversion);
int				check_prec(const char *fmt, va_list ap, t_conv *conversion);
int				check_htag(t_conv *conversion);
int				check_spce(t_conv *conversion);
int				check_plus(t_conv *conversion);
int				check_min(t_conv *conversion);
int				ft_parse_conversion(t_pft *pft, const char *fmt);

/*
** Specifiers
*/
intmax_t		ft_get_val_int(t_pft *pft, char *sign);
uintmax_t		ft_get_val_uint(t_pft *pft);
long double		ft_get_val_float(t_pft *pft);

/*
** Conversions
*/
void			conv_c(t_pft *pft);
void			conv_s(t_pft *pft);
void			conv_d(t_pft *pft);
void			conv_d_max(t_pft *pft);
void			conv_i(t_pft *pft);
void			conv_u(t_pft *pft);
void			conv_u_max(t_pft *pft);
void			conv_o(t_pft *pft);
void			conv_o_max(t_pft *pft);
void			conv_b(t_pft *pft);
void			conv_f(t_pft *pft);
void			conv_a(t_pft *pft);
void			conv_x_min(t_pft *pft);
void			conv_x_max(t_pft *pft);
void			conv_p(t_pft *pft);
void			conv_perc(t_pft *pft);

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
