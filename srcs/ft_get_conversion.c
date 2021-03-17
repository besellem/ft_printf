/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 23:42:12 by besellem          #+#    #+#             */
/*   Updated: 2021/03/17 02:00:28 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_int(t_pft *pft, int64_t nb, const char *base)
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

void	ft_put_uint(t_pft *pft, uint64_t nb, const char *base)
{
	const size_t	base_len = ft_strlen(base);
	char			tmp;

	if (nb / base_len > 0)
		ft_put_uint(pft, nb / base_len, base);
	tmp = base[nb % base_len];
	pft->write2buf(pft, &tmp);
}

void	*get_va_arg_idx(va_list ap, int idx)
{
	va_list	tmp;
	void	*arg;
	int		i;

	va_copy(tmp, ap);
	i = 0;
	while (i < idx)
	{
		arg = va_arg(tmp, void *);
		++i;
	}
	return (arg);
}

void	write2buf_str(t_pft *pft, char *str)
{
	int i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		pft->write2buf(pft, &str[i]);
		++i;
	}
}

void	conv_p(t_pft *pft)
{
	const t_uint64 nb = va_arg(pft->ap, unsigned long);

	write2buf_str(pft, "0x");
	ft_put_uint(pft, nb, "0123456789abcdef");
}

void	conv_x_min(t_pft *pft)
{
	const t_uint64 nb = ft_get_val_uint(pft);

	ft_put_uint(pft, nb, "0123456789abcdef");
}

void	conv_x_max(t_pft *pft)
{
	const t_uint64 nb = ft_get_val_uint(pft);

	ft_put_uint(pft, nb, "0123456789ABCDEF");
}

void	conv_o(t_pft *pft)
{
	const t_uint64 nb = ft_get_val_uint(pft);

	ft_put_uint(pft, nb, "01234567");
}

void	conv_u(t_pft *pft)
{
	const t_uint64 nb = ft_get_val_uint(pft);

	ft_put_uint(pft, nb, "0123456789");
}

void	conv_d(t_pft *pft)
{
	char			sign;
	const t_int64	nb = ft_get_val_int(pft, &sign);

	if (nb < 0)
		pft->write2buf(pft, "-");
	while (pft->conversion.precision-- > 0)
		pft->write2buf(pft, "0");
	ft_put_int(pft, nb, "0123456789");
}

void	conv_i(t_pft *pft)
{
	conv_d(pft);
}

void	conv_c(t_pft *pft)
{
	conv_d(pft);
}

int		ft_get_conversion(t_pft *pft, char conv)
{
	const t_conv_ptrs	conv_ptrs[] = {
		{'c', conv_c}, {'d', conv_d}, {'i', conv_i}, {'u', conv_u},
		{'o', conv_o}, {'p', conv_p}, {'x', conv_x_min}, {'X', conv_x_max},
		// {'b', conv_b}, {'f', conv_f}, {'g', conv_g}, {'e', conv_e},
		// {'a', conv_a}, {'n', conv_n}, {'%', conv_perc},
		{0, NULL}
	};
	int			i;

	i = 0;
	while (conv_ptrs[i].conversion)
	{
		if (conv_ptrs[i].conversion == conv)
		{
			conv_ptrs[i].f(pft);
			return (1);
		}
		++i;
	}
	return (0);
}

int		check_flags(t_pft *pft, const char *fmt)
{
	int ret;

	ret = 1;
	if (*fmt == '.')
		pft->conversion.flags |= flag_precision;
	return (ret);
}

int		ft_parse_conversion(t_pft *pft, const char *fmt)
{
	int i;

	i = 0;
	ft_bzero(&pft->conversion, sizeof(t_conv));
	while (ft_get_conversion(pft, fmt[i]) == 0)
	{
		if (check_flags(pft, fmt) == 0)
			return (-1);
		++i;
	}
	return (i + 1);
}
