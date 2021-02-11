/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:10:59 by besellem          #+#    #+#             */
/*   Updated: 2021/02/12 00:48:35 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*ret1;
	char	*ret2;
	int		mine_size;
	int		real_size;

	mine_size = ft_asprintf(&ret1, "[Hello World]");
	real_size = asprintf(&ret2, "[Hello World]");
	printf("mine[%d]: %s\n", mine_size, ret1);
	printf("real[%d]: %s\n", real_size, ret2);

	if (ft_strcmp(ret1, ret2) == 0 && mine_size == real_size)
		printf("\033[1;32mSUCCESS\033[0m\n");
	else
		printf("\033[1;31mFAILURE\033[0m\n");
	free(ret1);
	free(ret2);
	return (0);
}

// #include <fcntl.h>
// #include <unistd.h>
// #define BUF_SIZE 2110000

// int	main(int ac, char **av)
// {
// 	char	buf[BUF_SIZE + 1];
// 	int		fd;
// 	int		mine_size;
// 	int		real_size;

// 	if (ac != 2 || (fd = open(av[1], O_RDONLY)) == -1)
// 	{
// 		dprintf(2, "%s: Error\n", av[1]);
// 		return (1);
// 	}
// 	real_size = read(fd, buf, BUF_SIZE);
// 	mine_size = ft_printf(buf);
// 	// mine_size = printf("%s", buf);
// 	close(fd);

// 	printf("mine[%d]\n", mine_size);
// 	printf("real[%d]\n", real_size);
// 	if (mine_size == real_size)
// 		printf("\033[1;32mSUCCESS\033[0m\n");
// 	else
// 		printf("\033[1;31mFAILURE\033[0m\n");
// 	return (0);
// }
