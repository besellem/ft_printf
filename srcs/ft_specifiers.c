/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:58:47 by besellem          #+#    #+#             */
/*   Updated: 2021/04/25 22:32:49 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

t_int64	ft_get_val_int(t_pft *pft, char *sign)
{
	t_int64	nb;

	if (SPEC_HH & pft->conversion.specifiers)
		nb = (int8_t)va_arg(pft->ap, int);
	else if (SPEC_H & pft->conversion.specifiers)
		nb = (int16_t)va_arg(pft->ap, int);
	else if (SPEC_L & pft->conversion.specifiers)
		nb = va_arg(pft->ap, long);
	else if (SPEC_LL & pft->conversion.specifiers)
		nb = va_arg(pft->ap, long long);
	else if (SPEC_J & pft->conversion.specifiers)
		nb = va_arg(pft->ap, intmax_t);
	else if (SPEC_Z & pft->conversion.specifiers)
		nb = va_arg(pft->ap, ssize_t);
	else if (SPEC_T & pft->conversion.specifiers)
		nb = va_arg(pft->ap, ptrdiff_t);
	else
		nb = va_arg(pft->ap, int);
	if (nb < 0)
		*sign = -1;
	else
		*sign = 1;
	return (nb);
}

t_uint64	ft_get_val_uint(t_pft *pft)
{
	t_uint64	nb;

	if (SPEC_HH & pft->conversion.specifiers)
		nb = (int8_t)va_arg(pft->ap, unsigned int);
	else if (SPEC_H & pft->conversion.specifiers)
		nb = (uint16_t)va_arg(pft->ap, unsigned int);
	else if (SPEC_L & pft->conversion.specifiers)
		nb = va_arg(pft->ap, unsigned long);
	else if (SPEC_LL & pft->conversion.specifiers)
		nb = va_arg(pft->ap, unsigned long long);
	else if (SPEC_J & pft->conversion.specifiers)
		nb = va_arg(pft->ap, uintmax_t);
	else if (SPEC_Z & pft->conversion.specifiers)
		nb = va_arg(pft->ap, size_t);
	else if (SPEC_T & pft->conversion.specifiers)
		nb = va_arg(pft->ap, ptrdiff_t);
	else
		nb = va_arg(pft->ap, unsigned int);
	return (nb);
}

long double	ft_get_val_float(t_pft *pft, char *sign)
{
	long double	nb;

	if (SPEC_LF & pft->conversion.specifiers)
		nb = va_arg(pft->ap, long double);
	else
		nb = va_arg(pft->ap, double);
	if (nb < 0) // False in doubles (cases -0 +0)
		*sign = -1;
	else
		*sign = 1;
	return (nb);
}
