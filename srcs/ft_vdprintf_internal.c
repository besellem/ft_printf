/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf_internal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:26:26 by besellem          #+#    #+#             */
/*   Updated: 2021/03/03 01:59:27 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_no_conversion_opti(int fd, const char *fmt, t_pft *pft)
{
	int len;

	if (!fmt)
		return (1);
	if (ft_strchr(fmt, '%'))
		return (0);
	else
	{
		len = ft_strlen(fmt);
		if (write(fd, fmt, len) == -1)
			pft->global_size = -1;
		else
			pft->global_size = len;
		return (1);
	}
}

static int	write2buf_vdprintf(t_pft *pft, char *str)
{
	if (pft->size < PFT_BUFSIZ)
	{
		pft->buffer[pft->size++] = *str;
		++pft->global_size;
	}
	if (pft->size == PFT_BUFSIZ)
	{
		ft_putstr_fd(pft->buffer, pft->fd);
		ft_bzero(pft->buffer, sizeof(char));
		pft->size = 0;
	}
	return (1);
}

static void	init_pft(int fd, t_pft *pft)
{
	ft_bzero(pft, sizeof(t_pft));
	pft->fd = fd;
	pft->write2buf = write2buf_vdprintf;
}

int			ft_vdprintf_internal(int fd, const char *fmt, va_list ap)
{
	t_pft	pft;

	init_pft(fd, &pft);
	if (ft_no_conversion_opti(fd, fmt, &pft))
		return (pft.global_size);
	ft_printf_process(fmt, ap, &pft);
	ft_putstr_fd(pft.ret, fd);
	ft_putstr_fd(pft.buffer, fd);
	return (pft.global_size);
}
