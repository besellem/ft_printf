/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:12:41 by besellem          #+#    #+#             */
/*   Updated: 2021/09/01 17:18:08 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	__init_int_padding__(t_pft *pft, t_padding *pad, intmax_t val)
{
	if (*pad->_pre_char == 0 && pad->_sign < 0)
		ft_strncpy(pad->_pre_char, "-", 1);
	else if (*pad->_pre_char == 0 && isflag(pft, FLAG_PLUS))
		ft_strncpy(pad->_pre_char, "+", 1);
	else if (*pad->_pre_char == 0 && isflag(pft, FLAG_SPACE))
		ft_strncpy(pad->_pre_char, " ", 1);
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

void	__init_uint_padding__(t_pft *pft, t_padding *pad, uintmax_t val)
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
