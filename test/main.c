/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bensellem <bensellem@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 23:10:19 by bensellem         #+#    #+#             */
/*   Updated: 2020/10/16 16:45:36 by bensellem        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(void)
{
	char	*tab;
	int		size_real;
	int		size_mine;

	tab = "Hello !";
	size_mine = ft_printf("MINE: string => %s. char => '%c'. ptr => %p. int => %d%%.\n", "Hey there !", 98, &tab, -2147483647);
	size_real = printf("REAL: string => %s. char => '%c'. ptr => %p. int => %d%%.\n", "Hey there !", 98, &tab, -2147483647);
	printf("MINE SIZE: %d\n", size_mine);
	printf("REAL SIZE: %d\n", size_real);
	return (0);
}
