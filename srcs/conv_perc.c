/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_perc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:27:47 by besellem          #+#    #+#             */
/*   Updated: 2021/09/02 16:41:23 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	conv_perc(t_pft *pft)
{
	t_padding	pad;

	ft_bzero(&pad, sizeof(pad));
	pad._len = 1;
	pad._sign = POS;
	pad._pre = 0;
	pft->conversion.flags &= ~FLAG_SPACE;
	__int_padding__(pft, &pad, 1);
	if (pad._width > 0 && !isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width);
	if (pad._prec > 0)
		print_char(pft, '0', pad._prec);
	pft->write2buf_s(pft, "%");
	if (pad._width > 0 && isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width);
}
