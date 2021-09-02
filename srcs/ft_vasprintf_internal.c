/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf_internal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 23:40:13 by besellem          #+#    #+#             */
/*   Updated: 2021/09/02 19:05:07 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	ft_no_conversion_opti(const char *fmt, t_pft *pft)
{
	size_t	fmt_len;

	if (ft_strchr(fmt, '%'))
		return (FALSE);
	else
	{
		fmt_len = ft_strlen(fmt);
		pft->ret = (char *)malloc(sizeof(char) * (fmt_len + 1));
		if (!pft->ret)
			return (ft_error(pft));
		else
		{
			ft_memcpy(pft->ret, fmt, fmt_len);
			pft->ret[fmt_len] = '\0';
			pft->global_size = (int)fmt_len;
		}
		return (TRUE);
	}
}

static int	write2buf_vasprintf(t_pft *pft, char *fmt)
{
	char			*new;
	size_t			tmp_siz;
	const size_t	ret_siz = pft->global_size - pft->size;

	if (pft->size < PFT_BUFSIZ)
	{
		pft->buffer[pft->size++] = *fmt;
		++pft->global_size;
	}
	if (PFT_BUFSIZ == pft->size)
	{
		tmp_siz = PFT_BUFSIZ;
		if (pft->ret)
			tmp_siz += ret_siz;
		new = (char *)malloc(sizeof(char) * (tmp_siz + 1));
		if (!new)
			return (ft_error(pft));
		if (pft->ret)
			ft_memcpy(new, pft->ret, tmp_siz - PFT_BUFSIZ + 1);
		ft_memcpy(new + ret_siz, pft->buffer, tmp_siz - ret_siz + 1);
		pft->ret = (free(pft->ret), new);
		pft->size = 0;
		ft_bzero(pft->buffer, sizeof(char) * (PFT_BUFSIZ + 1));
	}
	return (TRUE);
}

/*
** Optimization done here by doing a kind of realloc if the size of the `str'
** is bigger than `PFT_BUFSIZ'.
*/
static int	write2buf_str_vasprintf(t_pft *pft, const char *str)
{
	char			*new;
	const size_t	_size = ft_strlen(str);
	const size_t	_ret_size = pft->global_size - pft->size;

	if (_size < (PFT_BUFSIZ - (size_t)pft->size))
	{
		ft_memcpy(pft->buffer + pft->size, str, _size);
		pft->size += _size;
	}
	else
	{
		new = malloc(sizeof(char) * (pft->global_size + _size + 1));
		if (!new)
			return (ft_error(pft));
		if (pft->ret)
			ft_memcpy(new, pft->ret, _ret_size);
		ft_memcpy(new + _ret_size, pft->buffer, pft->size);
		ft_memcpy(new + pft->global_size, str, _size);
		new[pft->global_size + _size] = '\0';
		ft_bzero(pft->buffer, sizeof(char) * (PFT_BUFSIZ + 1));
		pft->size = 0;
		free(pft->ret), (pft->ret = new);
	}
	return ((pft->global_size += _size), TRUE);
}

static int	vasprintf_last_alloc(t_pft *pft)
{
	char			*new;
	const size_t	size_ret = pft->global_size - pft->size;

	new = (char *)malloc(sizeof(char) * (pft->global_size + 1));
	if (!new)
		return (ft_error(pft));
	if (pft->ret)
		ft_memcpy(new, pft->ret, size_ret);
	ft_memcpy(new + size_ret, pft->buffer, pft->size);
	new[pft->global_size] = '\0';
	free(pft->ret);
	pft->ret = new;
	return (TRUE);
}

int	ft_vasprintf_internal(char **ret, const char *fmt, va_list ap)
{
	t_pft	pft;

	ft_bzero(&pft, sizeof(t_pft));
	pft.write2buf = &write2buf_vasprintf;
	pft.write2buf_s = &write2buf_str_vasprintf;
	va_copy(pft.ap, ap);
	if (!fmt || !ret)
		return (ft_error(&pft));
	if (ft_no_conversion_opti(fmt, &pft))
	{
		*ret = pft.ret;
		return (pft.global_size);
	}
	ft_printf_process(fmt, &pft);
	if (PFT_ERR == pft.global_size || SYSCALL_ERR == vasprintf_last_alloc(&pft))
		return (ft_error(&pft));
	*ret = pft.ret;
	return (pft.global_size);
}
