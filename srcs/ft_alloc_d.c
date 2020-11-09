/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:45:02 by besellem          #+#    #+#             */
/*   Updated: 2020/11/09 02:13:47 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_check_indic_d(long long nbr, t_indicators t, char *base)
{
	char *data;

	if (t.dot >= 0)
		data = prec_padding(nbr, t.dot, base);
	else if (t.zero > 0)
		data = zero_padding(nbr, t.zero - (nbr > 0 && t.plus ? 1 : 0), base);
	else
		data = convert_base(nbr, base);
	return (data);
}

/*
void		conv_decimal(t_data **s, char *data, char *pre, t_indicators t)
{
	char	*z;
	char	*sp;
	int		tmp;

	z = NULL;
	if (t.dot >= 0)
	{
		tmp = (int)ft_strlen(data) > t.dot ? 0 : t.dot - ft_strlen(data);
		z = ft_malloc_c(tmp, '0');
	}
	else if (t.zero > 0)
	{
		tmp = nbr < 0 ? 1 : 0;
		tmp = t.zero - tmp > (int)ft_strlen(tmp) ? t.zero - tmp - ft_strlen(tmp) : 0;
		tmp = (int)ft_strlen(data) > t.dot ? 0 : t.dot - ft_strlen(data);
		z = ft_malloc_c(tmp, '0');
	}
	add_lstd(s, pre);
	add_lstd(s, z);
	add_lstd(s, data);
	ft_free(3, data, pre, z);
}
*/

long long	d_spec(t_indicators *t, va_list ap)
{
	long long n;

	if (t->is_specifier == 1 && t->hh)
		n = (char)va_arg(ap, int);
	else if (t->is_specifier == 1 && t->h)
		n = (short)va_arg(ap, int);
	else if (t->is_specifier == 1 && t->l)
		n = (long)va_arg(ap, long);
	else if (t->is_specifier == 1 && t->ll)
		n = va_arg(ap, long long);
	else
		n = va_arg(ap, int);
	return (n);
}

void		ft_alloc_d(t_data **s, t_indicators t, va_list ap)
{
	long long	n;
	char		*data;
	char		*sp;

	n = d_spec(&t, ap);
	data = ft_check_indic_d(n, t, "0123456789");
	sp = NULL;
	if ((t.dot >= 0 && t.zero >= 0) || t.width >= 0)
		sp = space_padding(data, t.width >= 0 ? t.width : t.zero);
	(t.minus == -1) ? add_lstd(s, sp) : 0;
	if (t.space == 1 && n > 0)
		add_lstd(s, " ");
	else if (t.plus == 1 && n > 0)
		add_lstd(s, "+");
	data ? add_lstd(s, data) : 0;
	(t.minus == 1) ? add_lstd(s, sp) : 0;
	ft_free(2, sp, data);
}
