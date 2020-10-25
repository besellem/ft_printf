/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:02:45 by besellem          #+#    #+#             */
/*   Updated: 2020/10/17 21:02:48 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

/*
** -- STRUCTURES --
*/
typedef	struct	s_types
{
	char *type;
	void (*f)();
}				t_types;

typedef	struct	s_data
{
	char			*data;
	int				size;
	struct s_data	*next;
}				t_data;

typedef	struct	s_indicators
{
	int minus;
	int zero;
	int dot;
	int star;
	int plus;
}				t_indicators;

/*
** -- PROTOTYPES --
** Common
*/
int				ft_len(const char *s);
char			*ft_dup(const char *s1);
int     		ft_ncmp(const char *s1, const char *s2, int n);

/*
** Lists
*/
t_data			*ft_lstd_new(char *data, int size);
t_data			*ft_lstd_last(t_data *lst);
void			ft_lstd_add(t_data **lst, t_data *new);
void			ft_lstd_print(t_data **s, int *size, int fd);
void			ft_lstd_clear(t_data **lst);

/*
** Alloc
*/
t_types			*ft_init_conversions(void);
void			ft_alloc_c(t_data **s, t_indicators table, va_list ap);
void			ft_alloc_s(t_data **s, t_indicators	table, va_list ap);
void			ft_alloc_p(t_data **s, t_indicators	table, va_list ap);
void			ft_alloc_d(t_data **s, t_indicators table, va_list ap);
int				ft_alloc_txt(const char *format, t_data **s);
int				ft_alloc_format(const char *format, va_list ap, t_data **s, t_types	*t);

/*
** ft_printf
*/
t_data			*ft_parse_format(const char *format, va_list ap);
int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

#endif
