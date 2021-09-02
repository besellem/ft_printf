/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 01:26:33 by besellem          #+#    #+#             */
/*   Updated: 2021/09/02 16:41:23 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#define __BUF_TMP_SIZE__ 128

// print a character `n' times
void	print_char(t_pft *pft, char c, int n)
{
	char	buf[__BUF_TMP_SIZE__ + 1];

	ft_memset(buf, c, __BUF_TMP_SIZE__);
	buf[__BUF_TMP_SIZE__] = 0;
	while (n >= __BUF_TMP_SIZE__)
	{
		pft->write2buf_s(pft, buf);
		n -= __BUF_TMP_SIZE__;
	}
	if (n > 0)
	{
		buf[n] = 0;
		pft->write2buf_s(pft, buf);
	}
}

int	isflag(t_pft *pft, unsigned int flag)
{
	return ((pft->conversion.flags & flag) != 0);
}

int	ft_print_special_fp(t_pft *pft, double nb)
{
	if (ft_isnan(nb))
		pft->write2buf_s(pft, "nan");
	else if (ft_isinf(nb))
	{
		if (ft_signbit(nb))
			pft->write2buf_s(pft, "-");
		else
		{
			if (isflag(pft, FLAG_PLUS))
				pft->write2buf_s(pft, "+");
			else if (isflag(pft, FLAG_SPACE))
				pft->write2buf_s(pft, " ");
		}
		pft->write2buf_s(pft, "inf");
	}
	else
		return (FALSE);
	return (TRUE);
}
