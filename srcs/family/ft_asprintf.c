/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 00:42:03 by besellem          #+#    #+#             */
/*   Updated: 2021/06/10 21:31:56 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_asprintf(char **ret, const char *format, ...)
{
	va_list	ap;
	int		size;

	va_start(ap, format);
	size = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (size);
}
