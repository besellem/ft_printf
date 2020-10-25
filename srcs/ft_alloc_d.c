/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:45:02 by besellem          #+#    #+#             */
/*   Updated: 2020/10/25 19:45:20 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	nblen(long long n)
{
	long long	i;
	int			len;

	n = n < 0 ? -n : n;
	len = 1;
	i = 10;
	while (n / i > 0)
	{
		i *= 10;
		++len;
	}
	return (len);
}

static char	*convert_nb(long long ptr)
{
	char		*data;
	long long	div;
	int			i;

	if (!(data = (char *)malloc(nblen(ptr) + 1 + (ptr < 0 ? 1 : 0))))
		return (NULL);
	i = -1;
	if (ptr < 0 && (ptr = -ptr))
		data[++i] = '-';
	div = 1;
	while (ptr / div >= 10)
		div *= 10;
	while (div > 0)
	{
		data[++i] = (ptr / div) % 10 + 48;
		div /= 10;
	}
	data[++i] = '\0';
	return (data);
}

void		ft_alloc_d(t_data **s, t_indicators table, va_list ap)
{
	char *data;

	data = convert_nb(va_arg(ap, int));
	ft_lstd_add(s, ft_lstd_new(data, ft_len(data)));
}
