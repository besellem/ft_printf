/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:02:07 by besellem          #+#    #+#             */
/*   Updated: 2020/10/17 21:02:11 by besellem         ###   ########.fr       */
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

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		size;

	va_start(ap, format);
	size = ft_process(format, ap, 1);
	va_end(ap);
	return (size);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		size;

	va_start(ap, format);
	size = ft_process(format, ap, fd);
	va_end(ap);
	return (size);
}
