/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:43:49 by besellem          #+#    #+#             */
/*   Updated: 2021/09/01 00:52:14 by besellem         ###   ########.fr       */
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
	write2buf_str(pft, pad);
	print_char(pft, '0', ft_fdim(pft->conversion.precision, _new_len));
	ft_memdel((void **)&pad);
}

void	conv_a(t_pft *pft)
{
	int				exp = 0;
	double			nb = ft_get_val_float(pft);
	unsigned long	mant;
	int				padding;

	if (ft_print_special_fp(pft, nb))
		return ;
	frexp(nb, &exp);
	// padding = 5 + ft_signbit(nb) + (0 != (((*(unsigned long *)&nb << 12) >> 12) || isflag(pft, FLAG_HTAG))) + ft_nblen(exp - 1);
	// if (-1 == pft->conversion.precision)
	// 	pft->conversion.precision = 6;
	if (ft_signbit(nb))
		write2buf_str(pft, "-");
	else
	{
		if (isflag(pft, FLAG_PLUS))
			write2buf_str(pft, "+");
		else if (isflag(pft, FLAG_SPACE))
			write2buf_str(pft, " ");
	}
	write2buf_str(pft, "0x");
	ft_put_int(pft, 1, HEX_CHARSET); // false with rounding
	nb = ft_copysign(nb, 0.);
	mant = (*(unsigned long *)&nb << 12) >> 12;
	if (mant || isflag(pft, FLAG_HTAG))
		write2buf_str(pft, ".");
	__cut_precision__(pft, ft_itoa_base(mant, HEX_CHARSET), &padding);
	write2buf_str(pft, "p");
	if ((exp - 1) < 0)
		write2buf_str(pft, "-");
	else
		write2buf_str(pft, "+");
	ft_put_int(pft, exp - 1, DEC_CHARSET);
}
