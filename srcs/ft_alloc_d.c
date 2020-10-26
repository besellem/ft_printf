/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:45:02 by besellem          #+#    #+#             */
/*   Updated: 2020/10/27 00:14:26 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*nzero(int n)
{
	char	*zeros;
	int		i;

	if (n <= 0 || !(zeros = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = -1;
	while (++i < n)
		zeros[i] = '0';
	zeros[i] = '\0';
	return (zeros);
}

static void	add_zeros(t_data **s, t_indicators table, va_list ap)
{
	char		*data;
	char		*nbr;
	char		*zeros;
	long long	tmp;
	int			len;

	tmp = va_arg(ap, int);
	if (table.dot == 0 && tmp == 0)
		return ;
	nbr = convert_base(tmp < 0 ? -tmp : tmp, "0123456789");
	zeros = nzero(ft_strlen(nbr) > table.dot ? 0 : table.dot - ft_strlen(nbr));
	len = ft_strlen(nbr) + (tmp < 0 ? 1 : 0) + (zeros ? ft_strlen(zeros) : 0);
	if (!(data = (char *)malloc(sizeof(char) * (len + 1))))
	{
		ft_free(2, zeros, nbr);
		return ;
	}
	*data = '\0';
	if (tmp < 0)
		ft_strncat(data, "-", 1);
	if (zeros)
		ft_strncat(data, zeros, ft_strlen(zeros));
	ft_strncat(data, nbr, ft_strlen(nbr));
	ft_lstd_add(s, ft_lstd_new(data, ft_strlen(data)));
	ft_free(3, zeros, nbr, data);
}

void		ft_alloc_d(t_data **s, t_indicators table, va_list ap)
{
	char *data;

	if (table.dot != -1)
	{
		add_zeros(s, table, ap);
		return ;
	}
	data = convert_base(va_arg(ap, int), "0123456789");
	ft_lstd_add(s, ft_lstd_new(data, ft_strlen(data)));
	free(data);
}
