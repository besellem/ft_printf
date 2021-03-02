/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf_internal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 23:40:13 by besellem          #+#    #+#             */
/*   Updated: 2021/03/02 22:51:58 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_error(t_pft *pft)
{
	if (pft->ret)
		free(pft->ret);
	ft_bzero(pft, sizeof(t_pft));
}

static int	ft_asbuf(t_pft *pft, const char *fmt)
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
	return (0);
}

int			ft_vasprintf_internal(char **ret, const char *fmt, va_list ap)
{
	t_pft	pft;
	int		check;

	(void)ap;
	ft_bzero(&pft, sizeof(t_pft));
	while (*fmt)
	{
		check = 0;
		if (*fmt && *fmt == '%' && ++fmt)
			check = ft_get_conversion(&pft, fmt);
		else
			check = ft_asbuf(&pft, fmt);
		if (check)
		{
			ft_error(&pft);
			printf("%s:%d: ERROR\n", __FILE__, __LINE__);
			return (-1);
		}
		++fmt;
	}
	*ret = pft.ret;
	return (pft.global_size);
}
