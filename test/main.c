/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 23:10:19 by bensellem         #+#    #+#             */
/*   Updated: 2020/11/02 00:15:22 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main(void)
{
	char	*tab;
	int		size_real;
	int		size_mine;

	tab = "Hey there !";
	size_mine = ft_printf("MINE: int => [%*.*s]\n", -3, 10, tab);
	size_real = printf("REAL: int => [%*.*s]\n", -3, 10, tab);
	printf("MINE SIZE: %d\n", size_mine);
	printf("REAL SIZE: %d\n", size_real);
	return (0);
}
