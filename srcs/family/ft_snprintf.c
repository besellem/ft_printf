/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 03:11:45 by besellem          #+#    #+#             */
/*   Updated: 2021/09/03 03:19:13 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (len);
}
