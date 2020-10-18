/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:06:02 by besellem          #+#    #+#             */
/*   Updated: 2020/10/17 21:06:04 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_alloc_s(t_data **s, va_list ap)
{
	char	*str;
	int		i;

	str = va_arg(ap, char *);
	i = 0;
	while (str[i])
		++i;
	ft_lstd_add(s, ft_lstd_new(str, i));
}
