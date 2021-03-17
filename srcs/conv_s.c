/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:49:34 by besellem          #+#    #+#             */
/*   Updated: 2021/03/18 00:15:01 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_s(t_pft *pft)
{
	const char	*str = va_arg(pft->ap, char *);

	if (!str)
		write2buf_str(pft, "(null)");
	else
		write2buf_str(pft, (char *)str);
}
