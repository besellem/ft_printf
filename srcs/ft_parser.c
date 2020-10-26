/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:13:26 by besellem          #+#    #+#             */
/*   Updated: 2020/10/26 20:29:37 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_data	*ft_parse_format(const char *format, va_list ap)
{
	t_data	*data;
	t_types	*t;
	size_t	i;

	data = NULL;
	t = ft_init_conversions();
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%' && ++i)
			i += ft_alloc_format(format + i, ap, &data, t);
		else
			i += ft_alloc_txt(format + i, &data);
	}
	return (data);
}

int		ft_process(const char *format, va_list ap, int fd)
{
	t_data	*data;
	int		size;

	size = 0;
	data = ft_parse_format(format, ap);
	ft_lstd_print(&data, &size, fd);
	ft_lstd_clear(&data);
	return (size);
}
