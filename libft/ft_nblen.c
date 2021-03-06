/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 22:32:26 by besellem          #+#    #+#             */
/*   Updated: 2020/11/16 23:34:20 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nblen(long long n)
{
	int len;

	n = n < 0 ? -n : n;
	len = 1;
	while (n / 10 > 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}
