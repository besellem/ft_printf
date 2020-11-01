/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 23:10:19 by bensellem         #+#    #+#             */
/*   Updated: 2020/11/01 01:03:53 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main(void)
{
	char	*tab;
	int		size_real;
	int		size_mine;

	tab = "Hey there !";
	size_mine = ft_printf("MINE: hex => %.2X. %%d => %.4d. %%i => %.4i.\n", 10, 0x10, 0x10);
	size_real = printf("REAL: hex => %.2X. %%d => %.4d. %%i => %.4i.\n", 10, 0x10, 0x10);
	printf("MINE SIZE: %d\n", size_mine);
	printf("REAL SIZE: %d\n", size_real);
	/*
	printf("printf(\".%%*.*d.\", 8, 4, 123) => .%*.*d.\n", 8, 4, 123);
	printf("printf(\".%%0*.*d.\", 8, 4, 123) => .%0*.*d.\n", 8, 4, 123);
	*/
	return (0);
}
