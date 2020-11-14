/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 23:10:19 by bensellem         #+#    #+#             */
/*   Updated: 2020/11/14 19:15:08 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main(void)
{
	char	*ret;
	char	*ret2;
	int		orig;
	int		mine;

	mine = ft_asprintf(&ret, "Hello World !");
	orig = asprintf(&ret2, "Hello World !");
	printf("MINE [%d]: [%s]\nREAL [%d]: [%s]\n", mine, ret, orig, ret2);

	if (ft_strcmp(ret, ret2) == 0)
		printf("\033[1;32mSUCCESS !\033[0m\n");
	else
		printf("\033[1;31mERROR\033[0m\n");
	free(ret);
	free(ret2);
	return (0);
}
