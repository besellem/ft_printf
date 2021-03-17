/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:10:55 by besellem          #+#    #+#             */
/*   Updated: 2021/03/17 23:43:58 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -- INCLUDES --
*/
# include <libft.h>
# include "ft_printf_internal.h"

/*
** -- PROTOTYPES --
*/
// int	ft_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));

// int	ft_dprintf(int fd,
// 		const char *format, ...) __attribute__((format(printf, 2, 3)));

// int	ft_sprintf(char *str,
// 		const char *format, ...) __attribute__((format(printf, 2, 3)));

// int	ft_snprintf(char *str, size_t size,
// 		const char *format, ...) __attribute__((format(printf, 3, 4)));

// int	ft_asprintf(char **ret,
// 		const char *format, ...) __attribute__((format(printf, 2, 3)));

// int	ft_vprintf(const char *format,
// 		va_list ap) __attribute__((format(printf, 1, 0)));

// int	ft_vdprintf(int fd, const char *format,
// 		va_list ap) __attribute__((format(printf, 2, 0)));

// int	ft_vsprintf(char *str, const char *format,
// 		va_list ap) __attribute__((format(printf, 2, 0)));

// int	ft_vsnprintf(char *str, size_t size, const char *format,
// 		va_list ap) __attribute__((format(printf, 3, 0)));

// int	ft_vasprintf(char **ret, const char *format,
// 		va_list ap) __attribute__((format(printf, 2, 0)));


// WITHOUT PRINTF'S ATTRIBUTES
int	ft_printf(const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);
int	ft_sprintf(char *str, const char *format, ...);
int	ft_snprintf(char *str, size_t size, const char *format, ...);
int	ft_asprintf(char **ret, const char *format, ...);

int	ft_vprintf(const char *format, va_list ap);
int	ft_vdprintf(int fd, const char *format, va_list ap);
int	ft_vsprintf(char *str, const char *format, va_list ap);
int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap);
int	ft_vasprintf(char **ret, const char *format, va_list ap);
// END WITHOUT PRINTF'S ATTRIBUTES


/*
** -- COLORS --
** Standard
*/
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define GRAY "\033[0;37m"

/*
** Bold
*/
# define B_BLACK "\033[1;30m"
# define B_RED "\033[1;31m"
# define B_GREEN "\033[1;32m"
# define B_YELLOW "\033[1;33m"
# define B_BLUE "\033[1;34m"
# define B_PURPLE "\033[1;35m"
# define B_CYAN "\033[1;36m"
# define B_GRAY "\033[1;37m"

/*
** Foreground
*/
# define F_BLACK "\033[40m"
# define F_RED "\033[41m"
# define F_GREEN "\033[42m"
# define F_YELLOW "\033[43m"
# define F_BLUE "\033[44m"
# define F_PURPLE "\033[45m"
# define F_CYAN "\033[46m"
# define F_GRAY "\033[47m"

/*
** Clear Codes
*/
# define CLR_COLOR "\033[0m"
# define CLR_LINE "\033[2K\r"

#endif
