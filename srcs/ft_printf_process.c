/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 01:55:17 by besellem          #+#    #+#             */
/*   Updated: 2021/03/17 21:12:38 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_error(t_pft *pft)
{
	if (pft->ret)
		free(pft->ret);
	ft_bzero(pft, sizeof(t_pft));
}

void	ft_printf_process(const char *fmt, t_pft *pft)
{
	int	check;

	while (*fmt)
	{
		check = 0;
		if (*fmt && *fmt == '%' && ++fmt)
			check = ft_parse_conversion(pft, fmt);
		else
			check = pft->write2buf(pft, (char *)fmt);
		if (check == -1)
		{
			ft_error(pft);
			printf("%s:%d: ERROR\n", __FILE__, __LINE__);
			pft->global_size = -1;
			return ;
		}
		fmt += check;
	}
}
