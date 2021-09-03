/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:47:01 by besellem          #+#    #+#             */
/*   Updated: 2021/09/02 16:41:23 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	conv_d(t_pft *pft)
{
	char			sign;
	const intmax_t	nb = ft_get_val_int(pft, &sign);
	t_padding		pad;

	ft_bzero(&pad, sizeof(pad));
	pad._len = ft_nblen_base(nb, 10);
	pad._sign = sign;
	__int_padding__(pft, &pad, nb);
	if (pad._width > 0 && !isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width);
	if (pad._pre != 0)
		pft->write2buf_s(pft, pad._pre_char);
	if (pad._prec > 0)
		print_char(pft, '0', pad._prec);
	if (!(nb == 0 && pft->conversion.precision == 0))
		ft_put_int(pft, nb, DEC_CHARSET);
	if (pad._width > 0 && isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width);
}

void	conv_d_max(t_pft *pft)
{
	const uint16_t	_spec = pft->conversion.specifiers;

	if (0 == (_spec & SPEC_L) && 0 == (_spec & SPEC_LL))
		pft->conversion.specifiers = IS_SPEC | SPEC_L;
	conv_d(pft);
}
