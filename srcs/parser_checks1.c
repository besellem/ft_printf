/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checks1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:33:51 by besellem          #+#    #+#             */
/*   Updated: 2021/09/01 01:04:40 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	check_wdt(const char *fmt, va_list ap, t_conv *conversion)
{
	if (*fmt && '*' == *fmt)
	{
		conversion->width = va_arg(ap, int);
		if (conversion->width < 0)
		{
			conversion->flags |= FLAG_MINUS;
			conversion->width = -conversion->width;
		}
		return (1);
	}
	else
		conversion->width = ft_atoi(fmt);
	return (ft_nblen_base(conversion->width, 10));
}

int	check_zero(const char *fmt, va_list ap, t_conv *conversion)
{
	conversion->flags |= FLAG_ZERO;
	if (*fmt && '0' == *fmt)
		return (0);
	if (*fmt && '+' == *fmt)
		return (check_plus(conversion) - 1);
	if (*fmt && '*' == *fmt)
	{
		conversion->width = va_arg(ap, int);
		if (conversion->width < 0)
		{
			conversion->width = -conversion->width;
			conversion->flags |= FLAG_MINUS;
		}
		return (1);
	}
	if (*fmt && ft_atoi(fmt) < 0)
		return (check_min(conversion));
	else if (*fmt && 0 == ft_atoi(fmt))
	{
		conversion->width = 0;
		return (0);
	}
	conversion->width = ft_atoi(fmt);
	return (ft_nblen_base(conversion->width, 10));
}

int	check_prec(const char *fmt, va_list ap, t_conv *conversion)
{
	int	i;
	int	val;

	conversion->precision = 0;
	if (*fmt && '*' == *fmt)
	{
		conversion->precision = va_arg(ap, int);
		if (conversion->precision < 0)
			conversion->precision = -1;
		return (1);
	}
	else
	{
		i = 0;
		while (fmt[i] && '0' == fmt[i])
			++i;
		val = ft_atoi(fmt + i);
		if (0 == val)
			return (i);
		if (val < 0)
			conversion->precision = -1;
		else
			conversion->precision = val;
		return (i + ft_nblen_base(conversion->precision, 10));
	}
}
