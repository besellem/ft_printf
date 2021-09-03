/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 14:56:09 by besellem          #+#    #+#             */
/*   Updated: 2021/09/03 18:30:19 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	__special_fp__(t_pft *pft, double nb)
{
	if (ft_isnan(nb))
		pft->write2buf_s(pft, "nan");
	else if (ft_isinf(nb))
		pft->write2buf_s(pft, "inf");
	else
		return (FALSE);
	return (TRUE);
}

void	conv_f(t_pft *pft)
{
	const double	nb = ft_get_val_float(pft);
	const int		_is_special = ft_isnan(nb) || ft_isinf(nb);
	t_padding		pad;

	ft_bzero(&pad, sizeof(pad));
	if (-1 == pft->conversion.precision && !_is_special)
		pft->conversion.precision = 6;
	if (_is_special)
		pad._len = 3;
	else
		pad._len = ft_dbl_base(pft, nb, 10);
	pad._sign = (int)ft_copysign(1., nb);
	__dbl_padding__(pft, &pad, nb, _is_special);
	if (pad._width > 0 && !isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width);
	if (!ft_isnan(nb) && pad._pre != 0)
		pft->write2buf_s(pft, pad._pre_char);
	if (!_is_special && pad._prec > 0)
		print_char(pft, '0', pad._prec);
	if (!__special_fp__(pft, nb))
		ft_put_float(pft, nb, DEC_CHARSET);
	if (pad._width > 0 && isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width);
}
