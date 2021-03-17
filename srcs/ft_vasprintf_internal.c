/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf_internal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 23:40:13 by besellem          #+#    #+#             */
/*   Updated: 2021/03/17 01:02:37 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write2buf_vasprintf(t_pft *pft, char *fmt)
{
	char	*new;
	size_t	size_tmp;

	if (pft->size < PFT_BUFSIZ && ++pft->global_size)
		pft->buffer[pft->size++] = *fmt;
	if (pft->size == PFT_BUFSIZ || ft_strlen(fmt) > 0)
	{
		size_tmp = PFT_BUFSIZ;
		if (pft->ret)
			size_tmp += ft_strlen(pft->ret);
		new = ft_calloc(size_tmp + 1, sizeof(char));
		if (!new)
			return (-1);
		if (pft->ret)
			ft_strlcat(new, pft->ret, size_tmp - PFT_BUFSIZ + 1);
		ft_strlcat(new, pft->buffer, size_tmp + 1);
		if (pft->ret)
			free(pft->ret);
		pft->ret = new;
		pft->size = 0;
		ft_bzero(pft->buffer, sizeof(char));
	}
	return (1);
}

static void	init_pft(t_pft *pft, va_list ap)
{
	ft_bzero(pft, sizeof(t_pft));
	pft->write2buf = write2buf_vasprintf;
	va_copy(pft->ap, ap);
}

int			ft_vasprintf_internal(char **ret, const char *fmt, va_list ap)
{
	t_pft pft;

	init_pft(&pft, ap);
	ft_printf_process(fmt, ap, &pft);
	*ret = pft.ret;
	return (pft.global_size);
}
