/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:48:35 by besellem          #+#    #+#             */
/*   Updated: 2021/09/01 17:23:54 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	conv_u(t_pft *pft)
{
	const uintmax_t	nb = ft_get_val_uint(pft);
	t_padding		pad;

	ft_bzero(&pad, sizeof(pad));
	pad._len = ft_uint_base(nb, 10);
	pad._sign = POS;
	__init_uint_padding__(pft, &pad, nb);
	if (pad._width > 0 && !isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width);
	if (pad._prec > 0)
		print_char(pft, '0', pad._prec);
	if (!(nb == 0 && pft->conversion.precision == 0))
		ft_put_uint(pft, nb, DEC_CHARSET);
	if (pad._width > 0 && isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width);
}
