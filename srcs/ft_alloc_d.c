/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:45:02 by besellem          #+#    #+#             */
/*   Updated: 2020/11/12 22:14:53 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	d_spec(t_indicators *t, va_list ap)
{
	long long n;

	if (t->hh)
		n = (char)va_arg(ap, int);
	else if (t->h)
		n = (short)va_arg(ap, int);
	else if (t->l)
		n = (long)va_arg(ap, long);
	else if (t->ll)
		n = va_arg(ap, long long);
	else
		n = va_arg(ap, int);
	return (n);
}

void		ft_alloc_d(t_data **s, t_indicators t, va_list ap)
{
	char		*data;
	long long	n;

	n = d_spec(&t, ap);
	data = conv_d(t, (n < 0 ? -n : n), (n < 0 ? 1 : 0), "0123456789");
	add_lstd(s, data);
	ft_free(1, data);
}
