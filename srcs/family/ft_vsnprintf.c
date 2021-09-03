/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 03:12:57 by besellem          #+#    #+#             */
/*   Updated: 2021/09/03 04:07:11 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	char	*ret;
	int		len;

	ret = NULL;
	len = ft_vasprintf(&ret, format, ap);
	if (!ret)
		return (len);
	else if ((LIBC_NO_CRASH_ON_NULL && !str) || PFT_ERR == len)
	{
		ft_memdel((void **)&ret);
		return (len);
	}
	if (size > 0 && size <= (size_t)len)
	{
		ft_memcpy(str, ret, size - 1);
		str[size - 1] = 0;
	}
	else if (size > 0 && len > 0)
		ft_memcpy(str, ret, len + 1);
	ft_memdel((void **)&ret);
	return (len);
}
