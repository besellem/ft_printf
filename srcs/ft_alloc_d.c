/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:45:02 by besellem          #+#    #+#             */
/*   Updated: 2020/11/15 12:02:06 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_alloc_d(t_data **s, t_indicators t, va_list ap)
{
	char		*data;
	long long	n;

	n = d_spec(&t, ap);
	data = conv_d(t, (n < 0 ? -n : n), (n < 0 ? 1 : 0), "0123456789");
	add_lstd(s, data);
	ft_free(1, data);
}
