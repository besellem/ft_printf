/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:48:24 by besellem          #+#    #+#             */
/*   Updated: 2021/09/01 16:29:23 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	conv_c(t_pft *pft)
{
	const int	nb = (unsigned char)va_arg(pft->ap, int);
	const int	pad_left = isflag(pft, FLAG_MINUS);

	if (pft->conversion.width > 0 && !pad_left)
		print_char(pft, ' ', pft->conversion.width - 1);
	pft->write2buf(pft, (char [1]){nb});
	if (pft->conversion.width > 0 && pad_left)
		print_char(pft, ' ', pft->conversion.width - 1);
}
