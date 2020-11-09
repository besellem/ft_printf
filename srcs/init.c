/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 04:07:12 by besellem          #+#    #+#             */
/*   Updated: 2020/11/09 02:41:56 by besellem         ###   ########.fr       */
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

	size = 10;
	if (!(t = (t_types *)malloc(sizeof(t_types) * (size + 1))))
		return (NULL);
	add_conversion(&t[0], 'c', &ft_alloc_c);
	add_conversion(&t[1], 's', &ft_alloc_s);
	add_conversion(&t[2], 'p', &ft_alloc_p);
	add_conversion(&t[3], 'd', &ft_alloc_d);
	add_conversion(&t[4], 'i', &ft_alloc_i);
	add_conversion(&t[5], 'u', &ft_alloc_u);
	add_conversion(&t[6], 'o', &ft_alloc_o);
	add_conversion(&t[7], 'x', &ft_alloc_hex_min);
	add_conversion(&t[8], 'X', &ft_alloc_hex_maj);
	add_conversion(&t[9], '%', &ft_alloc_mod);
	// add_conversion(&t[10], 'f', &ft_alloc_f);
	t[size].type = '\0';
	return (t);
}
