/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:10:51 by besellem          #+#    #+#             */
/*   Updated: 2021/01/26 01:34:07 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

/*
** -- INCLUDES --
*/
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

/*
** -- DEFINES --
*/
# define PFT_BUFSIZ 1024

/*
** -- STRUCTS & TYPEDEFS --
*/
typedef	struct	s_pft
{
	int8_t		int8;
	uint8_t		uint8;
	int16_t		int16;
	uint16_t	uint16;
	int32_t		int32;
	uint32_t	uint32;
	int64_t		int64;
	uint64_t	uint64;
	ptrdiff_t	ptrdiff;
	size_t		sizet;
	uintmax_t	uintmax;
	char		buffer[PFT_BUFSIZ + 1];
	char		*ret;
	int			size;
	int			global_size;
}				t_pft;

/*
** -- PROTOTYPES --
*/
int				ft_vdprintf_internal(int fd, const char *fmt, va_list ap);

#endif
