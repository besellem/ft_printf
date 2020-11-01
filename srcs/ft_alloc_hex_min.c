/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_hex_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:23:26 by besellem          #+#    #+#             */
/*   Updated: 2020/11/01 13:24:01 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_alloc_hex_min(t_data **s, t_indicators table, va_list ap)
{
	char *data;
	char *base;

	base = "0123456789abcdef";
	if (table.dot >= 0)
		data = prec_padding(va_arg(ap, unsigned int), table.dot, base);
	else
		data = convert_base(va_arg(ap, unsigned int), base);
	if (data)
		ft_lstd_add(s, ft_lstd_new(data, ft_strlen(data)));
	free(data);
}
