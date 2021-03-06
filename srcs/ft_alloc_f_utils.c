/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_f_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:06:12 by besellem          #+#    #+#             */
/*   Updated: 2020/11/15 12:02:08 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_round_str(char *str, int precision)
{
	if (precision > 0 && str[precision] == '9')
	{
		str[precision] = '0';
		if (precision == 1 || (precision == 1 && str[precision] >= '5'))
			return (1);
		return (ft_round_str(str, precision - 1));
	}
	else
	{
		str[precision]++;
		return (0);
	}
}

int	prec_zero_case(long double n, int sign)
{
	int		x;
	long	next;

	n = sign ? -n : n;
	next = ((long)(n * 10) - (((long)n % 10) * 10)) % 10;
	if ((long)n % 2 == 1)
		x = next >= 5 ? 1 : 0;
	else
		x = next > 5 ? 1 : 0;
	return (!x && sign ? 0 : x);
}
