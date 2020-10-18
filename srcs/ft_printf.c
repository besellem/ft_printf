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
	t_data *data;
	size_t i;

	data = NULL;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
			i += ft_alloc_format(format + i + 1, ap, &data);
		else
			i += ft_alloc_txt(format + i, &data);
	}
	return (data);
}

int		ft_process(const char *format, va_list ap)
{
	t_data	*data;
	int		size;

	size = 0;
	data = ft_parse_format(format, ap);
	ft_lstd_print(&data, &size, 1);
	ft_lstd_clear(&data);
	return (size);
}

int		ft_printf_bis(const char *format, ...)
{
	va_list	ap;
	int		size;

	va_start(ap, format);
	size = ft_process(format, ap);
	va_end(ap);
	return (size);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_type	*s;
	size_t	i;
	size_t	j;
	int		size;

	va_start(ap, format);
	s = ft_init_types();
	size = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ++i)
		{
			if (format[i] == '%' && ++i)
			{
				ft_putchar('%', &size);
				continue ;
			}
			j = 0;
			while (s[j].type)
			{
				if (s[j].type == format[i])
				{
					s[j].f(va_arg(ap, void *), &size);
					break ;
				}
				++j;
			}
		}
		else
			ft_putchar(format[i], &size);
		++i;
	}
	free(s);
	va_end(ap);
	return (size);
}
