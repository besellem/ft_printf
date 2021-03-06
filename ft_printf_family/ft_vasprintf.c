/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:42:18 by besellem          #+#    #+#             */
/*   Updated: 2020/11/15 12:01:42 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	*vasprintf_process(const char *format, va_list ap, int *size)
{
	char	*ret;
	t_data	*data;

	*size = 0;
	data = ft_parse_format(format, ap);
	ft_lstd_get_size(&data, size);
	if (!(ret = (char *)ft_calloc(*size + 1, sizeof(char))))
	{
		*size = -1;
		ft_lstd_clear(&data);
		return (NULL);
	}
	ft_fill_ret(&data, &ret);
	ft_lstd_clear(&data);
	return (ret);
}

int			ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int size;

	*ret = vasprintf_process(format, ap, &size);
	return (size);
}
