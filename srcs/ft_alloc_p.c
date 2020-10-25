/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:20:39 by besellem          #+#    #+#             */
/*   Updated: 2020/10/25 16:20:40 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	nblen_base(long long n, int base)
{
	long long	i;
	int			len;

	len = 1;
	i = base;
	while (n / i > base)
	{
		i *= base;
		++len;
	}
	return (len);
}

static char	*convert_hex(long long ptr)
{
	char		*data;
	char		*hex;
	long long	div;
	int			i;

	div = 16;
	hex = "0123456789abcdef";
	while (ptr / div > 16)
		div *= 16;
	if (!(data = (char *)malloc(sizeof(char) * (nblen_base(ptr, 16) + 4))))
		return (NULL);
	i = -1;
	data[++i] = '0';
	data[++i] = 'x';
	while (div > 0)
	{
		data[++i] = hex[ptr / div % 16];
		div /= 16;
	}
	data[++i] = '\0';
	return (data);
}

void		ft_alloc_p(t_data **s, t_indicators table, va_list ap)
{
	char *data;

	data = convert_hex(va_arg(ap, unsigned long));
	ft_lstd_add(s, ft_lstd_new(data, ft_len(data)));
}
