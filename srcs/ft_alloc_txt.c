/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_txt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:36:50 by besellem          #+#    #+#             */
/*   Updated: 2020/10/17 21:36:51 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	len_alloc(const char *format)
{
	size_t len;
	size_t i;

	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] && format[i + 1] != '%')
			return (len);
		else if (format[i] == '%' && format[i + 1] && format[i + 1] == '%')
			++i;
		++len;
		++i;
	}
	return (len);
}

int				ft_alloc_txt(const char *format, t_data **s, size_t *index)
{
	char	*data;
	size_t	len;
	size_t	i;
	size_t	j;

	len = len_alloc(format);
	if (!(data = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	i = 0;
	j = 0;
	while (j < len)
	{
		if (format[i] == '%' && ++i)
			data[j++] = '%';
		else
			data[j++] = format[i];
		++i;
	}
	data[j] = '\0';
	ft_lstd_add(s, ft_lstd_new(data, len));
	*index += i;
	free(data);
	return (0);
}
