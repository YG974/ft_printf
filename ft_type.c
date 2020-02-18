/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:23:33 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/18 19:05:11 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_get_type(t_printf *s)
{
	if (s->fmt[0] == '.')
		ft_get_precision(s);
	if (s->fmt[0] == 'c')
	{
		ft_c(s);
	}
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
	if (s->fmt[0] == '%')
		ft_pourcent(s);
	return ;
}

void		ft_pourcent(t_printf *s)
{
	char	tmp;

	if (!(s->tmp = (char *)ft_calloc(2, sizeof(char))))
		return ;
	tmp = '%';
	s->tmp[0] = tmp;
	s->str = ft_strjoin(s->str, s->tmp);
	s->fmt += 1;
	return ;
}

void		ft_c(t_printf *s)
{
	char	tmp;

	if (s->width == 0)
		s->width = 1;
	tmp = (char)va_arg(s->par, int);
	write(1, &tmp, 1);
	s->michel++;
	s->fmt += 1;
	return ;
}

void		ft_s(t_printf *s)
{
	s->tmp = ((char*)va_arg(s->par, char *));
	if (s->tmp == NULL)
		s->tmp = ft_strjoin("(nul", "l)");
	s->tmp_len = (s->precision > s->tmp_len ? s->precision : s->tmp_len);
	if (s->precision_on == 0 && s->width_on == 0)
		ft_write_arg(s);
	else if (s->width_on == 1 && s->precision == 0)
	{
		if (s->zero == 1 || s->minus == 1)
		{
			ft_write_arg(s);
			ft_write_width_str(s);
		}
		else
		{
			ft_write_width_str(s);
			ft_write_arg(s);
		}
	}
	s->fmt += 1;
	return ;
}
