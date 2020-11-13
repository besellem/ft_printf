/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:28:41 by besellem          #+#    #+#             */
/*   Updated: 2020/11/13 13:53:34 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*asprintf_process(const char *format, va_list ap, int *size)
{
	char	*ret;
	t_data	*data;
	va_list	ap2;

	va_copy(ap2, ap);
	*size = 0;
	data = ft_parse_format(format, ap2);
	ft_lstd_get_size(&data, size);
	if (!(ret = (char *)ft_calloc(*size + 1, sizeof(char))))
		return (NULL);
	ft_fill_ret(&data, &ret);
	ft_lstd_clear(&data);
	va_end(ap2);
	return (ret);
}

int			ft_asprintf(char **ret, const char *format, ...)
{
	va_list	ap;
	int		size;

	va_start(ap, format);
	*ret = asprintf_process(format, ap, &size);
	va_end(ap);
	return (size);
}
