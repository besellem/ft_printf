/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:28:16 by besellem          #+#    #+#             */
/*   Updated: 2021/09/03 02:28:52 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	ap;
	int		size;

	va_start(ap, format);
	size = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (size);
}
