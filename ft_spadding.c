/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spadding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:46:16 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/13 19:07:09 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_spadding(t_printf *s)
{
	char	*pad;

	s->tmp_len = (ft_strlen(s->tmp) > s->width ? s->width : ft_strlen(s->tmp));
	if (!(pad = (char *)ft_calloc((s->width - s->tmp_len + 1), sizeof(char))))
		return ;
	if ((s->width > 0 && s->precision >= 0) || s->wstar == 1)
		pad = ft_memset(pad, ' ', s->width - s->tmp_len);
	if ((s->minus == 1 || s->neg_width == 1))
		s->tmp = ft_strjoin(s->tmp, pad);
	else
		s->tmp = ft_strjoin(pad, s->tmp);
	s->str = ft_strjoin(s->str, s->tmp);
	return ;
}

void		ft_sprecision(t_printf *s)
{
	char *pad;

	if (!(pad = (char *)ft_calloc(1, sizeof(char))))
		return ;
	if (s->precision < 0)
	{
		s->precision = 1;
		s->pstar = 1;
	}
	if ((s->pdot == 1 || s->dot == 1 || s->pstar) && s->neg_precision == 0)
		s->tmp = ft_strjoin_n(pad, s->tmp, s->precision);
	return ;
}
