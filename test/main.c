/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 23:10:19 by bensellem         #+#    #+#             */
/*   Updated: 2020/10/27 17:16:57 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main(void)
{
	char	*tab;
	int		size_real;
	int		size_mine;

	tab = "Hey there !";
	size_mine = ft_printf("MINE: hex => %.2X.\n", 10);
	size_real = printf("REAL: hex => %.2X.\n", 10);
	printf("MINE SIZE: %d\n", size_mine);
	printf("REAL SIZE: %d\n", size_real);
	// printf(".% d.\n", 12);
	return (0);
}
