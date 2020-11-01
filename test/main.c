/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 23:10:19 by bensellem         #+#    #+#             */
/*   Updated: 2020/11/01 15:47:41 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main(void)
{
	char	*tab;
	int		size_real;
	int		size_mine;

	tab = "Hey there !";
	size_mine = ft_printf("MINE: int => [%00*d]\n", 12, -123);
	size_real = printf("REAL: int => [%00*d]\n", 12, -123);
	printf("MINE SIZE: %d\n", size_mine);
	printf("REAL SIZE: %d\n", size_real);
	return (0);
}
