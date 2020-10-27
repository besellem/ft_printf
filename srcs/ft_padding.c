/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:59:04 by besellem          #+#    #+#             */
/*   Updated: 2020/10/27 17:13:42 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_malloc_c(size_t size, char c)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = c;
		++i;
	}
	str[i] = '\0';
	return (str);
}

char	*zero_padding(long long nbr, int pad, char *base)
{
	char	*data;
	char	*tmp;
	char	*zeros;
	int		len;

	if (pad == 0 && nbr == 0)
		return (NULL);
	tmp = convert_base((nbr < 0 ? -nbr : nbr), base);
	zeros = ft_malloc_c(ft_strlen(tmp) > pad ? 0 : pad - ft_strlen(tmp), '0');
	len = ft_strlen(tmp) + (nbr < 0 ? 1 : 0) + (zeros ? ft_strlen(zeros) : 0);
	if (!(data = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	if (nbr < 0)
		ft_strncat(data, "-", 1);
	if (zeros)
		ft_strncat(data, zeros, ft_strlen(zeros));
	ft_strncat(data, tmp, ft_strlen(tmp));
	ft_free(2, tmp, zeros);
	return (data);
}
