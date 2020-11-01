/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:13:26 by besellem          #+#    #+#             */
/*   Updated: 2020/11/01 12:15:32 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_data	*ft_parse_format(const char *format, va_list ap)
{
	t_data	*data;
	t_types	*t;
	size_t	i;
	int		check;

	data = NULL;
	t = ft_init_conversions();
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%' && ++i)
		{
			if ((check = ft_alloc_format(format + i, ap, &data, t)) == -1)
				return (NULL);
			i += check;
		}
		else
			i += ft_alloc_txt(format + i, &data);
	}
	return (data);
}

int		ft_process(const char *format, va_list ap, int fd)
{
	int		size;
	t_data	*data;
	va_list	ap2;

	va_copy(ap2, ap);
	size = 0;
	data = ft_parse_format(format, ap2);
	ft_lstd_print(&data, &size, fd);
	ft_lstd_clear(&data);
	va_end(ap2);
	return (size);
}
