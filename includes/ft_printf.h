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
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define TYPES "csdxX"

/*
** -- STRUCTURES --
*/
typedef	struct	s_type
{
	char			type;
	void			(*f)();
	struct s_type	*next;
}				t_type;

typedef	struct	s_types
{
	char *type;
	void (*f)();
}				t_types;

typedef	struct	s_data
{
	char			*data;
	size_t			size;
	struct s_data	*next;
}				t_data;

/*
** -- PROTOTYPES --
** Common
*/
char			*ft_dup(const char *s1);

size_t			ft_strlen(const char *s);
void			ft_putchar(unsigned int c, int *size);
void			ft_putstr(char *s, int *size);
void			ft_putnbr(long long n, int *size);
void			ft_print_hex_min(long long n, int *size);
void			ft_print_hex_maj(long long n, int *size);
t_type			*ft_init_types(void);

/*
** Lists
*/
t_data			*ft_lstd_new(char *data, size_t size);
t_data			*ft_lstd_last(t_data *lst);
void			ft_lstd_add(t_data **lst, t_data *new);
void			ft_lstd_print(t_data **s, int *size, int fd);
void			ft_lstd_clear(t_data **lst);

/*
** Alloc
*/
t_types			*ft_init_conversions(void);
void			ft_alloc_s(t_data **s, va_list ap);
int				ft_alloc_txt(const char *format, t_data **s);
int				ft_alloc_format(const char *format, va_list ap, t_data **s);

/*
** ft_printf
*/
t_data			*ft_parse_format(const char *format, va_list ap);
int				ft_printf(const char *format, ...);
int				ft_printf_fd(int fd, const char *format, ...);

int				ft_printf_bis(const char *format, ...);

#endif
