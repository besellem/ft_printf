/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:02:45 by besellem          #+#    #+#             */
/*   Updated: 2020/11/01 23:53:00 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

/*
** -- STRUCTURES --
*/
typedef	struct	s_types
{
	char type;
	void (*f)();
}				t_types;

typedef	struct	s_indicators
{
	int width;
	int minus;
	int zero;
	int dot;
}				t_indicators;

typedef	struct	s_data
{
	char			*data;
	int				size;
	struct s_data	*next;
}				t_data;

/*
** -- PROTOTYPES --
** Common
*/
int				ft_len_base(long long n, int base);
void			*ft_malloc_c(size_t size, char c);
void			ft_free(size_t nb, ...);
char			*convert_base(long long ptr, char *base);
void			add_lstd(t_data **s, char *str);

/*
** Lists
*/
t_data			*ft_lstd_new(char *data, int size);
t_data			*ft_lstd_last(t_data *lst);
void			ft_lstd_add(t_data **lst, t_data *new);
void			ft_lstd_print(t_data **s, int *size, int fd);
void			ft_lstd_clear(t_data **lst);

/*
** Format Checks
*/
int				check_min(t_indicators *table);
int				check_wdt(const char *format, va_list ap, t_indicators *table);
int				check_zero(const char *format, va_list ap, t_indicators *table);
int				check_prec(const char *format, va_list ap, t_indicators *table);

/*
** Padding
*/
char			*space_padding(char *data, int padding);
char			*zero_padding(long long nbr, int pad, char *base);
char			*prec_padding(long long nbr, int pad, char *base);

/*
** Alloc
*/
t_types			*ft_init_conversions(void);
char			*ft_check_indic_d(long long nbr, t_indicators t, char *base);
void			ft_alloc_c(t_data **s, t_indicators t, va_list ap);
void			ft_alloc_s(t_data **s, t_indicators	t, va_list ap);
void			ft_alloc_p(t_data **s, t_indicators	t, va_list ap);
void			ft_alloc_d(t_data **s, t_indicators t, va_list ap);
void			ft_alloc_i(t_data **s, t_indicators t, va_list ap);
void			ft_alloc_u(t_data **s, t_indicators t, va_list ap);
void			ft_alloc_hex_min(t_data **s, t_indicators t, va_list ap);
void			ft_alloc_hex_maj(t_data **s, t_indicators t, va_list ap);

int				ft_alloc_txt(const char *format, t_data **s);
int				ft_alloc_format(const char *format, va_list ap, t_data **s,
								t_types	*t);

/*
** Parser
*/
t_data			*ft_parse_format(const char *format, va_list ap);
int				ft_process(const char *format, va_list ap, int fd);

/*
** printf functions
*/
int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

#endif
