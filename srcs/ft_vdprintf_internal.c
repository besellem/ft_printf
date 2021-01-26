/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf_internal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:26:26 by besellem          #+#    #+#             */
/*   Updated: 2021/01/26 01:38:59 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_error(t_pft *pft)
{
	if (pft->ret)
		free(pft->ret);
	ft_memset(pft, 0, sizeof(t_pft));
	return (-1);
}

int		ft_write_in_buffer(t_pft *pft, char c)
{
	char	*new;
	size_t	size_tmp;

	if (pft->size++ < PFT_BUFSIZ)
		pft->buffer[pft->global_size++] = c;
	else if (pft->size == PFT_BUFSIZ)
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
	else
		return (1);
	return (0);
}

int		ft_vdprintf_internal(int fd, const char *fmt, va_list ap)
{
	t_pft	pft;
	int		check;

	ft_memset(&pft, 0, sizeof(t_pft));
	while (*fmt)
	{
		check = 0;
		if (*fmt && *fmt == '%' && ++fmt)
			check = ft_conversion(&pft, fmt);
		else
			check = ft_write_in_buffer(&pft, *fmt);
		if (check)
		{
			ft_error(&pft);
			return (-1);
		}
		++fmt;
	}
	return (pft.size);
}
