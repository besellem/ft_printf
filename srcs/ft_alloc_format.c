/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 22:18:36 by besellem          #+#    #+#             */
/*   Updated: 2020/10/17 22:18:38 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		is_flag(char *s)
{
	return (0);
}

static size_t	len_alloc(const char *format)
{
	size_t i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
			return (i);
		++i;
	}
	return (i);
}

static int		is_conversion(t_types *t, char *s)
{
	int i;
	int j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (t[++j].type)
		{
			//	ft_ncmp();
		}
	}
	return (i);
}

int				ft_alloc_format(const char *format, va_list ap, t_data **s)
{
	char	*data;
	t_types	*t;
	size_t	len;
	size_t	i;

	t = ft_init_conversions();
	len = len_alloc(format) + 1;
	if (!(data = (char *)malloc(sizeof(char) * len)))
		return (-1);
	i = 0;
	while (i < len)
	{
		if (format[i] == '%')
			data[i++] = '%';
		else
			data[i] = format[i];
		++i;
	}
	data[i] = '\0';
	ft_lstd_add(s, ft_lstd_new(data, len - 1));
	free(data);
	return (len);
}
