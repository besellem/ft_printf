/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:58:37 by besellem          #+#    #+#             */
/*   Updated: 2020/11/01 13:23:38 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_alloc_u(t_data **s, t_indicators table, va_list ap)
{
	char *data;

	if (table.dot >= 0)
		data = prec_padding(va_arg(ap, unsigned int), table.dot, "0123456789");
	else
		data = convert_base(va_arg(ap, unsigned int), "0123456789");
	if (data)
		ft_lstd_add(s, ft_lstd_new(data, ft_strlen(data)));
	free(data);
}
