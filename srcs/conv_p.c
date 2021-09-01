/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:48:33 by besellem          #+#    #+#             */
/*   Updated: 2021/09/01 19:25:51 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	conv_p(t_pft *pft)
{
	const uintptr_t	nb = va_arg(pft->ap, uintptr_t);
	t_padding		pad;

	ft_bzero(&pad, sizeof(pad));
	pad._len = ft_uint_base(nb, 16);
	pad._sign = POS;
	ft_strncpy(pad._pre_char, "0x", 2);
	__init_uint_padding__(pft, &pad, nb);
	if (pad._width > 0 && !isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width);
	write2buf_str(pft, pad._pre_char);
	if (pad._prec > 0)
		print_char(pft, '0', pad._prec);
	if (!(nb == 0 && pft->conversion.precision == 0))
		ft_put_uint(pft, nb, HEX_CHARSET);
	if (pad._width > 0 && isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width);
}
