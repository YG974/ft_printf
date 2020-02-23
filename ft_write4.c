/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:28:20 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/23 15:35:02 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void		ft_pad_11(t_printf *s)
{
	ft_write_width(s);
	ft_write_sign(s);
	ft_write_preci(s);
	ft_write_arg(s);
	return ;
}

void		ft_pad_12(t_printf *s)
{
	ft_write_sign(s);
	ft_write_width_zero(s);
	ft_write_arg(s);
	return ;
}

void		ft_pad_13(t_printf *s)
{
	ft_write_sign(s);
	if (s->tmp_len == 1 && s->tmp[0] == '0')
		ft_pad_10(s);
	else
		ft_write_arg(s);
	ft_write_width(s);
	return ;
}

void		ft_order(t_printf *s)
{
	s->tmp_len = ft_strlen(s->tmp);
	if (s->precision_on == 0 && s->width_on == 0 && s->dot == 0)
		ft_pad_1(s);
	else if (s->dot == 1 && s->precision_on == 0 && s->width_on == 0)
		ft_pad_8(s);
	else if (s->dot == 1 && s->precision == 0 && s->width_on == 0)
		ft_pad_8(s);
	else if (s->dot == 1 && s->precision_on == 0 && s->width_on == 1)
		ft_pad_1(s);
	else if (s->width_on == 1 && s->precision_on == 0
		&& s->minus == 0 && s->zero == 0)
	{
		if (s->neg_width == 1)
			ft_pad_2(s);
		else
			ft_pad_1(s);
	}
	else if (s->minus == 0 && s->zero == 0)
		ft_order2(s);
	else
		ft_order3(s);
	return ;
}

void		ft_order2(t_printf *s)
{
	if (s->precision_on == 1 && s->width_on == 0 && s->neg_precision == 1)
		ft_pad_8(s);
	else if (s->precision_on == 1 && s->width_on == 1)
	{
		if (s->precision == 0 && s->tmp[0] != '0' && s->neg_width == 0)
			ft_pad_11(s);
		else if (s->neg_precision == 1 && s->neg_width == 1)
			ft_pad_2(s);
		else if (s->precision == 0 != s->neg_width && s->tmp[0] != '0')
			ft_pad_6(s);
		else if (s->precision == 0 && s->tmp[0] == '0')
			ft_pad_1(s);
		else if (s->neg_precision == 1 && s->neg_width == 0)
			ft_pad_11(s);
		else if (s->neg_precision == 0 && s->neg_width == 0)
			ft_pad_11(s);
		else
			ft_pad_5(s);
	}
	else
		ft_order3(s);
	return ;
}
