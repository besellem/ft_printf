/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checks2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:33:59 by besellem          #+#    #+#             */
/*   Updated: 2021/09/01 00:35:55 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

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
