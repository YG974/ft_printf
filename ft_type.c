/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:23:33 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/13 16:13:10 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_get_type(t_printf *s)
{
	if (s->fmt[0] == '%')
		ft_pourcent(s);
	if (s->fmt[0] == '.')
		ft_get_precision(s);
	if (s->fmt[0] == 'c')
		ft_c(s);
	if (s->fmt[0] == 's')
		ft_s(s);
	if (s->fmt[0] == 'p')
		ft_p(s);
	if (s->fmt[0] == 'd' || s->fmt[0] == 'i')
		ft_d(s);
	if (s->fmt[0] == 'u')
		ft_u(s);
	if (s->fmt[0] == 'x')
		ft_x(s);
	if (s->fmt[0] == 'X')
		ft_x_up(s);
	return ;
}

void		ft_pourcent(t_printf *s)
{
	char tmp[2];
	char *pad;

	tmp[0] = '%';
	tmp[1] = '\0';
	if (!(pad = (char *)ft_calloc((s->width - s->tmp_len), sizeof(char))))
		return ;
	else if (s->width > 0)
		pad = ft_memset(pad, ' ', s->width - s->tmp_len - 1);
	if (s->minus == 1)
		s->str = ft_strjoin(tmp, pad);
	else
		s->str = ft_strjoin(pad, tmp);
	s->fmt += 1;
	return ;
}

void		ft_c(t_printf *s)
{
	char *pad;
	char tmp;

	if (!(s->tmp = (char *)ft_calloc(2, sizeof(char))))
		return ;
	tmp = (char)va_arg(s->par, int);
	s->tmp[0] = tmp;
	if (!(pad = (char *)ft_calloc((s->width - s->tmp_len), sizeof(char))))
		return ;
	if (s->zero == 1)
		pad = ft_memset(pad, '0', s->width - s->tmp_len - 1);
	else if (s->width > 0)
		pad = ft_memset(pad, ' ', s->width - s->tmp_len - 1);
	if (s->minus == 1 || s->star == 2)
		s->tmp = ft_strjoin(s->tmp, pad);
	else
		s->tmp = ft_strjoin(pad, s->tmp);
	s->str = ft_strjoin(s->str, s->tmp);
	s->fmt += 1;
	return ;
}

void		ft_s(t_printf *s)
{
	s->tmp = ((char*)va_arg(s->par, char *));
	if (s->tmp == NULL)
		s->tmp = ft_strjoin("(nul", "l)");
	ft_sprecision(s);
	ft_spadding(s);
	s->fmt += 1;
	return ;
}
