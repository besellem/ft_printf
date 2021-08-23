/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:49:34 by besellem          #+#    #+#             */
/*   Updated: 2021/08/23 02:38:30 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	conv_s(t_pft *pft)
{
	char	*str;
	size_t	__const_len__;
	int		len;
	int		len_tmp;

	str = va_arg(pft->ap, char *);
	if (!str)
		str = PFT_NULL;
	__const_len__ = ft_strlen(str);
	len = __const_len__;
	if (pft->conversion.precision >= 0 && len >= pft->conversion.precision)
		len = pft->conversion.precision;
	len_tmp = pft->conversion.width - len;
	if (-1 != pft->conversion.width && !(pft->conversion.flags & FLAG_MINUS))
		print_char(pft, ' ', ft_fdim(len_tmp, 0));
	write2buf_str(pft, (char *)str);
	if (-1 != pft->conversion.width && pft->conversion.flags & FLAG_MINUS)
		print_char(pft, ' ', ft_fdim(len_tmp, 0));
}
