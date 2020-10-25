/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 01:11:34 by besellem          #+#    #+#             */
/*   Updated: 2020/10/18 01:11:36 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_len(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_dup(const char *s1)
{
	char	*cpy;
	int		i;

	if (!(cpy = (char *)malloc(sizeof(char) * (ft_len(s1) + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		cpy[i] = s1[i];
	cpy[i] = '\0';
	return (cpy);
}

int		ft_ncmp(const char *s1, const char *s2, int n)
{
	int i;

	if (n <= 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}
