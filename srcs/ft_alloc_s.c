/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:06:02 by besellem          #+#    #+#             */
/*   Updated: 2020/10/27 17:18:09 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_alloc_s(t_data **s, t_indicators table, va_list ap)
{
	char	*str;
	int		size;

	str = va_arg(ap, char *);
	str = str ? str : "(null)";
	size = str ? ft_strlen(str) : 6;
	if (table.dot != -1)
		size = size >= table.dot ? table.dot : size;
	ft_lstd_add(s, ft_lstd_new(str, size));
}
