/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 23:10:19 by bensellem         #+#    #+#             */
/*   Updated: 2020/10/27 00:41:30 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main(void)
{
	char	*tab;
	int		size_real;
	int		size_mine;

	tab = "Hey there !";
	size_mine = ft_printf("MINE: str => %.1s.\n", "Hello");
	size_real = printf("REAL: str => %.1s.\n", "Hello");
	printf("MINE SIZE: %d\n", size_mine);
	printf("REAL SIZE: %d\n", size_real);
	//	printf("%.3d", 42);
	return (0);
}
