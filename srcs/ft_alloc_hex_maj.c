/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_hex_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:23:35 by besellem          #+#    #+#             */
/*   Updated: 2020/11/09 02:31:59 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_alloc_hex_maj(t_data **s, t_indicators t, va_list ap)
{
	unsigned long long	n;
	char				*data;
	char				*sp;

	n = u_spec(&t, ap);
	data = ft_check_indic_u(n, t, "0123456789ABCDEF");
	sp = NULL;
	if ((t.dot >= 0 && t.zero >= 0) || t.width >= 0)
		sp = space_padding(data, t.width >= 0 ? t.width : t.zero);
	(t.minus == -1) ? add_lstd(s, sp) : 0;
	data ? add_lstd(s, data) : 0;
	(t.minus == 1) ? add_lstd(s, sp) : 0;
	ft_free(2, sp, data);
}
