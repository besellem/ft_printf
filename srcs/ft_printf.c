/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:10:45 by besellem          #+#    #+#             */
/*   Updated: 2021/01/26 00:26:38 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int size;

	size = ft_vdprintf_internal(fd, format, ap);
	return (size);
}

int	ft_vprintf(const char *format, va_list ap)
{
	int size;

	size = ft_vdprintf_internal(1, format, ap);
	return (size);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		size;

	va_start(ap, format);
	size = ft_vdprintf_internal(fd, format, ap);
	va_end(ap);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		size;

	va_start(ap, format);
	size = ft_vdprintf_internal(1, format, ap);
	va_end(ap);
	return (size);
}
