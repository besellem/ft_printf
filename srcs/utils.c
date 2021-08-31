/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:39:26 by besellem          #+#    #+#             */
/*   Updated: 2021/09/01 00:53:27 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	print_flags(t_conv conv)
{
	printf("Flags:\n");
	printf("{\n");
	printf("    flag_htag:      [%u]\n", conv.flags & FLAG_HTAG);
	printf("    flag_space:     [%u]\n", conv.flags & FLAG_SPACE);
	printf("    flag_plus:      [%u]\n", conv.flags & FLAG_PLUS);
	printf("    flag_minus:     [%u]\n", conv.flags & FLAG_MINUS);
	printf("    flag_zero:      [%u]\n", conv.flags & FLAG_ZERO);
	printf("\n");
	printf("    is_spec:        [%u]\n", conv.specifiers & IS_SPEC);
	printf("    spec_hh:        [%u]\n", conv.specifiers & SPEC_HH);
	printf("    spec_h:         [%u]\n", conv.specifiers & SPEC_H);
	printf("    spec_l:         [%u]\n", conv.specifiers & SPEC_L);
	printf("    spec_ll:        [%u]\n", conv.specifiers & SPEC_LL);
	printf("    spec_j:         [%u]\n", conv.specifiers & SPEC_J);
	printf("    spec_z:         [%u]\n", conv.specifiers & SPEC_Z);
	printf("    spec_t:         [%u]\n", conv.specifiers & SPEC_T);
	printf("    spec_lf:        [%u]\n", conv.specifiers & SPEC_LF);
	printf("\n");
	printf("    width:          [%d]\n", conv.width);
	printf("    precision:      [%d]\n", conv.precision);
	printf("}\n");
}

void	print_binary(const char *prefix, long long n)
{
	const char	*binary = ft_itoa_base(n, "01");

	if (prefix)
		printf("%s -> [%s] [%lld]\n", prefix, binary, n);
	else
		printf("[%s] [%lld]\n", binary, n);
	ft_memdel((void **)&binary);
}
