/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:10:55 by besellem          #+#    #+#             */
/*   Updated: 2021/01/26 00:44:42 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -- INCLUDES --
*/
# include "ft_printf_internal.h"

/*
** -- PROTOTYPES --
*/
int	ft_printf(const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);
int	sprintf(char *str, const char *format, ...);
int	snprintf(char *str, size_t size, const char *format, ...);
int	asprintf(char **ret, const char *format, ...);

int	ft_vprintf(const char *format, va_list ap);
int	ft_vdprintf(int fd, const char *format, va_list ap);
int	vsprintf(char *str, const char *format, va_list ap);
int	vsnprintf(char *str, size_t size, const char *format, va_list ap);
int	vasprintf(char **ret, const char *format, va_list ap);

#endif
