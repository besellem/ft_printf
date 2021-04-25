/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:48:37 by besellem          #+#    #+#             */
/*   Updated: 2021/04/25 22:32:41 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	conv_x_min(t_pft *pft)
{
	const t_uint64	nb = ft_get_val_uint(pft);

	ft_put_uint(pft, nb, "0123456789abcdef");
}

void	conv_x_max(t_pft *pft)
{
	const t_uint64	nb = ft_get_val_uint(pft);

	ft_put_uint(pft, nb, "0123456789ABCDEF");
}
