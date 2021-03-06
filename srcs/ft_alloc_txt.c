/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_txt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:36:50 by besellem          #+#    #+#             */
/*   Updated: 2020/11/15 12:02:36 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	len_alloc(const char *format)
{
	int i;

	i = 0;
	while (format[i] && format[i] != '%')
		++i;
	return (i);
}

int			ft_alloc_txt(const char *format, t_data **s)
{
	char	*data;
	int		len;
	int		i;

	len = len_alloc(format);
	if (!(data = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	i = -1;
	while (++i < len)
		data[i] = format[i];
	data[i] = '\0';
	ft_lstd_add(s, ft_lstd_new(data, len));
	free(data);
	return (i);
}
