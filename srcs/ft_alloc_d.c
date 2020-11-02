/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:45:02 by besellem          #+#    #+#             */
/*   Updated: 2020/11/02 18:06:58 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_check_indic_d(long long nbr, t_indicators t, char *base)
{
	char *data;

	if (t.dot >= 0)
		data = prec_padding(nbr, t.dot, base);
	else if (t.zero > 0)
		data = zero_padding(nbr, t.zero, base);
	else
		data = convert_base(nbr, base);
	return (data);
}

void	ft_alloc_d(t_data **s, t_indicators t, va_list ap)
{
	char *data;
	char *sp;

	data = ft_check_indic_d(va_arg(ap, int), t, "0123456789");
	sp = NULL;
	if ((t.dot >= 0 && t.zero >= 0) || t.width >= 0)
		sp = space_padding(data, t.width >= 0 ? t.width : t.zero);
	(t.minus == -1) ? add_lstd(s, sp) : 0;
	data ? add_lstd(s, data) : 0;
	(t.minus == 1) ? add_lstd(s, sp) : 0;
	ft_free(2, sp, data);
}
