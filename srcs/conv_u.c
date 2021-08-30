/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:48:35 by besellem          #+#    #+#             */
/*   Updated: 2021/08/30 18:41:46 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	conv_u(t_pft *pft)
{
	const uintmax_t	nb = ft_get_val_uint(pft);

	ft_put_uint(pft, nb, DEC_CHARSET);
}
