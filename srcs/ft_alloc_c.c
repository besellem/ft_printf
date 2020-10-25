/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:37:44 by besellem          #+#    #+#             */
/*   Updated: 2020/10/25 19:37:46 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_alloc_c(t_data **s, t_indicators table, va_list ap)
{
	char data[2];

	data[0] = va_arg(ap, int);
	data[1] = '\0';
	ft_lstd_add(s, ft_lstd_new(data, 1));
}
