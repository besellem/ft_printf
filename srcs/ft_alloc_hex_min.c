/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_hex_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:23:26 by besellem          #+#    #+#             */
/*   Updated: 2020/10/26 19:21:17 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_alloc_hex_min(t_data **s, t_indicators table, va_list ap)
{
	char *str;

	str = convert_base(va_arg(ap, unsigned int), "0123456789abcdef");
	ft_lstd_add(s, ft_lstd_new(str, ft_strlen(str)));
}
