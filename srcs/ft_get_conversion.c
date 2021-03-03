/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 23:42:12 by besellem          #+#    #+#             */
/*   Updated: 2021/03/03 02:05:30 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_conversion(t_pft *pft, const char *fmt)
{
	ft_bzero(&pft->type, sizeof(t_types));
	ft_bzero(&pft->conversion, sizeof(t_conv));
	(void)pft;
	(void)fmt;
	return (1);
}

void	conv_d(t_pft *pft)
{
	(void)pft;
}

void	conv_i(t_pft *pft)
{
	conv_d(pft);
}

void	conv_c(t_pft *pft)
{
	conv_d(pft);
}

int		ft_get_conversion(t_pft *pft, char conv)
{
	static char	conversions[] = "cdioupxXbfgean%";
	static void	(*convs[])() = {conv_c, conv_d, conv_i};
	// static void	(*convs[])() = {conv_c, conv_d, conv_i, conv_o, conv_u, conv_p,
	// 							conv_x_min, conv_x_max, conv_b, conv_f, conv_g,
	// 							conv_e, conv_a, conv_n, conv_perc};
	int			i;

	i = 0;
	while (conversions[i])
	{
		if (conversions[i] == conv)
		{
			convs[i](pft);
			return (1);
		}
		++i;
	}
	return (0);
}
