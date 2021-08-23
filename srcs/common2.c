/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 01:26:33 by besellem          #+#    #+#             */
/*   Updated: 2021/08/23 01:50:47 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#define __BUF_TMP_SIZE__ 128

void	print_char(t_pft *pft, char c, int len)
{
	char	buf[__BUF_TMP_SIZE__ + 1];

	ft_memset(buf, c, __BUF_TMP_SIZE__);
	buf[__BUF_TMP_SIZE__] = 0;
	while (len > __BUF_TMP_SIZE__)
	{
		write2buf_str(pft, buf);
		len -= __BUF_TMP_SIZE__;
	}
	if (len > 0)
	{
		buf[len] = 0;
		write2buf_str(pft, buf);
	}
}
