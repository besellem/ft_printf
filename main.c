/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:10:59 by besellem          #+#    #+#             */
/*   Updated: 2021/09/05 02:41:54 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#pragma clang diagnostic push
// #pragma clang diagnostic ignored "-Wformat-invalid-specifier"
// #pragma clang diagnostic ignored "-Wformat-security"
// #pragma clang diagnostic ignored "-Wformat"


uint64_t	__get_time_ms__(void)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * (uint64_t)1000) + (t.tv_usec / 1000));
}

#define TESTS_NBR  1000000U

/*
** float MASKS:
** 0x3fe0000000000000 || 0xbfe0000000000000;
** 0xc01fffffffffffff || 0x401fffffffffffff;
** 0x4fffffffffffff;
*/

int	main(__unused int ac, __unused char **av)
{
	__unused char	*ret1 = NULL;
	__unused char	*ret2 = NULL;
	__unused int	mine_size = 0;
	__unused int	real_size = 0;
	__unused double value = (ac > 1) ? strtod(av[1], NULL) : DBL_MIN;
	
	// printf("value: [%.10f]\n", value);

	__unused uint64_t	mine_start = __get_time_ms__();
	for (size_t i = 0; i < TESTS_NBR; ++i)
	{
		mine_size = ft_asprintf(&ret1, "[%.315f]", value);
		if (i + 1 < TESTS_NBR) { free(ret1); ret1 = NULL; }
	}
	__unused uint64_t	mine_end = __get_time_ms__();

	__unused uint64_t	real_start = __get_time_ms__();
	for (size_t i = 0; i < TESTS_NBR; ++i)
	{
		real_size = asprintf(&ret2, "[%.315f]", value);
		if (i + 1 < TESTS_NBR) { free(ret2); ret2 = NULL; }
	}
	__unused uint64_t	real_end = __get_time_ms__();
	
	
	__unused int			p = 0;
	__unused double			x = frexp(value, &p);
	__unused unsigned long	x_tmp = *(unsigned long *)&x;
	printf("hex: %f*(2^%d) [%#lx]\n", value, p, x_tmp);

	printf("mine[%2d] [%4llu ms]: %s\n", mine_size, (mine_end - mine_start), ret1);
	printf("real[%2d] [%4llu ms]: %s\n", real_size, (real_end - real_start), ret2);
	
	ft_printf("");			/// Check if ft_printf execute without errors
	ft_printf(NULL);		/// Check if ft_printf execute without errors

	if (ret1 && ret2 && 0 == strcmp(ret1, ret2) && mine_size == real_size)
		printf(B_GREEN "SUCCESS" CLR_COLOR "\n");
	else
		printf(B_RED "FAILURE" CLR_COLOR "\n");
	
	if (ret1) free(ret1);
	if (ret2) free(ret2);
	
	return (0);
}


// #define FD_REAL  "__real_printf_test_on_fd.txt"
// #define FD_MINE  "__mine_printf_test_on_fd.txt"

// #define BUF_SIZE 2110000

// int	main(int ac, char **av)
// {
// 	char	buf[BUF_SIZE + 1] = {0};
// 	int		fd;
// 	int		real_size, mine_size;
// 	int		real_fd, mine_fd;

// 	if (ac != 2 || (fd = open(av[1], O_RDONLY)) == -1)
// 	{
// 		dprintf(STDERR_FILENO, "%s: Error\n", av[1]);
// 		return (EXIT_FAILURE);
// 	}

// 	if (SYSCALL_ERR == (real_fd = open(FD_REAL, O_RDWR | O_CREAT | O_TRUNC, 0644)))
// 	{
// 		dprintf(STDERR_FILENO, "Error: %s\n", strerror(errno));
// 		return (EXIT_FAILURE);
// 	}
// 	if (SYSCALL_ERR == (mine_fd = open(FD_MINE, O_RDWR | O_CREAT | O_TRUNC, 0644)))
// 	{
// 		dprintf(STDERR_FILENO, "Error: %s\n", strerror(errno));
// 		return (EXIT_FAILURE);
// 	}

// 	read(fd, buf, BUF_SIZE);

// 	uint64_t	real_start = __get_time_ms__();
// 	real_size = dprintf(real_fd, "%-100s", buf);
// 	uint64_t	real_end = __get_time_ms__();
	
// 	uint64_t	mine_start = __get_time_ms__();
// 	mine_size = ft_dprintf(mine_fd, "%-100s", buf);
// 	uint64_t	mine_end = __get_time_ms__();
	
// 	close(fd);
// 	close(real_fd);
// 	close(mine_fd);

// 	printf("mine[%d] time[%llu ms]\n", mine_size, mine_end - mine_start);
// 	printf("real[%d] time[%llu ms]\n", real_size, real_end - real_start);
	
// 	if (mine_size == real_size)
// 		printf("\033[1;32mSUCCESS\033[0m\n");
// 	else
// 		printf("\033[1;31mFAILURE\033[0m\n");
	
// 	return (EXIT_SUCCESS);
// }

#pragma clang diagnostic pop
