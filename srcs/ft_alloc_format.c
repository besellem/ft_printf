/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 22:18:36 by besellem          #+#    #+#             */
/*   Updated: 2020/11/01 14:28:46 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_conversion(const char *s, t_types *t)
{
	int i;

	i = -1;
	while (t[++i].type)
		if (*s == t[i].type)
			return (i);
	return (-1);
}

void	init_indicators(t_indicators *table)
{
	table->minus = -1;
	table->zero = -1;
	table->dot = -1;
	table->plus = -1;
}

int		fill_indicators(const char *format, va_list ap, t_indicators *table)
{
	int index;

	if (*format == '-')
		table->minus = 1;
	else if (*format == '0')
		index = 1 + check_zero(format + 1, ap, table);
	//else if (ft_isdigit(*format))
	//	index = check_padding(format + 1, ap, table);
	else if (*format == '.')
		index = 1 + check_precision(format + 1, ap, table);
	else if (*format == '+')
		table->plus = 1;
	else
		return (-1);
	return (index);
}

int		ft_alloc_format(const char *format, va_list ap, t_data **s, t_types *t)
{
	t_indicators	table;
	int				index;
	int				i;
	int				check;

	init_indicators(&table);
	i = 0;
	while (format[i] && (index = is_conversion(format + i, t)) == -1)
	{
		if ((check = fill_indicators(format + i, ap, &table)) == -1)
			return (-1);
		i += check;
	}
	t[index].f(s, table, ap);
	return (i + 1);
}
