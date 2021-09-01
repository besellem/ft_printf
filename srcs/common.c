/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:50:16 by besellem          #+#    #+#             */
/*   Updated: 2021/09/01 17:23:34 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	write2buf_str(t_pft *pft, char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		pft->write2buf(pft, &str[i]);
		++i;
	}
}

int	ft_error(t_pft *pft)
{
	if (pft->ret)
		ft_memdel((void **)&pft->ret);
	pft->global_size = PFT_ERR;
	return (PFT_ERR);
}

int			ft_uint_base(uintmax_t n, int base)
{
	int	len;

	len = 1;
	while (n / base > 0)
	{
		n /= base;
		++len;
	}
	return (len);
}

// If nb < 0, the sign is handled outside this function
void	ft_put_int(t_pft *pft, intmax_t nb, const char *base)
{
	const size_t	base_len = ft_strlen(base);
	char			tmp;

	if (nb < 0)
		nb = -nb;
	if (nb / base_len > 0)
		ft_put_int(pft, nb / base_len, base);
	tmp = base[nb % base_len];
	pft->write2buf(pft, &tmp);
}

void	ft_put_uint(t_pft *pft, uintmax_t nb, const char *base)
{
	const size_t	base_len = ft_strlen(base);
	char			tmp;

	if (nb / base_len > 0)
		ft_put_uint(pft, nb / base_len, base);
	tmp = base[nb % base_len];
	pft->write2buf(pft, &tmp);
}
