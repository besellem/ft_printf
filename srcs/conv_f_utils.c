/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:28:41 by besellem          #+#    #+#             */
/*   Updated: 2021/09/02 16:41:23 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	ft_put_float_head(t_pft *pft, double nb, const char *base)
{
	const double	base_len = (double)ft_strlen(base);
	char			tmp;

	if (trunc(nb / base_len) > 0.)
		ft_put_float_head(pft, nb / base_len, base);
	tmp = base[(size_t)fmod(nb, base_len)];
	pft->write2buf(pft, &tmp);
}

__unused static int	ft_round_str(double *nb, char *str, int precision)
{
	if (precision >= 0 && '9' == str[precision])
	{
		str[precision] = '0';
		if (0 == precision)
		{
			++(*nb);
			// if ((*nb - ft_trunc(*nb)) >= .5 && 1 == (int)ft_fmod(*nb, 2.))
			// 	++(*nb);
			// else if ((*nb - ft_trunc(*nb)) > .5 && 0 == (int)ft_fmod(*nb, 2.))
			// 	++(*nb);
			return (1);
		}
		return (ft_round_str(nb, str, precision - 1));
	}
	else if (precision > 0)
	{
		++str[precision];
		return (0);
	}
	else
		return (0);
}

static void	ft_fill_float_precision(double *nb, int precision, char *prec_tab)
{
	double	fp;
	int		i;

	fp = *nb - ft_trunc(*nb);
	i = 0;
	while (i < precision)
	{
		fp *= 10.;
		prec_tab[i] = (int)ft_fmod(fp, 10.) + 48;
		fp = fp - ft_trunc(fp);
		++i;
	}
	prec_tab[i] = '\0';
	if ((fp * 10.) >= 5.)
		ft_round_str(nb, prec_tab, precision - 1);
	// if ((*nb - ft_trunc(*nb)) >= .5 && 1 == (int)ft_fmod(*nb, 2.))
	// 	++(*nb);
	// else if ((*nb - ft_trunc(*nb)) > .5 && 0 == (int)ft_fmod(*nb, 2.))
	// 	++(*nb);
}

void		ft_put_float(t_pft *pft, double nb, const char *base)
{
	char	*prec_tab;

	nb = ft_copysign(nb, 0.);
	prec_tab = NULL;
	if (pft->conversion.precision >= 0)
	{
		prec_tab = malloc(sizeof(char) * (pft->conversion.precision + 1));
		if (!prec_tab)
		{
			printf("%s:%d: ERROR\n", __FILE__, __LINE__);
			return ((void)ft_error(pft));
		}
		ft_fill_float_precision(&nb, pft->conversion.precision, prec_tab);
	}
	ft_put_float_head(pft, nb, base);
	if ((0 == pft->conversion.precision && isflag(pft, FLAG_HTAG))
		|| pft->conversion.precision > 0)
		pft->write2buf_s(pft, ".");
	pft->write2buf_s(pft, prec_tab);
	ft_memdel((void **)&prec_tab);
}
