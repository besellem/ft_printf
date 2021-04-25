/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:39:26 by besellem          #+#    #+#             */
/*   Updated: 2021/04/25 22:54:56 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	print_flags(t_pft *pft)
{
	printf("Flags:\n");
	printf("{\n");
	printf("    flag_htag:      [%u]\n", pft->conversion.flags & FLAG_HTAG);
	printf("    flag_space:     [%u]\n", pft->conversion.flags & FLAG_SPACE);
	printf("    flag_plus:      [%u]\n", pft->conversion.flags & FLAG_PLUS);
	printf("    flag_minus:     [%u]\n", pft->conversion.flags & FLAG_MINUS);
	printf("    flag_zero:      [%u]\n", pft->conversion.flags & FLAG_ZERO);
	printf("    flag_width:     [%u]\n", pft->conversion.flags & FLAG_WIDTH);
	printf("    flag_precision: [%u]\n", pft->conversion.flags & FLAG_PRECISION);
	printf("\n");
	printf("    is_spec:        [%u]\n", pft->conversion.specifiers & IS_SPEC);
	printf("    spec_hh:        [%u]\n", pft->conversion.specifiers & SPEC_HH);
	printf("    spec_h:         [%u]\n", pft->conversion.specifiers & SPEC_H);
	printf("    spec_l:         [%u]\n", pft->conversion.specifiers & SPEC_L);
	printf("    spec_ll:        [%u]\n", pft->conversion.specifiers & SPEC_LL);
	printf("    spec_j:         [%u]\n", pft->conversion.specifiers & SPEC_J);
	printf("    spec_z:         [%u]\n", pft->conversion.specifiers & SPEC_Z);
	printf("    spec_t:         [%u]\n", pft->conversion.specifiers & SPEC_T);
	printf("    spec_lf:        [%u]\n", pft->conversion.specifiers & SPEC_LF);
	printf("\n");
	printf("    width:          [%d]\n", pft->conversion.width);
	printf("    precision:      [%d]\n", pft->conversion.precision);
	printf("}\n");
}
