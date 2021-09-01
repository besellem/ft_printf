/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:47:01 by besellem          #+#    #+#             */
/*   Updated: 2021/09/01 02:03:17 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

typedef struct s_padding
{
	char	_pre_char[3];
	int		_sign;
	int		_len;
	int		_pre;
	int		_width;
	int		_prec;
}				t_padding;

static void	__init_padding__(t_pft *pft, t_padding *pad, intmax_t val)
{
	if (*pad->_pre_char == 0 && pad->_sign < 0)
		ft_strncpy(pad->_pre_char, "-", 1);
	else if (*pad->_pre_char == 0 && isflag(pft, FLAG_PLUS))
		ft_strncpy(pad->_pre_char, "+", 1);
	else if (*pad->_pre_char == 0 && isflag(pft, FLAG_SPACE))
		ft_strncpy(pad->_pre_char, " ", 1);
	pad->_pre = (*pad->_pre_char != 0);
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
	printf("zero_flag[%d], sign[%d], len[%d], pre[%d], width[%d] precision[%d]\n",
		isflag(pft, FLAG_ZERO), pad->_sign, pad->_len, pad->_pre, pad->_width, pad->_prec);
}

void	conv_d(t_pft *pft)
{
	char			sign;
	const intmax_t	nb = ft_get_val_int(pft, &sign);
	t_padding		pad;

	ft_bzero(&pad, sizeof(pad));
	pad._len = ft_nblen_base(nb, 10);
	pad._sign = sign;
	__init_padding__(pft, &pad, nb);
	if (pad._width > 0 && !isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width);
	if (pad._pre != 0)
		write2buf_str(pft, pad._pre_char);
	if (pad._prec > 0)
		print_char(pft, '0', pad._prec);
	if (!(nb == 0 && pft->conversion.precision == 0))
		ft_put_int(pft, nb, DEC_CHARSET);
	if (pad._width > 0 && isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', pad._width);
}
