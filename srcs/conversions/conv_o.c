/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:48:31 by besellem          #+#    #+#             */
/*   Updated: 2021/09/03 19:14:32 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	conv_o(t_pft *pft)
{
	const uintmax_t	nb = ft_get_val_uint(pft);
	t_padding		pad;

	ft_bzero(&pad, sizeof(pad));
	pad._len = ft_uint_base(nb, 8);
	pad._sign = POS;
	if (nb != 0 && isflag(pft, FLAG_HTAG))
		ft_memcpy(pad._pre_char, "0", 1);
	__uint_padding__(pft, &pad, nb);
	if (pad._width > 0 && !isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width - (isflag(pft, FLAG_HTAG) && 0 == nb));
	if (pad._pre != 0 && pad._prec <= 0)
		pft->write2buf_s(pft, pad._pre_char);
	if (pad._prec > 0)
		print_char(pft, '0', pad._prec);
	if (!(0 == nb && 0 == pft->conversion.precision) || isflag(pft, FLAG_HTAG))
		ft_put_uint(pft, nb, OCT_CHARSET);
	if (pad._width > 0 && isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width - (isflag(pft, FLAG_HTAG) && 0 == nb));
}

void	conv_o_max(t_pft *pft)
{
	const uint16_t	_spec = pft->conversion.specifiers;

	if (0 == (_spec & SPEC_L) && 0 == (_spec & SPEC_LL))
		pft->conversion.specifiers = IS_SPEC | SPEC_L;
	conv_o(pft);
}
