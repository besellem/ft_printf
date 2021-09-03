/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:12:41 by besellem          #+#    #+#             */
/*   Updated: 2021/09/03 17:45:46 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	__int_padding__(t_pft *pft, t_padding *pad, intmax_t val)
{
	if (0 == *pad->_pre_char && pad->_sign < 0)
		ft_memcpy(pad->_pre_char, "-", 1);
	else if (0 == *pad->_pre_char && isflag(pft, FLAG_PLUS))
		ft_memcpy(pad->_pre_char, "+", 1);
	else if (0 == *pad->_pre_char && isflag(pft, FLAG_SPACE))
		ft_memcpy(pad->_pre_char, " ", 1);
	pad->_pre = ft_strlen(pad->_pre_char);
	pad->_prec = (int)ft_fdim(pft->conversion.precision - pad->_len, 0);
	if (pft->conversion.precision >= pft->conversion.width)
		pad->_width = -1;
	else
	{
		pad->_width = (0 == val && 0 == pft->conversion.precision) - pad->_len;
		pad->_width += pft->conversion.width - pad->_pre - pad->_prec;
	}
	if (pft->conversion.precision < 0 && pad->_width > 0
		&& !isflag(pft, FLAG_MINUS) && isflag(pft, FLAG_ZERO))
	{
		pad->_prec = pad->_width;
		pad->_width = 0;
	}
}

void	__uint_padding__(t_pft *pft, t_padding *pad, uintmax_t val)
{
	pad->_pre = ft_strlen(pad->_pre_char);
	pad->_prec = (int)ft_fdim(pft->conversion.precision - pad->_len, 0);
	if (pft->conversion.precision >= pft->conversion.width)
		pad->_width = -1;
	else
	{
		pad->_width = (0 == val && 0 == pft->conversion.precision) - pad->_len;
		pad->_width += pft->conversion.width - pad->_pre - pad->_prec;
	}
	if (pft->conversion.precision < 0 && pad->_width > 0
		&& !isflag(pft, FLAG_MINUS) && isflag(pft, FLAG_ZERO))
	{
		pad->_prec = pad->_width;
		pad->_width = 0;
	}
}

void	__dbl_padding__(t_pft *pft, t_padding *pad, double val, int is_special)
{
	if (0 == *pad->_pre_char && pad->_sign < 0 && !ft_isnan(val))
		ft_memcpy(pad->_pre_char, "-", 1);
	else if (0 == *pad->_pre_char && isflag(pft, FLAG_PLUS))
		ft_memcpy(pad->_pre_char, "+", 1);
	else if (0 == *pad->_pre_char && isflag(pft, FLAG_SPACE))
		ft_memcpy(pad->_pre_char, " ", 1);
	pad->_pre = ft_strlen(pad->_pre_char);
	pad->_prec = (int)ft_fdim(pft->conversion.precision - pad->_len, 0);
	if (pft->conversion.precision >= pft->conversion.width)
		pad->_width = -1;
	else
	{
		pad->_width = pft->conversion.width;
		pad->_width -= (pad->_pre * !ft_isnan(val) + pad->_prec * !is_special);
		pad->_width -= pad->_len;
	}
	if ((pft->conversion.precision - 1) <= 0 && pad->_width > 0
		&& !isflag(pft, FLAG_MINUS) && isflag(pft, FLAG_ZERO) && !is_special)
	{
		pad->_prec = pad->_width;
		pad->_width = 0;
	}
}
