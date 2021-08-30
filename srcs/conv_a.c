/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:43:49 by besellem          #+#    #+#             */
/*   Updated: 2021/08/30 19:00:28 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	conv_a(t_pft *pft)
{
	int				exp;
	const double	nb = ft_get_val_float(pft);
	const double	x = frexp(nb, &exp);

	if (-1 == pft->conversion.precision)
		pft->conversion.precision = 6;
	if (ft_signbit(nb))
		write2buf_str(pft, "-");
	write2buf_str(pft, "0x");
	ft_put_float(pft, x, HEX_CHARSET);
	write2buf_str(pft, "p");
	if (exp >= 0)
		write2buf_str(pft, "+");
	ft_put_int(pft, exp, DEC_CHARSET);
}
