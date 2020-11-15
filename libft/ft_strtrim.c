/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 21:53:35 by besellem          #+#    #+#             */
/*   Updated: 2020/09/13 22:06:53 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	is_set(char c, char const *set)
{
	unsigned int i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

static unsigned int	head_index(char const *str, char const *set)
{
	unsigned int i;

	i = 0;
	while (str[i] && is_set(str[i], set))
		++i;
	return (i);
}

static unsigned int	tail_index(char const *str, char const *set)
{
	unsigned int i;

	i = ft_strlen(str);
	while (i-- > 0)
		if (!is_set(str[i], set))
			return (i);
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char			*new;
	unsigned int	head;
	unsigned int	tail;
	unsigned int	i;

	head = head_index(s1, set);
	tail = tail_index(s1, set);
	if (!(new = (char *)malloc(sizeof(char) * (tail - head + 1))))
		return (NULL);
	i = 0;
	while (head <= tail)
		new[i++] = s1[head++];
	new[i] = '\0';
	return (new);
}
