/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_hex_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:23:35 by besellem          #+#    #+#             */
/*   Updated: 2020/10/26 19:21:15 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_alloc_hex_maj(t_data **s, t_indicators table, va_list ap)
{
	char *str;

	str = convert_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	ft_lstd_add(s, ft_lstd_new(str, ft_strlen(str)));
}
