/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:27:45 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/12 19:49:41 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_p(t_printf *s)
{
	long	ptr;
	char	*tmp;
	char	*pad;
	int		len;

	ptr = (long)va_arg(s->par, long);
	tmp = ft_itoa_base(ptr, "0123456789abcdef");
	len = ft_strlen(tmp) + 2;
	len = (len > s->width ? 0 : s->width - len);
	if (!(pad = (char *)malloc(len * sizeof(char))))
		return ;
	if (s->width > 0)
		pad = ft_memset(pad, ' ', s->width - len);
	tmp = ft_strjoin("0x", tmp);
	if (s->minus == 1)
		tmp = ft_strjoin(tmp, pad);
	else
		tmp = ft_strjoin(pad, tmp);
	s->str = ft_strjoin(s->str, tmp);
	s->fmt += 1;
	return ;
}

void		ft_d(t_printf *s)
{
	int		d;

	d = (int)va_arg(s->par, int);
	if (d < 0)
	{
		s->sign = 1;
		d = -d;
	}
	if (d == 0)
	{
		if (!(s->tmp = (char *)malloc(2 * sizeof(char))))
			return ;
		s->tmp[0] = '0';
		s->tmp[1] = '\0';
		if (s->dot == 1 && s->precision == 0)
			s->tmp[0] = '\0';
	}
	else
		s->tmp = ft_itoa_base(d, "0123456789");
	ft_padding2(s);
	ft_precision2(s);
	s->fmt += 1;
	return ;
}

void		ft_u(t_printf *s)
{
	unsigned int	u;

	u = (unsigned int)va_arg(s->par, unsigned int);
	if (u == 0)
	{
		if (!(s->tmp = (char *)malloc(2 * sizeof(char))))
			return ;
		s->tmp[0] = '0';
		s->tmp[1] = '\0';
	}
	else 
		s->tmp = ft_itoa_base(u, "0123456789");
	ft_padding2(s);
	ft_precision2(s);
	s->fmt += 1;
	return ;
}

void		ft_x(t_printf *s)
{
	unsigned int	l;

	l = (unsigned )va_arg(s->par, unsigned int);
	if (l == 0)
	{
		if (!(s->tmp = (char *)malloc(2 * sizeof(char))))
			return ;
		s->tmp[0] = '0';
		s->tmp[1] = '\0';
	}
	else
		s->tmp = ft_itoa_base(l, "0123456789abcdef");
	ft_padding2(s);
	ft_precision2(s);
	s->fmt += 1;
	return ;
}

void		ft_x_up(t_printf *s)
{
	unsigned int	l;

	l = (unsigned int)va_arg(s->par, unsigned int);
	if (l == 0)
	{
		if (!(s->tmp = (char *)malloc(2 * sizeof(char))))
			return ;
		s->tmp[0] = '0';
		s->tmp[1] = '\0';
	}
	else
		s->tmp = ft_itoa_base(l, "0123456789ABCDEF");
	ft_padding2(s);
	ft_precision2(s);
	s->fmt += 1;
	return ;
}
