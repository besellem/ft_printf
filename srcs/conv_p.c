/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:48:33 by besellem          #+#    #+#             */
/*   Updated: 2021/08/31 00:44:02 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	conv_p(t_pft *pft)
{
	const uintptr_t	nb = va_arg(pft->ap, uintptr_t);

	if (0 == nb)
		return (write2buf_str(pft, PFT_NULL_PTR));
	write2buf_str(pft, "0x");
	ft_put_uint(pft, nb, HEX_CHARSET);
}
