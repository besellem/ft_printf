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

void		init_indicators(t_indicators *table)
{
	table->minus = 0;
	table->zero = 0;
	table->dot = 0;
	table->star = 0;
	table->plus = 0;
}

static int	ft_indicator(const char *format, t_indicators *table)
{
	if (*format == '-')
		table->minus = 1;
	else if (*format == '0')
		table->zero = 1;
	else if (*format == '.')
		table->dot = 1;
	else if (*format == '*')
		table->star = 1;
	else if (*format == '+')
		table->plus = 1;
	else
		return (0);
	return (1);
}

static int	is_conversion(t_types *t, const char *s)
{
	int i;

	i = -1;
	while (t[++i].type)
	{
		if (strncmp(s, t[i].type, ft_len(t[i].type)) == 0)
			return (i);
	}
	return (-1);
}

static int	ft_width(const char *format, t_indicators *table)
{
	return (0);
}

int			ft_alloc_format(const char *format, va_list ap, t_data **s, t_types	*t)
{
	t_indicators	table;
	int				index;
	int				i;

	init_indicators(&table);
	/*
	i = ft_indicator(format, &table);
	i += ft_width(format + i, &table);
	*/
	i = 0;
	while ((format + i) && (index = is_conversion(t, format + i)) == -1)
	{
		++i;
	}
	t[index].f(s, table, ap);
	return (ft_len(t[index].type));
}
