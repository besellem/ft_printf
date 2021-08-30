/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:47:01 by besellem          #+#    #+#             */
/*   Updated: 2021/08/30 18:41:59 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	int_get_width(t_pft *pft, const t_int64 nb, const int nb_len)
{
	int	width;

	width = -1;
	if (pft->conversion.width >= 0)
		width = pft->conversion.width - nb_len - (nb < 0);
	if (pft->conversion.precision >= 0)
		width -= pft->conversion.precision;
	return (width);
}

void	conv_d(t_pft *pft)
{
	char			sign;
	const intmax_t	nb = ft_get_val_int(pft, &sign);
	const int		nb_len = ft_nblen_base(nb, 10);
	int				width;

	width = int_get_width(pft, nb, nb_len);
	if (!(pft->conversion.flags & FLAG_MINUS))
		while (width-- > 0)
			pft->write2buf(pft, " ");
	if (nb < 0)
		pft->write2buf(pft, "-");
	while (pft->conversion.precision > nb_len)
	{
		pft->write2buf(pft, "0");
		--pft->conversion.precision;
	}
	if (!(nb == 0 && pft->conversion.precision == 0))
		ft_put_int(pft, nb, DEC_CHARSET);
	if (pft->conversion.flags & FLAG_MINUS)
		while (width-- > 0)
			pft->write2buf(pft, " ");
}
