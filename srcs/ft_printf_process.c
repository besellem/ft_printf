/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 01:55:17 by besellem          #+#    #+#             */
/*   Updated: 2021/04/25 22:32:45 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#define PFT_CHARSET "$#* -+0123456789hljztL.sducpxXiobfgean%"
#define PFT_END_CONVERSION "sducpxXiobfgean"

// static void	get_arg_nbr(const char *fmt, t_pft *pft)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (fmt[i])
// 	{
// 		j = 0;
// 		if (fmt[i] == '%' && ++i)
// 		{
// 			while (fmt[i + j])
// 			{
// 				if (fmt[i + j] == '$' || fmt[i + j] == '%')
// 					break ;
// 				if (ft_strchr(PFT_END_CONVERSION, fmt[i + j]))
// 				{
// 					++pft->arg_nbr;
// 					break ;
// 				}
// 				if (fmt[i + j] == '*')
// 					++pft->arg_nbr;
// 				++j;
// 			}
// 		}
// 		i += 1 + j;
// 	}
// }

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
			printf("%s:%d: ERROR\n", __FILE__, __LINE__);
			return ;
		}
		fmt += check;
	}
}
