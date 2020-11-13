/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:58:37 by besellem          #+#    #+#             */
/*   Updated: 2020/11/13 15:09:45 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_alloc_u(t_data **s, t_indicators t, va_list ap)
{
	char				*data;
	unsigned long long	n;

	n = u_spec(&t, ap);
	data = conv_d(t, n, 0, "0123456789");
	add_lstd(s, data);
	ft_free(1, data);
}
