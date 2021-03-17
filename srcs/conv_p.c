/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:48:33 by besellem          #+#    #+#             */
/*   Updated: 2021/03/17 23:53:43 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_p(t_pft *pft)
{
	const t_uint64	nb = va_arg(pft->ap, unsigned long);

	write2buf_str(pft, "0x");
	ft_put_uint(pft, nb, "0123456789abcdef");
}
