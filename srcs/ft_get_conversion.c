/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 23:42:12 by besellem          #+#    #+#             */
/*   Updated: 2021/03/18 00:16:40 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_conversion(t_pft *pft, char conv)
{
	const t_conv_ptrs	conv_ptrs[] = {
		{'s', conv_s}, {'d', conv_d}, {'u', conv_u}, {'c', conv_c},
		{'p', conv_p}, {'x', conv_x_min}, {'X', conv_x_max}, {'i', conv_i},
		{'o', conv_o}, 
		// {'b', conv_b}, {'f', conv_f}, {'g', conv_g}, {'e', conv_e},
		// {'a', conv_a}, {'n', conv_n}, {'%', conv_perc},
		{0, NULL}
	};
	int					i;

	i = 0;
	while (conv_ptrs[i].conversion)
	{
		if (conv_ptrs[i].conversion == conv)
		{
			conv_ptrs[i].f(pft);
			return (1);
		}
		++i;
	}
	return (0);
}

int	check_flags(t_pft *pft, const char *fmt)
{
	int	ret;

	ret = 1;
	if (*fmt == '.')
		pft->conversion.flags |= flag_precision;
	return (ret);
}

// OLD PRINTF CODE
// int		is_specifier(const char *format, t_indicators *t)
// {
// 	int ret;

// 	ret = 1;
// 	if (t->is_specifier != 0)
// 		return (-1);
// 	t->is_specifier = 1;
// 	if (ft_strncmp("hh", format, 2) == 0 && (ret = 2))
// 		t->hh = 1;
// 	else if (ft_strncmp("h", format, 1) == 0)
// 		t->h = 1;
// 	else if (ft_strncmp("ll", format, 2) == 0 && (ret = 2))
// 		t->ll = 1;
// 	else if (ft_strncmp("l", format, 1) == 0)
// 		t->l = 1;
// 	else if (ft_strncmp("L", format, 1) == 0)
// 		t->lf = 1;
// 	else
// 		return (-1);
// 	return (ret);
// }

// void	init_indicators(t_indicators *table)
// {
// 	table->width = -1;
// 	table->minus = -1;
// 	table->zero = -1;
// 	table->dot = -1;
// 	table->htag = 0;
// 	table->space = 0;
// 	table->plus = 0;
// 	table->is_specifier = 0;
// 	table->h = 0;
// 	table->hh = 0;
// 	table->l = 0;
// 	table->ll = 0;
// 	table->lf = 0;
// }

// int		fill_indicators(const char *format, va_list ap, t_indicators *table)
// {
// 	int index;

// 	if (*format == '-')
// 		index = 1 + check_min(table);
// 	else if (*format == '0')
// 		index = 1 + check_zero(format + 1, ap, table);
// 	else if (*format == '*' || (*format >= '1' && *format <= '9'))
// 		index = check_wdt(format, ap, table);
// 	else if (*format == '.')
// 		index = 1 + check_prec(format + 1, ap, table);
// 	else if (*format == '#')
// 		index = check_htag(table);
// 	else if (*format == ' ')
// 		index = check_spce(table);
// 	else if (*format == '+')
// 		index = check_plus(table);
// 	else if ((index = is_specifier(format, table)) != -1)
// 		return (index);
// 	else
// 		return (-1);
// 	return (index);
// }
// END OLD PRINTF CODE


static void	init_conversion(t_conv *conversion)
{
	ft_bzero(conversion, sizeof(t_conv));
	conversion->width = -1;
	conversion->precision = -1;
}

int			ft_parse_conversion(t_pft *pft, const char *fmt)
{
	int	check;
	int	i;

	i = 0;
	init_conversion(&pft->conversion);
	while (ft_get_conversion(pft, fmt[i]) == 0)
	{
		// check = check_flags(pft, fmt);
		check = ft_parse_flags(pft, fmt + i);
		print_flags(pft);
		if (check == 0)
			return (-1);
		i += check;
	}
	return (i + 1);
}
