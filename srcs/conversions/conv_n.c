/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 01:20:32 by besellem          #+#    #+#             */
/*   Updated: 2021/09/03 01:35:32 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	conv_n(t_pft *pft)
{
	const void	*ptr = va_arg(pft->ap, void *);
	const int	_spec = pft->conversion.specifiers;

	if (_spec & SPEC_HH)
		*(char *)(void *)ptr = pft->global_size;
	else if (_spec & SPEC_H)
		*(short *)(void *)ptr = pft->global_size;
	else if (_spec & SPEC_L)
		*(long *)(void *)ptr = pft->global_size;
	else if (_spec & SPEC_LL)
		*(long long *)(void *)ptr = pft->global_size;
	else if (_spec & SPEC_J)
		*(intmax_t *)(void *)ptr = pft->global_size;
	else if (_spec & SPEC_T)
		*(ptrdiff_t *)(void *)ptr = pft->global_size;
	else if (_spec & SPEC_Z)
		*(ssize_t *)(void *)ptr = pft->global_size;
	else
		*(int *)(void *)ptr = pft->global_size;
}
