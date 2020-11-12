/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_common2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:21:20 by besellem          #+#    #+#             */
/*   Updated: 2020/11/12 20:22:00 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	add_lstd(t_data **s, char *str)
{
	size_t size;

	if (!str || ((size = ft_strlen(str)) == 0))
		return ;
	ft_lstd_add(s, ft_lstd_new(str, size));
}

void	ft_lstd_get_size(t_data **s, int *size)
{
	t_data	**tracer;

	tracer = s;
	while (*tracer)
	{
		*size += (*tracer)->size;
		tracer = &(*tracer)->next;
	}
}
