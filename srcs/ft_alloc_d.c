/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:45:02 by besellem          #+#    #+#             */
/*   Updated: 2020/11/01 15:48:21 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_alloc_d(t_data **s, t_indicators table, va_list ap)
{
	char *data;
	char *spaces;
	char *base;

	base = "0123456789";
	if (table.dot >= 0)
		data = prec_padding(va_arg(ap, int), table.dot, base);
	else if (table.zero > 0)
		data = zero_padding(va_arg(ap, int), table.zero, base);
	else
		data = convert_base(va_arg(ap, int), base);
	if (data)
	{
		if (table.dot >= 0 && table.zero >= 0 &&
		(spaces = space_padding(data, table.zero, base)))
		{
			ft_lstd_add(s, ft_lstd_new(spaces, ft_strlen(spaces)));
			free(spaces);
		}
		ft_lstd_add(s, ft_lstd_new(data, ft_strlen(data)));
	}
	free(data);
}
