/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 02:42:55 by besellem          #+#    #+#             */
/*   Updated: 2020/11/13 00:02:34 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_round_str(char *prec, int precision)
{
	if (precision > 0 && prec[precision] == '9')
	{
		prec[precision] = '0';
		if (precision == 1 || (precision == 1 && prec[precision] >= '5'))
			return (1);
		return (ft_round_str(prec, precision - 1));
	}
	else
	{
		prec[precision]++;
		return (0);
	}
}

int			f_prec(char **ret, long double n, int precision, int sign)
{
	char	*data;
	int		i;

	n = (sign ? -n : n) - (long long)n;
	i = (long long)(n * 10) - (((long long)n % 10) * 10) >= 5 ? 1 : 0;
	if (precision == 0)
		return (!i && sign ? 1 : i);
	if (!(data = (char *)ft_calloc(precision + 2, sizeof(char))))
		return (0);
	i = -1;
	data[++i] = '.';
	while (i < precision)
	{
		n = (n * 10) - (((long long)n % 10) * 10);
		data[++i] = (long long)n % 10 + 48;
	}
	data[++i] = '\0';
	i = 0;
	if (((long long)((n * 10) - (((long long)n % 10) * 10)) % 10) >= 5)
		i = ft_round_str(data, precision);
	*ret = data;
	return (i);
}

char		*convert_f(long double n, int prec, int htag)
{
	char	*data;
	char	*nbr;
	char	*pr;
	int		len;
	int		sign;

	pr = NULL;
	sign = n == 0. ? ft_signbit_f(n) : (n < 0);
	prec = prec < 0 ? 6 : prec;
	n += sign ? -f_prec(&pr, n, prec, sign) : f_prec(&pr, n, prec, sign);
	nbr = conv_f((long long)n, sign);
	len = ft_strlen(nbr) + prec + (prec == 0 && htag ? 1 : 0);
	if (!(data = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_strcat(data, nbr);
	if (prec == 0 && htag)
		ft_strcat(data, ".");
	if (pr)
		ft_strcat(data, pr);
	ft_free(2, nbr, pr);
	return (data);
}

long double	f_spec(t_indicators *t, va_list ap)
{
	long double n;

	if (t->lf)
		n = va_arg(ap, long double);
	else
		n = (double)va_arg(ap, double);
	return (n);
}

void		ft_alloc_f(t_data **s, t_indicators t, va_list ap)
{
	char		*data;
	long double	n;

	n = f_spec(&t, ap);
	data = convert_f(n, t.dot, t.htag);
	add_lstd(s, data);
	ft_free(1, data);
}
