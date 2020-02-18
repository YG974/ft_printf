/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:20:09 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/18 09:15:38 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_char_is_flag(t_printf *s)
{
	char	*flags;
	int		i;

	flags = "-+0 #*";
	i = 0;
	while (i < 6)
	{
		if (s->fmt[0] == flags[i])
			return (1);
		i++;
	}
	return (0);
}

void		ft_get_width(t_printf *s)
{
	int width;

	width = 0;
	if (s->width == 0 && s->dot == 0)
	{
		while (s->fmt[0] >= '0' && s->fmt[0] <= '9')
		{
			width = (width * 10) + (s->fmt[0] - '0');
			s->fmt++;
			s->width_on = 1;
		}
		s->width = width;
	}
	return ;
}

void		ft_get_precision(t_printf *s)
{
	int pres;

	pres = 0;
	if (s->fmt[0] == '.')
	{
		s->dot = 1;
		s->fmt += 1;
	}
	if (s->dot == 1)
	{
		while (s->fmt[0] >= '0' && s->fmt[0] <= '9')
		{
			s->precision_on = 1;
			pres = (pres * 10) + (s->fmt[0] - '0');
			s->fmt++;
		}
		s->precision = pres;
	}
	ft_get_precision2(s);
	return ;
}

void		ft_get_precision2(t_printf *s)
{
	int pres;

	pres = 0;
	if (s->fmt[0] == '*' && s->dot == 1)
	{
		s->star = 1;
		s->fmt++;
		pres = (int)va_arg(s->par, int);
		s->precision_on = 1;
		if (pres < 0)
		{
			pres = 1;
			s->neg_precision = 1;
		}
		s->precision = pres;
	}
	return ;
}
