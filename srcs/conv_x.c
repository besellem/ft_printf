/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:48:37 by besellem          #+#    #+#             */
/*   Updated: 2021/09/02 16:41:23 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	conv_x(t_pft *pft, const char *prefix, const char *charset)
{
	const uintmax_t	nb = ft_get_val_uint(pft);
	t_padding		pad;

	ft_bzero(&pad, sizeof(pad));
	pad._len = ft_uint_base(nb, 16);
	pad._sign = POS;
	if (nb != 0 && isflag(pft, FLAG_HTAG))
		ft_memcpy(pad._pre_char, prefix, 2);
	__uint_padding__(pft, &pad, nb);
	if (pad._width > 0 && !isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width);
	if (pad._pre != 0)
		pft->write2buf_s(pft, pad._pre_char);
	if (pad._prec > 0)
		print_char(pft, '0', pad._prec);
	if (!(nb == 0 && pft->conversion.precision == 0))
		ft_put_uint(pft, nb, charset);
	if (pad._width > 0 && isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width);
}

void	conv_x_min(t_pft *pft)
{
	conv_x(pft, "0x", HEX_CHARSET);
}

void	conv_x_max(t_pft *pft)
{
	conv_x(pft, "0X", HEX_CHARSET_UP);
}
