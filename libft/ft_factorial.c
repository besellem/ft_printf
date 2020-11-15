/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:01:36 by besellem          #+#    #+#             */
/*   Updated: 2020/09/17 15:01:44 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_factorial(size_t nb)
{
	size_t res;

	res = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
		res *= nb--;
	return (res);
}
