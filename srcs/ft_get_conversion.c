/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 23:42:12 by besellem          #+#    #+#             */
/*   Updated: 2021/09/01 23:09:27 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

struct s_is_spec
{
	char			*_spec;
	unsigned int	_len;
	unsigned int	_mask;
};

struct s_conv_ptrs
{
	char	_conv;
	void	(*_f)(struct s_pft *);
};

static int	is_specifier(const char *fmt, t_conv *conversion)
{
	static struct s_is_spec	spec[] = {
		{"hh", 2, SPEC_HH}, {"h", 1, SPEC_H}, {"j", 1, SPEC_J},
		{"ll", 2, SPEC_LL}, {"l", 1, SPEC_L}, {"z", 1, SPEC_Z},
		{"t", 1, SPEC_T}, {"L", 1, SPEC_LF}, {NULL, 0, 0x0}
	};
	int						i;

	if (conversion->specifiers & IS_SPEC)
		return (-1);
	i = 0;
	while (spec[i]._spec)
	{
		if (0 == ft_strncmp(spec[i]._spec, fmt, spec[i]._len))
		{
			conversion->specifiers |= spec[i]._mask;
			return (spec[i]._len);
		}
		++i;
	}
	return (-1);
}

static int	fill_indicators(const char *fmt, va_list ap, t_conv *conversion)
{
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
	else if (is_specifier(fmt, conversion) != -1)
		return (is_specifier(fmt, conversion));
	else
		return (-1);
}

static int	ft_get_conversion(t_pft *pft, char conv)
{
	static struct s_conv_ptrs	conv_ptrs[] = {
		{'d', conv_d}, {'u', conv_u}, {'x', conv_x_min}, {'X', conv_x_max},
		{'s', conv_s}, {'c', conv_c}, {'p', conv_p}, {'i', conv_i},
		{'o', conv_o}, {'f', conv_f}, {'a', conv_a}, {'%', conv_perc},
		{'D', conv_d_max}, {'U', conv_u_max}, {'O', conv_o_max},
		// {'b', conv_b}, {'g', conv_g}, {'e', conv_e}, {'n', conv_n},
		{0, NULL}
	};
	int							i;

	i = 0;
	while (conv_ptrs[i]._conv)
	{
		if (conv_ptrs[i]._conv == conv)
		{
			conv_ptrs[i]._f(pft);
			return (TRUE);
		}
		++i;
	}
	return (FALSE);
}

int	ft_parse_conversion(t_pft *pft, const char *fmt)
{
	int		check;
	int		i;

	ft_bzero(&pft->conversion, sizeof(t_conv));
	pft->conversion.width = -1;
	pft->conversion.precision = -1;
	i = 0;
	while (FALSE == ft_get_conversion(pft, fmt[i]))
	{
		check = fill_indicators(fmt + i, pft->ap, &pft->conversion);
		if (PFT_ERR == check)
			return (PFT_ERR);
		i += check;
	}
	return (i + 1);
}
