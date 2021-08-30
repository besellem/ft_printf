/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 23:42:12 by besellem          #+#    #+#             */
/*   Updated: 2021/08/31 00:46:45 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_get_conversion(t_pft *pft, char conv)
{
	const t_conv_ptrs	conv_ptrs[] = {
		{'s', conv_s}, {'d', conv_d}, {'u', conv_u}, {'c', conv_c},
		{'p', conv_p}, {'x', conv_x_min}, {'X', conv_x_max}, {'i', conv_i},
		{'o', conv_o}, {'f', conv_f}, {'a', conv_a},
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

int	check_htag(t_conv *conversion)
{
	conversion->flags |= FLAG_HTAG;
	return (1);
}

int	check_spce(t_conv *conversion)
{
	conversion->flags |= FLAG_SPACE;
	if (conversion->flags & FLAG_PLUS)
		conversion->flags &= ~FLAG_SPACE;
	return (1);
}

int	check_plus(t_conv *conversion)
{
	conversion->flags |= FLAG_PLUS;
	return (1);
}

int	check_min(t_conv *conversion)
{
	conversion->flags |= FLAG_MINUS;
	return (0);
}

int	check_wdt(const char *fmt, va_list ap, t_conv *conversion)
{
	if (*fmt && *fmt == '*')
	{
		conversion->width = va_arg(ap, int);
		if (conversion->width < 0)
		{
			conversion->flags |= FLAG_MINUS;
			conversion->width *= -1;
		}
		return (1);
	}
	else
		conversion->width = ft_atoi(fmt);
	return (ft_len_base(conversion->width, 10));
}

int	check_zero(const char *fmt, va_list ap, t_conv *conversion)
{
	if (*fmt && *fmt == '0')
		return (0);
	if (*fmt && *fmt == '+')
		return (check_plus(conversion) - 1);
	if (*fmt && *fmt == '*')
	{
		conversion->width = va_arg(ap, int);
		if (conversion->width < 0)
		{
			conversion->width = -conversion->width;
			conversion->flags |= FLAG_ZERO;
			conversion->flags |= FLAG_MINUS;
		}
		return (1);
	}
	if (*fmt && ft_atoi(fmt) < 0)
		return (check_min(conversion));
	else if (*fmt && ft_atoi(fmt) == 0)
	{
		conversion->width = 0;
		return (0);
	}
	conversion->width = ft_atoi(fmt);
	return (ft_len_base(conversion->width, 10));
}

int	check_prec(const char *fmt, va_list ap, t_conv *conversion)
{
	int	i;

	conversion->precision = 0;
	conversion->flags |= FLAG_PRECISION;
	if (*fmt && *fmt == '*')
	{
		conversion->precision = va_arg(ap, int);
		if (conversion->precision < 0)
		{
			conversion->precision = -1;
			conversion->flags &= ~FLAG_PRECISION;
		}
		return (1);
	}
	else
	{
		i = 0;
		while (fmt[i] && fmt[i] == '0')
			++i;
		if (ft_atoi(fmt + i) == 0)
			return (i);
		conversion->precision = ft_atoi(fmt + i) < 0 ? -1 : ft_atoi(fmt + i);
		return (i + ft_len_base(conversion->precision, 10));
	}
}

int	is_specifier(const char *fmt, t_conv *conversion)
{
	int	ret;

	ret = 1;
	if (conversion->specifiers & IS_SPEC)
		return (-1);
	conversion->specifiers |= IS_SPEC;
	if (ft_strncmp("hh", fmt, 2) == 0 && (ret = 2))
		conversion->specifiers |= SPEC_HH;
	else if (ft_strncmp("h", fmt, 1) == 0)
		conversion->specifiers |= SPEC_H;
	else if (ft_strncmp("ll", fmt, 2) == 0 && (ret = 2))
		conversion->specifiers |= SPEC_LL;
	else if (ft_strncmp("l", fmt, 1) == 0)
		conversion->specifiers |= SPEC_L;
	else if (ft_strncmp("j", fmt, 1) == 0)
		conversion->specifiers |= SPEC_J;
	else if (ft_strncmp("z", fmt, 1) == 0)
		conversion->specifiers |= SPEC_Z;
	else if (ft_strncmp("t", fmt, 1) == 0)
		conversion->specifiers |= SPEC_T;
	else if (ft_strncmp("L", fmt, 1) == 0)
		conversion->specifiers |= SPEC_LF;
	else
		return (-1);
	return (ret);
}

int	fill_indicators(const char *fmt, va_list ap, t_conv *conversion)
{
	int	index;

	if ('-' == *fmt)
		return (1 + check_min(conversion));
	else if ('0' == *fmt)
		return (1 + check_zero(fmt + 1, ap, conversion));
	else if ('*' == *fmt || (*fmt >= '1' && *fmt <= '9'))
		return (check_wdt(fmt, ap, conversion));
	else if ('.' == *fmt)
		return (1 + check_prec(fmt + 1, ap, conversion));
	else if ('#' == *fmt)
		return (check_htag(conversion));
	else if (' ' == *fmt)
		return (check_spce(conversion));
	else if ('+' == *fmt)
		return (check_plus(conversion));
	else if ((index = is_specifier(fmt, conversion)) != -1)
		return (index);
	else
		return (-1);
	return (index);
}

static void	init_conversion(t_conv *conversion)
{
	ft_bzero(conversion, sizeof(t_conv));
	conversion->width = -1;
	conversion->precision = -1;
}

int	ft_parse_conversion(t_pft *pft, const char *fmt)
{
	int	check;
	int	i;

	init_conversion(&pft->conversion);
	
	// printf("width:     %d\n", pft->conversion.width);
	// printf("precision: %d\n", pft->conversion.precision);

	i = 0;
	while (0 == ft_get_conversion(pft, fmt[i]))
	{
		check = fill_indicators(fmt + i, pft->ap, &pft->conversion);
		// printf("PREC: %d\n", pft->conversion.precision);
		if (PFT_ERR == check)
			return (PFT_ERR);
		i += check;
	}
	// print_flags(pft->conversion);
	return (i + 1);
}
