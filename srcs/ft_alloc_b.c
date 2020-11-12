/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:49:58 by besellem          #+#    #+#             */
/*   Updated: 2020/11/12 21:51:14 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_alloc_b(t_data **s, t_indicators t, va_list ap)
{
	char				*data;
	unsigned long long	n;

	n = u_spec(&t, ap);
	data = conv_d(t, n, 0, "01");
	add_lstd(s, data);
	ft_free(1, data);
}
