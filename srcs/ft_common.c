/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 01:11:34 by besellem          #+#    #+#             */
/*   Updated: 2020/10/27 00:10:16 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_len_base(long long n, int base)
{
	long long	i;
	int			len;

	n = n < 0 ? -n : n;
	len = 1;
	i = base;
	while (n / i > 0)
	{
		i *= base;
		++len;
	}
	return (len);
}

void	ft_free(size_t nb, ...)
{
	va_list	ap;
	void	*ptr;

	va_start(ap, nb);
	while (nb-- > 0)
	{
		ptr = va_arg(ap, void *);
		free(ptr);
	}
	va_end(ap);
}

char	*convert_base(long long n, char *base)
{
	char		*data;
	long long	div;
	int			i;
	int			len;

	len = ft_len_base(n, ft_strlen(base)) + (n < 0 ? 1 : 0) + 1;
	if (!(data = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	len = ft_strlen(base);
	i = -1;
	if (n < 0 && (n = -n))
		data[++i] = '-';
	div = 1;
	while (n / div >= len)
		div *= len;
	while (div > 0)
	{
		data[++i] = base[n / div % len];
		div /= len;
	}
	data[++i] = '\0';
	return (data);
}
