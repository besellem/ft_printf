/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:10:59 by besellem          #+#    #+#             */
/*   Updated: 2021/08/23 02:40:27 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-security"


uint64_t	__get_time_ms__(void)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * (uint64_t)1000) + (t.tv_usec / 1000));
}


// int	main(void)
// {
// 	__attribute((unused)) t_conv	conversion;
// 	__attribute((unused)) char		*ret1;
// 	__attribute((unused)) char		*ret2;
// 	__attribute((unused)) int		mine_size;
// 	__attribute((unused)) int		real_size;

// 	// ft_printf("[Hello World !] [%d]", 123);
// 	mine_size = ft_asprintf(&ret1, "[%10d]", -123);
// 	real_size = asprintf(&ret2, "[%10d]", -123);
// 	printf("mine[%d]: %s\n", mine_size, ret1);
// 	printf("real[%d]: %s\n", real_size, ret2);

// 	// ft_dprintf(2, "[Hello %s !] [%d] [%d]\n", "World", INT32_MIN, INT32_MAX);
// 	// dprintf(2, "[Hello %s !] [%d] [%d]\n", "World", INT32_MIN, INT32_MAX);
	
// 	ft_printf("");			/// Check if ft_printf execute without errors
// 	ft_printf(NULL);		/// Check if ft_printf execute without errors
// 	// printf("ft_printf() returned => [%d]\n", ft_printf(""));
// 	// printf("ft_printf() returned => [%d]\n", ft_printf("%d")); /// Throw Warning (Error with -Werror)

// 	// ft_bzero(&conversion, sizeof(t_conv));
// 	// conversion.flags |= flag_arg_nbr;
// 	// conversion.flags |= flag_precision;
// 	// conversion.flags |= flag_zero;
// 	// conversion.specifiers |= spec_ll;
// 	// printf("conversion.flags bef:  %d\n", conversion.flags);
// 	// conversion.flags &= ~flag_zero; 	// Remove flag_zero flag from conversion.flag
// 	// printf("conversion.flags aft:  %d\n", conversion.flags);
// 	// printf("conversion.specifiers: %d\n", conversion.specifiers);

// 	if (ret1 && ret2 && ft_strcmp(ret1, ret2) == 0 && mine_size == real_size)
// 		printf(B_GREEN"SUCCESS\n"CLR_COLOR);
// 	else
// 		printf(B_RED"FAILURE\n"CLR_COLOR);
// 	if (ret1)
// 		free(ret1);
// 	if (ret2)
// 		free(ret2);
// 	return (0);
// }


#define FD_REAL  "__real_printf_test_on_fd.txt"
#define FD_MINE  "__mine_printf_test_on_fd.txt"

#define BUF_SIZE 2110000

int	main(int ac, char **av)
{
	char	buf[BUF_SIZE + 1] = {0};
	int		fd;
	int		real_size, mine_size;
	int		real_fd, mine_fd;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) == -1)
	{
		dprintf(STDERR_FILENO, "%s: Error\n", av[1]);
		return (EXIT_FAILURE);
	}

	if (SYSCALL_ERR == (real_fd = open(FD_REAL, O_RDWR | O_CREAT | O_TRUNC, 0644)))
	{
		dprintf(STDERR_FILENO, "Error: %s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	if (SYSCALL_ERR == (mine_fd = open(FD_MINE, O_RDWR | O_CREAT | O_TRUNC, 0644)))
	{
		dprintf(STDERR_FILENO, "Error: %s\n", strerror(errno));
		return (EXIT_FAILURE);
	}

	read(fd, buf, BUF_SIZE);

	uint64_t	real_start = __get_time_ms__();
	real_size = dprintf(real_fd, "%-100s", buf);
	uint64_t	real_end = __get_time_ms__();
	
	uint64_t	mine_start = __get_time_ms__();
	mine_size = ft_dprintf(mine_fd, "%-100s", buf);
	uint64_t	mine_end = __get_time_ms__();
	
	close(fd);
	close(real_fd);
	close(mine_fd);

	printf("mine[%d] time[%llu ms]\n", mine_size, mine_end - mine_start);
	printf("real[%d] time[%llu ms]\n", real_size, real_end - real_start);
	
	if (mine_size == real_size)
		printf("\033[1;32mSUCCESS\033[0m\n");
	else
		printf("\033[1;31mFAILURE\033[0m\n");
	
	return (EXIT_SUCCESS);
}

#pragma clang diagnostic pop
