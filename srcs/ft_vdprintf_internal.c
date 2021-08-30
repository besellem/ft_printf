/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf_internal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:26:26 by besellem          #+#    #+#             */
/*   Updated: 2021/08/30 14:45:46 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	ft_no_conversion_opti(int fd, const char *fmt, t_pft *pft)
{
	int	len;

	if (!fmt)
		return (TRUE);
	if (ft_strchr(fmt, '%'))
		return (FALSE);
	else
	{
		len = ft_strlen(fmt);
		if (SYSCALL_ERR == write(fd, fmt, len))
			return (ft_error(pft));
		else
			pft->global_size = len;
		return (TRUE);
	}
}

static int	write2buf_vdprintf(t_pft *pft, char *str)
{
	if (pft->size < PFT_BUFSIZ)
	{
		pft->buffer[pft->size++] = *str;
		++pft->global_size;
	}
	if (PFT_BUFSIZ == pft->size)
	{
		if (SYSCALL_ERR == write(pft->fd, pft->buffer, PFT_BUFSIZ))
			return (ft_error(pft));
		ft_bzero(pft->buffer, sizeof(char) * (PFT_BUFSIZ + 1));
		pft->size = 0;
	}
	return (TRUE);
}

static void	init_pft(int fd, t_pft *pft, va_list ap)
{
	ft_bzero(pft, sizeof(t_pft));
	pft->fd = fd;
	pft->write2buf = &write2buf_vdprintf;
	va_copy(pft->ap, ap);
}

int	ft_vdprintf_internal(int fd, const char *fmt, va_list ap)
{
	t_pft	pft;

	init_pft(fd, &pft, ap);
	if (ft_no_conversion_opti(fd, fmt, &pft))
		return (pft.global_size);
	ft_printf_process(fmt, &pft);
	if (PFT_ERR == pft.global_size
		|| SYSCALL_ERR == write(pft.fd, pft.buffer, pft.size))
	{
		return (ft_error(&pft));
	}
	return (pft.global_size);
}
