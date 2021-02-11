/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf_internal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:26:26 by besellem          #+#    #+#             */
/*   Updated: 2021/02/12 00:14:37 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_no_conversion_opti(int fd, const char *fmt, t_pft *pft)
{
	size_t i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i++] == '%')
			return (0);
	}
	write(fd, fmt, i);
	pft->global_size = i;
	return (1);
}

static int	ft_buf(t_pft *pft, char c, int fd)
{
	if (pft->size < PFT_BUFSIZ)
	{
		pft->buffer[pft->size++] = c;
		pft->global_size++;
	}
	if (pft->size == PFT_BUFSIZ)
	{
		ft_putstr_fd(pft->buffer, fd);
		ft_bzero(pft->buffer, sizeof(char));
		pft->size = 0;
	}
	return (0);
}

int			ft_vdprintf_internal(int fd, const char *fmt, va_list ap)
{
	t_pft	pft;
	int		check;

	(void)ap;
	ft_bzero(&pft, sizeof(t_pft));
	if (ft_no_conversion_opti(fd, fmt, &pft))
		return (pft.global_size);
	while (*fmt)
	{
		check = 0;
		if (*fmt && *fmt == '%' && ++fmt)
			check = ft_get_conversion(&pft, fmt);
		else
			check = ft_buf(&pft, *fmt, fd);
		if (check)
		{
			ft_bzero(&pft, sizeof(t_pft));
			printf("%s:%d: ERROR\n", __FILE__, __LINE__);
			return (-1);
		}
		++fmt;
	}
	ft_putstr_fd(pft.ret, fd);
	ft_putstr_fd(pft.buffer, fd);
	return (pft.global_size);
}
