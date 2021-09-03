/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:43:49 by besellem          #+#    #+#             */
/*   Updated: 2021/09/03 02:11:18 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	__cut_precision__(t_pft *pft, char *pad, int *padding)
{
	const size_t	_len = ft_strlen(pad);
	size_t			_new_len;
	size_t			i;

	i = _len;
	while (i-- > 0)
	{
		if (pad[i] == '0')
			pad[i] = '\0';
		else
			break ;
	}
	if (-1 != pft->conversion.precision && pft->conversion.precision < (int)_len)
		pad[pft->conversion.precision] = '\0';
	_new_len = ft_strlen(pad);
	*padding += _new_len;
	pft->write2buf_s(pft, pad);
	print_char(pft, '0', ft_fdim(pft->conversion.precision, _new_len));
	ft_memdel((void **)&pad);
}

void	conv_a(t_pft *pft)
{
	int				exp;
	double			nb;
	unsigned long	mant;
	int				padding;

	nb = ft_get_val_float(pft);
	if (ft_print_special_fp(pft, nb))
		return ;
	ft_frexp(nb, &exp);
	// padding = 5 + ft_signbit(nb) + (0 != (((*(unsigned long *)&nb << 12) >> 12) || isflag(pft, FLAG_HTAG))) + ft_nblen(exp - 1);
	// if (-1 == pft->conversion.precision)
	// 	pft->conversion.precision = 6;
	if (ft_signbit(nb))
		pft->write2buf_s(pft, "-");
	else
	{
		if (isflag(pft, FLAG_PLUS))
			pft->write2buf_s(pft, "+");
		else if (isflag(pft, FLAG_SPACE))
			pft->write2buf_s(pft, " ");
	}
	pft->write2buf_s(pft, "0x");
	ft_put_int(pft, 1, HEX_CHARSET); // false with rounding
	nb = ft_copysign(nb, 0.);
	mant = (*(unsigned long *)&nb << 12) >> 12;
	if (mant || isflag(pft, FLAG_HTAG))
		pft->write2buf_s(pft, ".");
	__cut_precision__(pft, ft_itoa_base(mant, HEX_CHARSET), &padding);
	pft->write2buf_s(pft, "p");
	if ((exp - 1) < 0)
		pft->write2buf_s(pft, "-");
	else
		pft->write2buf_s(pft, "+");
	ft_put_int(pft, exp - 1, DEC_CHARSET);
}