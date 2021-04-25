/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:14:49 by besellem          #+#    #+#             */
/*   Updated: 2021/04/25 22:33:01 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

typedef	struct	s_parse_flags
{
	char	flag;
	int		mask;
	int		(*f)();
}				t_parse_flags;

int		parse_va_args(t_pft *pft, const char *fmt);
int		parse_htag(t_pft *pft, const char *fmt);
int		parse_apostrophe(t_pft *pft, const char *fmt);
int		parse_space(t_pft *pft, const char *fmt);
int		parse_plus(t_pft *pft, const char *fmt);
int		parse_minus(t_pft *pft, const char *fmt);
int		parse_precision(t_pft *pft, const char *fmt);


// int		parse_nbrs(t_pft *pft, const char *fmt)
// {
// 	const t_parse_flags	nbr_flags[] = {
// 		{'$', flag_arg_nbr, parse_va_args},
// 		{'.', FLAG_PRECISION, parse_precision}, {0, 0, NULL}
// 	};
// 	int					fmt_idx;
// 	int					nb;
// 	int					tmp_is_zero_flag;

// 	fmt_idx = 0;
// 	if (ft_isdigit(fmt[fmt_idx]))
// 	{
// 		tmp_is_zero_flag = 0;
// 		while (fmt[fmt_idx] && fmt[fmt_idx] == '0')
// 		{
// 			++tmp_is_zero_flag;
// 			++fmt_idx;
// 		}
// 		nb = ft_atoi(fmt + fmt_idx);
// 		fmt_idx += ft_nblen(nb);
// 		if (fmt[fmt_idx] && fmt[fmt_idx] == '$')
// 		{
// 			pft->conversion.arg_nbr = nb;
// 			pft->conversion.flags |= FLAG_ARG_NBR;
// 		}
// 		else
// 		{
// 			if (tmp_is_zero_flag)
// 				pft->conversion.flags |= FLAG_ZERO;
// 			if (fmt[fmt_idx] && fmt[fmt_idx] == '.')
// 			{
// 				pft->conversion.width = nb;
// 				pft->conversion.flags |= FLAG_WIDTH;
// 			}
// 			else
// 			{
// 				pft->conversion.precision = nb;
// 				pft->conversion.flags |= FLAG_PRECISION;
// 			}
// 		}
// 	}
// }






// void	*get_va_arg_idx(va_list ap, int idx)
// {
// 	va_list	tmp;
// 	void	*arg;
// 	int		i;

// 	va_copy(tmp, ap);
// 	i = 0;
// 	while (i < idx)
// 	{
// 		arg = va_arg(tmp, void *);
// 		++i;
// 	}
// 	return (arg);
// }

// int	ft_parse_flags(t_pft *pft, const char *fmt)
// {
// 	const t_parse_flags	flags[] = {
// 		{'#', FLAG_HTAG, NULL}, {' ', FLAG_SPACE, NULL},
// 		{'+', FLAG_PLUS, NULL}, {'-', FLAG_MINUS, NULL},
// 		{0, 0, NULL}
// 	};
// 	int					nb;
// 	int					tmp_is_zero_flag;
// 	int					fmt_idx;
// 	int					i;

// 	fmt_idx = 0;
// 	if (ft_isdigit(fmt[fmt_idx]))
// 	{
// 		tmp_is_zero_flag = 0;
// 		while (fmt[fmt_idx] && fmt[fmt_idx] == '0')
// 		{
// 			++tmp_is_zero_flag;
// 			++fmt_idx;
// 		}
// 		nb = ft_atoi(fmt + fmt_idx);
// 		fmt_idx += ft_nblen(nb);
// 		if (fmt[fmt_idx] && fmt[fmt_idx] == '$')
// 		{
// 			// pft->conversion.arg_nbr = nb;
// 			printf("arg_nb parsed: [%d]\n", nb);
// 			pft->conversion.arg = get_va_arg_idx(pft->ap_cpy, nb);
// 			printf("pft->conversion.arg: [%d]\n", (int)pft->conversion.arg);
// 			pft->conversion.flags |= FLAG_ARG_NBR;
// 		}
// 		else
// 		{
// 			if (tmp_is_zero_flag)
// 				pft->conversion.flags |= FLAG_ZERO;
// 			pft->conversion.width = nb;
// 			pft->conversion.flags |= FLAG_WIDTH;
// 			if (fmt[fmt_idx] && fmt[fmt_idx] == '.')
// 			{
// 				// parse_precision(pft, fmt + fmt_idx);
// 				pft->conversion.flags |= FLAG_PRECISION;
// 			}
// 		}
// 	}
// 	i = 0;
// 	while (flags[i].flag)
// 	{
// 		if (fmt[fmt_idx] == flags[i].flag)
// 		{
// 			pft->conversion.flags |= flags[i].mask;
// 			// flags[i].f(pft, fmt + fmt_idx);
// 			printf("fmt_idx: [%d]\n", fmt_idx);
// 			break ;
// 		}
// 		++i;
// 	}
// 	return (fmt_idx + 1);
// }
