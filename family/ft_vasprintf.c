/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 00:41:36 by besellem          #+#    #+#             */
/*   Updated: 2021/02/12 00:41:51 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int size;

	size = ft_vasprintf_internal(ret, format, ap);
	return (size);
}
