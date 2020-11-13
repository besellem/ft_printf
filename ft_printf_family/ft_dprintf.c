/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:26:27 by besellem          #+#    #+#             */
/*   Updated: 2020/11/02 21:26:42 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		size;

	va_start(ap, format);
	size = ft_process(format, ap, fd);
	va_end(ap);
	return (size);
}
