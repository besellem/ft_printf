/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:37:44 by besellem          #+#    #+#             */
/*   Updated: 2020/11/01 23:51:10 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_alloc_c(t_data **s, t_indicators t, va_list ap)
{
	char data[2];
	char *sp;

	data[0] = va_arg(ap, int);
	data[1] = '\0';
	sp = NULL;
	if ((t.dot >= 0 && t.zero >= 0) || t.width >= 0)
		sp = space_padding(data, t.width >= 0 ? t.width : t.zero);
	(t.minus == -1) ? add_lstd(s, sp) : 0;
	add_lstd(s, data);
	(t.minus == 1) ? add_lstd(s, sp) : 0;
	ft_free(1, sp);
}
