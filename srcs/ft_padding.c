/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:59:04 by besellem          #+#    #+#             */
/*   Updated: 2020/11/01 23:56:44 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*space_padding(char *data, int padding)
{
	char	*spaces;
	int		data_len;
	int		len;

	data_len = data ? ft_strlen(data) : 0;
	len = data_len > padding ? 0 : padding - data_len;
	if (len <= 0)
		return (NULL);
	spaces = ft_malloc_c(len, ' ');
	return (spaces);
}

char	*zero_padding(long long nbr, int pad, char *base)
{
	char	*data;
	char	*tmp;
	char	*z;
	int		len;

	tmp = convert_base((nbr < 0 ? -nbr : nbr), base);
	len = nbr < 0 ? 1 : 0;
	len = pad - len > (int)ft_strlen(tmp) ? pad - len - ft_strlen(tmp) : 0;
	z = ft_malloc_c(len, '0');
	len = (int)ft_strlen(tmp) > pad ? ft_strlen(tmp) : pad;
	if (!(data = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	if (nbr < 0)
		ft_strncat(data, "-", 1);
	if (z)
		ft_strncat(data, z, ft_strlen(z));
	ft_strncat(data, tmp, ft_strlen(tmp));
	ft_free(2, tmp, z);
	return (data);
}

char	*prec_padding(long long nbr, int pad, char *base)
{
	char	*data;
	char	*tmp;
	char	*z;
	int		len;

	if (pad == 0 && nbr == 0)
		return (NULL);
	tmp = convert_base((nbr < 0 ? -nbr : nbr), base);
	z = ft_malloc_c((int)ft_strlen(tmp) > pad ? 0 : pad - ft_strlen(tmp), '0');
	len = (int)ft_strlen(tmp) + (nbr < 0 ? 1 : 0) + (z ? ft_strlen(z) : 0);
	if (!(data = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	if (nbr < 0)
		ft_strncat(data, "-", 1);
	if (z)
		ft_strncat(data, z, ft_strlen(z));
	ft_strncat(data, tmp, ft_strlen(tmp));
	ft_free(2, tmp, z);
	return (data);
}
