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

/*
size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	ft_putchar(unsigned int c, int *size)
{
	write(1, &c, 1);
	*size += 1;
}

void	ft_putstr(char *s, int *size)
{
	char *str;

	str = (char *)s;
	while (*str)
	{
		write(1, str++, 1);
		*size += 1;
	}
}

void	ft_putnbr(long long n, int *size)
{
	long long tmp;

	if (n < 0 && (n = -n))
		write(1, "-", 1);
	if (n / 10 > 0)
		ft_putnbr(n / 10, size);
	tmp = n % 10 + 48;
	write(1, &tmp, 1);
	*size += 1;
}

void	ft_print_hex_min(long long n, int *size)
{
	char *base;

	base = "0123456789abcdef";
	if (n >> 4 > 16)
		ft_print_hex_min(n >> 4, size);
	write(1, &base[n / 16], 1);
	write(1, &base[n % 16], 1);
	*size += 2;
}

void	ft_print_hex_maj(long long n, int *size)
{
	char *base;

	base = "0123456789ABCDEF";
	if (n >> 4 > 16)
		ft_print_hex_maj(n >> 4, size);
	write(1, &base[n / 16], 1);
	write(1, &base[n % 16], 1);
	*size += 2;
}

t_type	*ft_init_types(void)
{
	t_type *s;
	size_t i;

	if (!(s = (t_type *)malloc(sizeof(t_type) * (ft_strlen(TYPES) + 1))))
		return (NULL);
	i = 0;
	while (i < ft_strlen(TYPES))
	{
		s[i].type = TYPES[i];
		++i;
	}
	s[0].f = &ft_putchar;
	s[1].f = &ft_putstr;
	s[2].f = &ft_putnbr;
	s[3].f = &ft_print_hex_min;
	s[4].f = &ft_print_hex_maj;
	return (s);
}
*/

int		main(void)
{
	int size_real;
	int size_mine;
	char tab[] = "Hello !";

	size_mine = ft_printf("Hey %s%c %p\n", "there !", 48, &tab);
	size_real = printf("Hey %s%c %p\n", "there !", 48, &tab);
	printf("Mine Size: %d\n", size_mine);
	printf("Real Size: %d\n", size_real);
	/*
	size_real = printf("real: Tu as %% %d ans ! %s %c\n", 12035045, "Bravo !", 175);
	size_mine = ft_printf("mine: Tu as %% %d ans ! %s %c\n", 12035045, "Bravo !", 175);
	printf("mine size: %d\n", size_mine);
	printf("real size: %d\n", size_real);
	*/
	return (0);
}
