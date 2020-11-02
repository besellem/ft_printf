/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:20:39 by besellem          #+#    #+#             */
/*   Updated: 2020/11/02 11:09:27 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*convert_p(long long ptr)
{
	char		*data;
	char		*hex;
	long long	div;
	int			i;

	div = 16;
	hex = "0123456789abcdef";
	while (ptr / div >= 16)
		div *= 16;
	if (!(data = (char *)malloc(sizeof(char) * (ft_len_base(ptr, 16) + 3))))
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

void		ft_alloc_p(t_data **s, t_indicators t, va_list ap)
{
	char			*data;
	char			*sp;
	unsigned long	tmp;

	tmp = va_arg(ap, unsigned long);
	data = tmp ? convert_p(tmp) : ft_strdup("0x0");
	sp = NULL;
	if ((t.dot >= 0 && t.zero >= 0) || t.width >= 0)
		sp = space_padding(data, t.width >= 0 ? t.width : t.zero);
	(t.minus == -1) ? add_lstd(s, sp) : 0;
	data ? add_lstd(s, data) : 0;
	(t.minus == 1) ? add_lstd(s, sp) : 0;
	ft_free(2, sp, data);
}
