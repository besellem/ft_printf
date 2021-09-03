/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:27:17 by besellem          #+#    #+#             */
/*   Updated: 2021/09/03 04:01:25 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	char	*ret;
	int		size;

	ret = NULL;
	size = ft_vasprintf(&ret, format, ap);
	if (!ret)
		return (size);
	else if ((LIBC_NO_CRASH_ON_NULL && !str) || PFT_ERR == size)
	{
		ft_memdel((void **)&ret);
		return (size);
	}
	ft_memcpy(str, ret, size + 1);
	ft_memdel((void **)&ret);
	return (size);
}
