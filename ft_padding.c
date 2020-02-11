/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:21:46 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/11 14:36:58 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_padding(t_printf *s)
{
	char *pad;

	s->tmp_len = ft_strlen(s->tmp);
	s->tmp_len = (s->tmp_len > s->width ? s->width : s->tmp_len);
	if (!(pad = (char *)ft_calloc((s->width - s->tmp_len + 1), sizeof(char))))
		return ;
	if (s->zero == 1 && s->star != 2)
		pad = ft_memset(pad, '0', s->width - s->tmp_len);
	else if (s->width < s->precision)
		pad = ft_memset(pad, '0', ((s->precision - ft_strlen(s->tmp) + s->sign
		> 0 ? s->precision - ft_strlen(s->tmp) + s->sign : 0)));
	else if (s->width > 0)
		pad = ft_memset(pad, ' ', s->width - s->tmp_len);
	if (s->minus == 1 || s->star == 2)
		s->tmp = ft_strjoin(s->tmp, pad);
	else
		s->tmp = ft_strjoin(pad, s->tmp);
	if (s->sign == 1)
		s->tmp = ft_strjoin("-", s->tmp);
	s->str = ft_strjoin(s->str, s->tmp);
	return ;
}

void		ft_precision(t_printf *s)
{
	char *pad;

	ft_get_precision(s);
	if (!(pad = (char *)ft_calloc(1, sizeof(char))))
		return ;
	if (s->precision < 0)
		s->precision = 0;
	if (s->dot == 1)
		s->tmp = ft_strjoin_n(pad, s->tmp, s->precision);
	return ;
}

void		ft_padding_precision(t_printf *s)
{
	char	*pad;
	int		l;

	l = 0;
	if ((s->precision > l - s->sign && s->dot == 1) ||
		(s->wstar == 1 || s->pstar == 0))
	{
		l = ft_strlen(s->tmp);
		l = (l > s->precision ? s->precision : l);
		if (!(pad = (char *)ft_calloc((s->precision - l + 1), sizeof(char))))
			return ;
		pad = ft_memset(pad, '0', s->precision - l);
		s->tmp = ft_strjoin(pad, s->tmp);
	}
	else if ((s->zero == 1 && s->width > 0) || s->pstar == 1)
	{
		l = ft_strlen(s->tmp) + s->sign;
		l = (l > s->width ? s->width : l);
		if (!(pad = (char *)ft_calloc((s->width - l + 1), sizeof(char))))
			return ;
		pad = ft_memset(pad, '0', s->width - l);
		s->tmp = ft_strjoin(pad, s->tmp);
	}
	return ;
}

void		ft_padding2(t_printf *s)
{
	char	*pad;
	int		l;

	l = ft_strlen(s->tmp) + s->sign;
	if (s->precision > l - s->sign || s->zero == 1)
		ft_padding_precision(s);
	s->tmp_len = (ft_strlen(s->tmp) + s->sign > s->width ?
					s->width : ft_strlen(s->tmp) + s->sign);
	if (!(pad = (char *)ft_calloc((s->width - s->tmp_len + 1), sizeof(char))))
		return ;
	else if (s->width <= s->precision && s->dot == 1 && s->zero)
		pad = ft_memset(pad, '0', ((s->precision - l > 0 ? s->precision - ft_strlen(s->tmp) : 0)));
	if ((s->width > 0 && s->width > s->precision && s->precision >= 0) || s->wstar == 1)
	{
		if (s->sign == 1)
		{
			s->tmp = ft_strjoin("-", s->tmp);
			s->sign = 0;
		}
		pad = ft_memset(pad, ' ', s->width - s->tmp_len - s->sign);
	}
	if ((s->minus == 1 || s->wstar == 1))
		s->tmp = ft_strjoin(s->tmp, pad);
	else
		s->tmp = ft_strjoin(pad, s->tmp);
	if (s->sign == 1)
		s->tmp = ft_strjoin("-", s->tmp);
	s->str = ft_strjoin(s->str, s->tmp);
	return ;
}

void		ft_precision2(t_printf *s)
{
	char *pad;

	ft_get_precision(s);
	if (!(pad = (char *)ft_calloc(1, sizeof(char))))
		return ;
	if (s->precision < 0)
		s->precision = 0;
	if (s->dot == 1)
		s->tmp = ft_strjoin_n(pad, s->tmp, s->precision);
	return ;
}
