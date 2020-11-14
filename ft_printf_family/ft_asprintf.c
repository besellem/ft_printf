/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:28:41 by besellem          #+#    #+#             */
/*   Updated: 2020/11/14 21:05:38 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_asprintf(char **ret, const char *format, ...)
{
	va_list	ap;
	int		size;

	va_start(ap, format);
	size = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (size);
}
