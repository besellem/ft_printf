/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:49:34 by besellem          #+#    #+#             */
/*   Updated: 2021/09/01 17:37:24 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	__writen2buf__(t_pft *pft, char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str[i])
	{
		pft->write2buf(pft, str + i);
		++i;
	}
}

void	conv_s(t_pft *pft)
{
	char	*str;
	size_t	_const_len;
	int		len;
	int		len_tmp;

	str = va_arg(pft->ap, char *);
	if (!str)
		str = PFT_NULL;
	_const_len = ft_strlen(str);
	len = _const_len;
	if (pft->conversion.precision >= 0 && len >= pft->conversion.precision)
		len = pft->conversion.precision;
	len_tmp = pft->conversion.width - len;
	if (-1 != pft->conversion.width && !isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', ft_fdim(len_tmp, 0));
	__writen2buf__(pft, str, pft->conversion.precision);
	if (-1 != pft->conversion.width && isflag(pft, FLAG_MINUS))
		print_char(pft, ' ', ft_fdim(len_tmp, 0));
}
