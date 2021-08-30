/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:48:31 by besellem          #+#    #+#             */
/*   Updated: 2021/08/30 13:41:31 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	conv_o(t_pft *pft)
{
	const uintmax_t	nb = ft_get_val_uint(pft);

	ft_put_uint(pft, nb, "01234567");
}
