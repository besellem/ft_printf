/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_hex_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:23:26 by besellem          #+#    #+#             */
/*   Updated: 2020/11/01 23:51:25 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_alloc_hex_min(t_data **s, t_indicators t, va_list ap)
{
	char *data;
	char *sp;

	data = ft_check_indic_d(va_arg(ap, unsigned int), t, "0123456789abcdef");
	sp = NULL;
	if ((t.dot >= 0 && t.zero >= 0) || t.width >= 0)
		sp = space_padding(data, t.width >= 0 ? t.width : t.zero);
	(t.minus == -1) ? add_lstd(s, sp) : 0;
	data ? add_lstd(s, data) : 0;
	(t.minus == 1) ? add_lstd(s, sp) : 0;
	ft_free(2, sp, data);
}
