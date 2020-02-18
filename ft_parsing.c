/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:17:07 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/18 09:47:55 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_parsing(t_printf *s)
{
	ft_putstr_fd(s->str, 1);
	s->michel += ft_strlen(s->str);
	s->str[0] = '\0';
	ft_get_flags(s);
	ft_get_precision(s);
	ft_get_width(s);
	ft_get_type(s);
	return ;
}

void		ft_get_flags(t_printf *s)
{
	ft_init_flags(s);
	while (ft_char_is_flag(s) > 0)
	{
		if (s->fmt[0] == '-')
			s->minus = 1;
		if (s->fmt[0] == '+')
			s->positive = 1;
		if (s->fmt[0] == '0')
			s->zero = 1;
		if (s->fmt[0] == ' ')
			s->space = 1;
		if (s->fmt[0] == '#')
			s->sharp = 1;
		if (s->fmt[0] == '*')
			ft_star(s);
		s->fmt += 1;
	}
	if (s->fmt[0] == '.' && s->star > 0)
		ft_preci_star(s);
	return ;
}

void		ft_star(t_printf *s)
{
	s->width = (int)va_arg(s->par, int);
	s->width_on = 1;
	if (s->width < 0)
	{
		s->width = -s->width;
		s->neg_width = 1;
	}
	return ;
}

void		ft_preci_star(t_printf *s)
{
	if (s->fmt[0] == '*')
	{
		s->precision = (int)va_arg(s->par, int);
		s->precision_on = 1;
		s->fmt++;
	}
	return ;
}

void		ft_init_flags(t_printf *s)
{
	s->minus = 0;
	s->positive = 0;
	s->zero = 0;
	s->null = 0;
	s->space = 0;
	s->sharp = 0;
	s->star = 0;
	s->width = 0;
	s->precision = 0;
	s->dot = 0;
	s->sign = 0;
	s->width_on = 0;
	s->precision_on = 0;
	s->neg_width = 0;
	s->neg_precision = 0;
	return ;
}
