/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:45:02 by besellem          #+#    #+#             */
/*   Updated: 2020/10/27 17:14:10 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_alloc_d(t_data **s, t_indicators table, va_list ap)
{
	char *data;

	if (table.dot >= 0)
		data = zero_padding(va_arg(ap, int), table.dot, "0123456789");
	else
		data = convert_base(va_arg(ap, int), "0123456789");
	if (data)
		ft_lstd_add(s, ft_lstd_new(data, ft_strlen(data)));
	free(data);
}
