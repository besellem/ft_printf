/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:58:47 by besellem          #+#    #+#             */
/*   Updated: 2021/03/17 02:05:24 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_int64		ft_get_val_int(t_pft *pft, char *sign)
{
	t_int64	nb;

	if (spec_hh & pft->conversion.specifiers)
		nb = (int8_t)va_arg(pft->ap, int);
	else if (spec_h & pft->conversion.specifiers)
		nb = (int16_t)va_arg(pft->ap, int);
	else if (spec_l & pft->conversion.specifiers)
		nb = va_arg(pft->ap, long);
	else if (spec_ll & pft->conversion.specifiers)
		nb = va_arg(pft->ap, long long);
	else if (spec_j & pft->conversion.specifiers)
		nb = va_arg(pft->ap, intmax_t);
	else if (spec_z & pft->conversion.specifiers)
		nb = va_arg(pft->ap, ssize_t);
	else if (spec_t & pft->conversion.specifiers)
		nb = va_arg(pft->ap, ptrdiff_t);
	else
		nb = va_arg(pft->ap, int);
	if (nb < 0)
		*sign = -1;
	else
		*sign = 1;
	return (nb);
}

t_uint64		ft_get_val_uint(t_pft *pft)
{
	t_uint64 nb;

	if (spec_hh & pft->conversion.specifiers)
		nb = (int8_t)va_arg(pft->ap, unsigned int);
	else if (spec_h & pft->conversion.specifiers)
		nb = (uint16_t)va_arg(pft->ap, unsigned int);
	else if (spec_l & pft->conversion.specifiers)
		nb = va_arg(pft->ap, unsigned long);
	else if (spec_ll & pft->conversion.specifiers)
		nb = va_arg(pft->ap, unsigned long long);
	else if (spec_j & pft->conversion.specifiers)
		nb = va_arg(pft->ap, uintmax_t);
	else if (spec_z & pft->conversion.specifiers)
		nb = va_arg(pft->ap, size_t);
	else if (spec_t & pft->conversion.specifiers)
		nb = va_arg(pft->ap, ptrdiff_t);
	else
		nb = va_arg(pft->ap, unsigned int);
	return (nb);
}

long double	ft_get_val_float(t_pft *pft, char *sign)
{
	long double nb;

	if (spec_lf & pft->conversion.specifiers)
		nb = va_arg(pft->ap, long double);
	else
		nb = va_arg(pft->ap, double);
	if (nb < 0)			// False in doubles (cases -0 +0)
		*sign = -1;
	else
		*sign = 1;
	return (nb);
}
