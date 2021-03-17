/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:47:01 by besellem          #+#    #+#             */
/*   Updated: 2021/03/17 23:56:12 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_d(t_pft *pft)
{
	char			sign;
	const t_int64	nb = ft_get_val_int(pft, &sign);

	if (nb < 0)
		pft->write2buf(pft, "-");
	while (pft->conversion.precision-- > 0)
		pft->write2buf(pft, "0");
	ft_put_int(pft, nb, "0123456789");
}
