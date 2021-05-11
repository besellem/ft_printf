/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf_internal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 23:40:13 by besellem          #+#    #+#             */
/*   Updated: 2021/05/11 20:26:00 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	ft_no_conversion_opti(const char *fmt, t_pft *pft)
{
	const size_t	fmt_len = ft_strlen(fmt);

	if (ft_strchr(fmt, '%'))
		return (0);
	else
	{
		pft->ret = ft_calloc(fmt_len + 1, sizeof(char));
		if (!pft->ret)
			return (ft_error(pft));
		else
		{
			ft_memcpy(pft->ret, fmt, fmt_len);
			pft->global_size = (int)fmt_len;
		}
		return (1);
	}
}

static int	write2buf_vasprintf(t_pft *pft, char *fmt)
{
	char	*new;
	size_t	size_tmp;

	if (pft->size < PFT_BUFSIZ)
	{
		pft->buffer[pft->size++] = *fmt;
		++pft->global_size;
	}
	if (pft->size == PFT_BUFSIZ)
	{
		size_tmp = PFT_BUFSIZ;
		if (pft->ret)
			size_tmp += ft_strlen(pft->ret);
		new = ft_calloc(size_tmp + 1, sizeof(char));
		if (!new)
			return (ft_error(pft));
		if (pft->ret)
			ft_strlcat(new, pft->ret, size_tmp - PFT_BUFSIZ + 1);
		ft_strlcat(new, pft->buffer, size_tmp + 1);
		if (pft->ret)
			free(pft->ret);
		pft->ret = new;
		pft->size = 0;
		ft_bzero(pft->buffer, sizeof(char) * (PFT_BUFSIZ + 1));
	}
	return (1);
}

static int	vasprintf_ultimate_realloc(t_pft *pft)
{
	char			*new;
	size_t			size_tmp;
	const size_t	size_ret = ft_strlen(pft->ret);
	const size_t	size_buf = ft_strlen(pft->buffer);

	size_tmp = size_ret + size_buf;
	new = ft_calloc(size_tmp + 1, sizeof(char));
	if (!new)
		return (ft_error(pft));
	if (pft->ret)
		ft_strlcat(new, pft->ret, size_ret + 1);
	ft_strlcat(new, pft->buffer, size_ret + size_buf + 1);
	if (pft->ret)
		free(pft->ret);
	pft->ret = new;
	return (1);
}

static void	init_pft(t_pft *pft, va_list ap)
{
	ft_bzero(pft, sizeof(t_pft));
	pft->write2buf = write2buf_vasprintf;
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
	if (pft.global_size == -1 || vasprintf_ultimate_realloc(&pft) == -1)
		return (ft_error(&pft));
	*ret = pft.ret;
	return (pft.global_size);
}
