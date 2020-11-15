/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:35:24 by besellem          #+#    #+#             */
/*   Updated: 2020/11/15 12:01:45 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_vprintf(const char *format, va_list ap)
{
	int size;

	size = ft_vdprintf(1, format, ap);
	return (size);
}
