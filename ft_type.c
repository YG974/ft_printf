/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:23:33 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/18 22:41:28 by ygeslin          ###   ########.fr       */
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
	s->tmp_len = ft_strlen(s->tmp);
	if (s->precision_on == 0 && s->width_on == 0 && s->dot == 0)
		ft_write_arg(s);
	else if (s->width_on == 1 && s->precision_on == 0)
	{
		if (s->dot == 1 && s->precision_on == 0)
		{
			write(1, " ", 1);
			s->michel ++;
		}
		else if (s->zero == 1 || s->minus == 1 || s->neg_width == 1)
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
	else
		ft_s2(s);
	s->fmt += 1;
	return ;
}

void		ft_s2(t_printf *s)
{
	if (s->precision_on == 1 && s->width_on == 0 && s->neg_precision == 0)
		ft_write_preci_str(s);
	else if (s->precision_on == 1 && s->width_on == 0 && s->neg_precision == 1)
		ft_write_arg(s);
	else if (s->precision_on == 1 && s->width_on == 1)
	{
		if (s->neg_precision == 1)
		{
			ft_write_arg(s);
			ft_write_width_str(s);
		}
		else if (s->minus == 1 && s->neg_width == 0)
		{
			ft_write_preci_str(s);
			ft_write_width_str(s);
		}
		else if (s->minus == 1 && s->neg_width == 1)
		{
			ft_write_preci_str(s);
			ft_write_width_str(s);
		}
		else
			ft_s3(s);
	}
	return ;
}

void		ft_s3(t_printf *s)
{
	if (s->dot == 1 && s->precision_on == 0)
	{
		write(1, " ", 1);
		s->michel ++;
	}
	else if (s->neg_width == 1)
	{
		ft_write_width_str(s);
		ft_write_preci_str(s);
	}
	else
	{
		ft_write_width_str(s);
		ft_write_preci_str(s);
	}
	return ;
}
