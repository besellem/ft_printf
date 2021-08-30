/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf_internal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 23:40:13 by besellem          #+#    #+#             */
/*   Updated: 2021/08/30 14:53:49 by besellem         ###   ########.fr       */
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
	const size_t	ret_siz = ft_strlen(pft->ret);

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

static int	vasprintf_ultimate_realloc(t_pft *pft)
{
	char			*new;
	const size_t	size_ret = ft_strlen(pft->ret);
	const size_t	size_buf = ft_strlen(pft->buffer);

	new = (char *)malloc(sizeof(char) * (size_ret + size_buf + 1));
	if (!new)
		return (ft_error(pft));
	if (pft->ret)
		ft_memcpy(new, pft->ret, size_ret);
	ft_memcpy(new + size_ret, pft->buffer, size_buf);
	new[size_ret + size_buf] = '\0';
	free(pft->ret);
	pft->ret = new;
	return (TRUE);
}

static void	init_pft(t_pft *pft, va_list ap)
{
	ft_bzero(pft, sizeof(t_pft));
	pft->write2buf = &write2buf_vasprintf;
	va_copy(pft->ap, ap);
}

int	ft_vasprintf_internal(char **ret, const char *fmt, va_list ap)
{
	t_pft	pft;

	init_pft(&pft, ap);
	if (!fmt || !ret)
		return (ft_error(&pft));
	if (ft_no_conversion_opti(fmt, &pft))
	{
		*ret = pft.ret;
		return (pft.global_size);
	}
	ft_printf_process(fmt, &pft);
	if (PFT_ERR == pft.global_size
		|| SYSCALL_ERR == vasprintf_ultimate_realloc(&pft))
	{
		return (ft_error(&pft));
	}
	*ret = pft.ret;
	return (pft.global_size);
}
