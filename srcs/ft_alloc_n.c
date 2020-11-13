/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:20:09 by besellem          #+#    #+#             */
/*   Updated: 2020/11/13 15:53:52 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_alloc_n(t_data **s, va_list ap)
{
	int size;
	int *ptr;

	size = 0;
	ptr = va_arg(ap, int *);
	ft_lstd_get_size(s, &size);
	*ptr = size;
}
