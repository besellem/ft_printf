/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:10:59 by besellem          #+#    #+#             */
/*   Updated: 2021/03/18 00:19:17 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	__attribute((unused)) t_conv	conversion;
	__attribute((unused)) char		*ret1;
	__attribute((unused)) char		*ret2;
	__attribute((unused)) int		mine_size;
	__attribute((unused)) int		real_size;

	// ft_printf("[Hello World !] [%d]", 123);
	mine_size = ft_asprintf(&ret1, "[Hello %s !] [%d] [%d]", "World", INT32_MIN, INT32_MAX);
	real_size = asprintf(&ret2, "[Hello %s !] [%d] [%d]", "World", INT32_MIN, INT32_MAX);
	printf("mine[%d]: %s\n", mine_size, ret1);
	printf("real[%d]: %s\n", real_size, ret2);
	
	ft_printf("");			/// Check if ft_printf execute without errors
	ft_printf(NULL);		/// Check if ft_printf execute without errors
	// printf("ft_printf() returned => [%d]\n", ft_printf(""));
	// printf("ft_printf() returned => [%d]\n", ft_printf("%d")); /// Throw Warning (Error with -Werror)

	// ft_bzero(&conversion, sizeof(t_conv));
	// conversion.flags |= flag_arg_nbr;
	// conversion.flags |= flag_precision;
	// conversion.flags |= flag_zero;
	// conversion.specifiers |= spec_ll;
	// printf("conversion.flags bef:  %d\n", conversion.flags);
	// conversion.flags &= ~flag_zero; 	// Remove flag_zero flag from conversion.flag
	// printf("conversion.flags aft:  %d\n", conversion.flags);
	// printf("conversion.specifiers: %d\n", conversion.specifiers);

	if (ret1 && ret2 && ft_strcmp(ret1, ret2) == 0 && mine_size == real_size)
		printf(B_GREEN"SUCCESS\n"CLR_COLOR);
	else
		printf(B_RED"FAILURE\n"CLR_COLOR);
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
