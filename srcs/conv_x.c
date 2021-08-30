/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:48:37 by besellem          #+#    #+#             */
/*   Updated: 2021/08/30 13:43:39 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	conv_x(t_pft *pft, const char *charset)
{
	const uintmax_t	nb = ft_get_val_uint(pft);

	ft_put_uint(pft, nb, charset);
}

void	conv_x_min(t_pft *pft)
{
	conv_x(pft, HEX_CHARSET);
}

void	conv_x_max(t_pft *pft)
{
	conv_x(pft, HEX_CHARSET_UP);
}
