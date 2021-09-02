/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf_internal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:26:26 by besellem          #+#    #+#             */
/*   Updated: 2021/09/02 16:33:04 by besellem         ###   ########.fr       */
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

/*
** Optimization done here by writing `PFT_BUFSIZ' bytes while the length of the
** string is bigger than this size.
** This prevents multiple copies of the data into the buffer, followed by a
** writing of that buffer, itself followed by a call to `memset' to clean the
** latter, all this being unnecessary.
*/
static int	write2buf_str_vdprintf(t_pft *pft, const char *str)
{
	const size_t	_size = ft_strlen(str);
	size_t			_size_res;

	if (_size < (PFT_BUFSIZ - (size_t)pft->size))
	{
		ft_memcpy(pft->buffer + pft->size, str, _size);
		pft->size += _size;
	}
	else
	{
		ft_memcpy(pft->buffer + pft->size, str, PFT_BUFSIZ - pft->size);
		if (SYSCALL_ERR == write(pft->fd, pft->buffer, PFT_BUFSIZ))
			return (ft_error(pft));
		_size_res = _size - (PFT_BUFSIZ - pft->size);
		ft_bzero(pft->buffer, sizeof(char) * (PFT_BUFSIZ + 1));
		while (_size_res >= PFT_BUFSIZ)
		{
			if (write(pft->fd, str + (_size - _size_res), PFT_BUFSIZ) < 0)
				return (ft_error(pft));
			_size_res -= PFT_BUFSIZ;
		}
		pft->size = _size_res;
		ft_memcpy(pft->buffer, str + (_size - _size_res), _size_res);
	}
	return ((pft->global_size += _size), TRUE);
}

int	ft_vdprintf_internal(int fd, const char *fmt, va_list ap)
{
	t_pft	pft;

	ft_bzero(&pft, sizeof(t_pft));
	pft.fd = fd;
	pft.write2buf = &write2buf_vdprintf;
	pft.write2buf_s = &write2buf_str_vdprintf;
	va_copy(pft.ap, ap);
	if (ft_no_conversion_opti(fd, fmt, &pft))
		return (pft.global_size);
	ft_printf_process(fmt, &pft);
	if (PFT_ERR == pft.global_size || write(pft.fd, pft.buffer, pft.size) < 0)
		return (ft_error(&pft));
	return (pft.global_size);
}
