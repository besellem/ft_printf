/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 14:56:09 by besellem          #+#    #+#             */
/*   Updated: 2021/08/30 21:44:45 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	conv_f(t_pft *pft)
{
	const double	nb = ft_get_val_float(pft);

	if (-1 == pft->conversion.precision)
		pft->conversion.precision = 6;
	if (ft_signbit(nb))
		write2buf_str(pft, "-");
	ft_put_float(pft, nb, DEC_CHARSET);
}
