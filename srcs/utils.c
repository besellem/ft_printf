/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:39:26 by besellem          #+#    #+#             */
/*   Updated: 2021/03/17 23:58:28 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flags(t_pft *pft)
{
	printf("Flags:\n");
	printf("{\n");
	printf("    flag_arg_nbr:   [%u]\n", pft->conversion.flags & flag_arg_nbr);
	printf("    flag_htag:      [%u]\n", pft->conversion.flags & flag_htag);
	printf("    flag_space:     [%u]\n", pft->conversion.flags & flag_space);
	printf("    flag_plus:      [%u]\n", pft->conversion.flags & flag_plus);
	printf("    flag_minus:     [%u]\n", pft->conversion.flags & flag_minus);
	printf("    flag_zero:      [%u]\n", pft->conversion.flags & flag_zero);
	printf("    flag_width:     [%u]\n", pft->conversion.flags & flag_width);
	printf("    flag_precision: [%u]\n", pft->conversion.flags & flag_precision);
	printf("\n");
	printf("    width:          [%u]\n", pft->conversion.width);
	printf("    precision:      [%u]\n", pft->conversion.precision);
	printf("    arg_nbr:        [%u]\n", pft->conversion.arg_nbr);
	printf("}\n");
}
