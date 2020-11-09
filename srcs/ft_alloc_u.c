/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:58:37 by besellem          #+#    #+#             */
/*   Updated: 2020/11/09 02:38:37 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_check_indic_u(t_ullong nbr, t_indicators t, char *base)
{
	char *data;

	if (t.dot >= 0)
		data = prec_padding(nbr, t.dot, base);
	else if (t.zero > 0)
		data = zero_padding(nbr, t.zero - (nbr > 0 && t.plus ? 1 : 0), base);
	else
		data = convert_base_u(nbr, base);
	return (data);
}

t_ullong	u_spec(t_indicators *t, va_list ap)
{
	unsigned long long n;

	if (t->is_specifier == 1 && t->hh)
		n = (unsigned char)va_arg(ap, unsigned int);
	else if (t->is_specifier == 1 && t->h)
		n = (unsigned short)va_arg(ap, unsigned int);
	else if (t->is_specifier == 1 && t->l)
		n = (unsigned long)va_arg(ap, unsigned long);
	else if (t->is_specifier == 1 && t->ll)
		n = va_arg(ap, unsigned long long);
	else
		n = va_arg(ap, unsigned int);
	return (n);
}

void		ft_alloc_u(t_data **s, t_indicators t, va_list ap)
{
	unsigned long long	n;
	char				*data;
	char				*sp;

	n = u_spec(&t, ap);
	data = ft_check_indic_u(n, t, "0123456789");
	sp = NULL;
	if ((t.dot >= 0 && t.zero >= 0) || t.width >= 0)
		sp = space_padding(data, t.width >= 0 ? t.width : t.zero);
	(t.minus == -1) ? add_lstd(s, sp) : 0;
	data ? add_lstd(s, data) : 0;
	(t.minus == 1) ? add_lstd(s, sp) : 0;
	ft_free(2, sp, data);
}
