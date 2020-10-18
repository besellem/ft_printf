/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 04:07:12 by besellem          #+#    #+#             */
/*   Updated: 2020/10/18 04:07:16 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	add_conversion(t_types t, char *type, void (*f)())
{
	t.type = ft_dup(type);
	t.f = f;
}

t_types	*ft_init_conversions(void)
{
	t_types	*t;
	int		size;

	size = 5;
	if (!(t = (t_types *)malloc(sizeof(t_types) * (size + 1))))
		return (NULL);
	//	add_conversion(t[0], "c", &ft_alloc_c);
	add_conversion(t[0], "s", &ft_alloc_s);
	/*
	add_conversion(t[2], "d", &ft_alloc_d);
	add_conversion(t[3], "x", &ft_alloc_x);
	add_conversion(t[4], "X", &ft_alloc_X);
	*/
	add_conversion(t[size], NULL, NULL);
	return (t);
}
