/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_checks2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 23:03:38 by besellem          #+#    #+#             */
/*   Updated: 2020/11/15 12:02:52 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	check_htag(t_indicators *table)
{
	table->htag = 1;
	return (1);
}

int	check_spce(t_indicators *table)
{
	table->space = 1;
	if (table->plus == 1)
		table->space = 0;
	return (1);
}

int	check_plus(t_indicators *table)
{
	table->plus = 1;
	return (1);
}
