/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:27:45 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/21 17:23:43 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_p(t_printf *s)
{
	long	ptr;

	ptr = (long)va_arg(s->par, long);
	if (ptr == 0)
	{
		if (!(s->tmp = (char *)malloc(2 * sizeof(char))))
			return ;
		s->tmp[0] = '0';
		s->tmp[1] = '\0';
		if (s->dot == 1 && s->precision == 0)
			s->tmp[0] = '\0';
	}
	else
		s->tmp = ft_itoa_base(ptr, "0123456789abcdef");
	s->tmp = ft_strjoin("0x", s->tmp);
	ft_order(s);
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
	ft_order(s);
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
		if (s->dot == 1 && s->precision == 0)
			s->tmp[0] = '\0';
	}
	else
		s->tmp = ft_itoa_base(u, "0123456789");
	ft_order(s);
	s->fmt += 1;
	return ;
}

void		ft_x(t_printf *s)
{
	unsigned int	l;

	l = (unsigned)va_arg(s->par, unsigned int);
	if (l == 0)
	{
		if (!(s->tmp = (char *)malloc(2 * sizeof(char))))
			return ;
		s->tmp[0] = '0';
		s->tmp[1] = '\0';
		if (s->dot == 1 && s->precision == 0)
			s->tmp[0] = '\0';
	}
	else
		s->tmp = ft_itoa_base(l, "0123456789abcdef");
	ft_order(s);
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
		if (s->dot == 1 && s->precision == 0)
			s->tmp[0] = '\0';
	}
	else
		s->tmp = ft_itoa_base(l, "0123456789ABCDEF");
	ft_order(s);
	s->fmt += 1;
	return ;
}
