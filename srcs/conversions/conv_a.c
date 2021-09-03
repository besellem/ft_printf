/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:43:49 by besellem          #+#    #+#             */
/*   Updated: 2021/09/03 18:45:07 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	__cut_precision__(t_pft *pft, char *pad, int *padding)
{
	const int		_prec = pft->conversion.precision;
	const size_t	_len = ft_strlen(pad);
	size_t			_new_len;
	size_t			i;

	i = _len - 1;
	while (i >= 0 && pad[i] == '0')
		pad[i--] = '\0';
	if (-1 != _prec && _prec < (int)_len)
		pad[_prec] = '\0';
	_new_len = ft_strlen(pad);
	*padding += _new_len;
	pft->write2buf_s(pft, pad);
	print_char(pft, '0', ft_fdim(_prec, _new_len));
	ft_memdel((void **)&pad);
}

static void	conv_a(t_pft *pft, const char *hex_prec, const char *charset,
	char prec_char)
{
	int				exp;
	double			nb;
	unsigned long	mant;
	int				padding;

	nb = ft_get_val_float(pft);
	if (ft_print_special_fp(pft, nb))
		return ;
	ft_frexp(nb, &exp);
	if (ft_signbit(nb))
		pft->write2buf_s(pft, "-");
	else
		pft->write2buf_s(pft, ft_trns(isflag(pft, FLAG_PLUS), "+",
			ft_trns(isflag(pft, FLAG_SPACE), " ", NULL)));
	pft->write2buf_s(pft, hex_prec);
	ft_put_int(pft, 1, charset);
	nb = ft_copysign(nb, 0.);
	mant = (*(unsigned long *)&nb << 12) >> 12;
	if (mant || isflag(pft, FLAG_HTAG))
		pft->write2buf_s(pft, ".");
	__cut_precision__(pft, ft_itoa_base(mant, (char *)charset), &padding);
	pft->write2buf(pft, &prec_char);
	pft->write2buf_s(pft, ft_trns((exp - 1) < 0, "-", "+"));
	ft_put_int(pft, exp - 1, DEC_CHARSET);
}

void	conv_a_min(t_pft *pft)
{
	conv_a(pft, "0x", HEX_CHARSET, 'p');
}

void	conv_a_max(t_pft *pft)
{
	conv_a(pft, "0X", HEX_CHARSET_UP, 'P');
}
