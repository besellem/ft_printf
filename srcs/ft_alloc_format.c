/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 22:18:36 by besellem          #+#    #+#             */
/*   Updated: 2020/10/26 23:45:13 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_indicators(t_indicators *table)
{
	table->minus = -1;
	table->zero = -1;
	table->dot = -1;
	table->plus = -1;
}

void	check_dot(const char *format, va_list ap, t_indicators *table)
{
	if (*format && *format == '*')
		table->dot = va_arg(ap, int);
	else
		table->dot = ft_atoi(format);
}

static void	fill_indicators(const char *format, va_list ap, t_indicators *table)
{
	if (*format == '-')
		table->minus = 1;
	else if (*format == '0')
		table->zero = 1;
	else if (*format == '.')
		check_dot(format + 1, ap, table);
	else if (*format == '+')
		table->plus = 1;
}

static int	is_conversion(t_types *t, const char *s)
{
	int i;

	i = -1;
	while (t[++i].type)
		if (*s == t[i].type)
			return (i);
	return (-1);
}

int			ft_alloc_format(const char *format, va_list ap, t_data **s, t_types *t)
{
	t_indicators	table;
	int				index;
	int				i;

	init_indicators(&table);
	i = 0;
	while (format[i] && (index = is_conversion(t, format + i)) == -1)
	{
		fill_indicators(format + i, ap, &table);
		++i;
	}
	t[index].f(s, table, ap);
	return (i + 1);	// ft_len(t[index].type)
}
