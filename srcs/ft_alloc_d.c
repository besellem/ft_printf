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

static char	*convert_nb(long long ptr)
{
	char		*data;
	long long	div;
	int			len;
	int			i;

	len = 1;
	div = 1;
	while (ptr / div >= 10)
	{
		div *= 10;
		++len;
	}
	if (!(data = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		data[i] = (ptr / div) % 10 + 48;
		div /= 10;
	}
	data[i] = '\0';
	return (data);
}

void		ft_alloc_d(t_data **s, t_indicators table, va_list ap)
{
	char *data;

	data = convert_nb(va_arg(ap, int));
	ft_lstd_add(s, ft_lstd_new(data, ft_len(data)));
}
