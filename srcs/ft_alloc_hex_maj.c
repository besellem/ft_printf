/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_hex_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:23:35 by besellem          #+#    #+#             */
/*   Updated: 2020/10/27 17:18:46 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_alloc_hex_maj(t_data **s, t_indicators table, va_list ap)
{
	char *data;
	char *base;

	base = "0123456789ABCDEF";
	if (table.dot >= 0)
		data = zero_padding(va_arg(ap, unsigned int), table.dot, base);
	else
		data = convert_base(va_arg(ap, unsigned int), base);
	if (data)
		ft_lstd_add(s, ft_lstd_new(data, ft_strlen(data)));
	free(data);
}
