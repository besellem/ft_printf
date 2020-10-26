/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 04:07:12 by besellem          #+#    #+#             */
/*   Updated: 2020/10/27 00:46:27 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	add_conversion(t_types *t, char type, void (*f)())
{
	t->type = type;
	t->f = f;
}

t_types		*ft_init_conversions(void)
{
	t_types	*t;
	int		size;

	size = 7;
	if (!(t = (t_types *)malloc(sizeof(t_types) * (size + 1))))
		return (NULL);
	add_conversion(&t[0], 'c', &ft_alloc_c);
	add_conversion(&t[1], 's', &ft_alloc_s);
	add_conversion(&t[2], 'p', &ft_alloc_p);
	add_conversion(&t[3], 'd', &ft_alloc_d);
	add_conversion(&t[4], 'u', &ft_alloc_u);
	add_conversion(&t[5], 'x', &ft_alloc_hex_min);
	add_conversion(&t[6], 'X', &ft_alloc_hex_maj);
	/*
	** add_conversion(&t[4], 'i', &ft_alloc_i);
	*/
	t[size].type = '\0';
	return (t);
}
