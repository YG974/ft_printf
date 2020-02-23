/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:29:23 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/23 15:36:50 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void		ft_order3(t_printf *s)
{
	if (s->minus == 0 && s->zero == 0)
	{
		if (s->precision_on == 1 && s->width_on == 0)
		{
			if (s->precision == 0)
				ft_pad_1(s);
			else
				ft_pad_7(s);
		}
		else if (s->neg_precision == 1)
		{
			if (s->neg_width == 1)
				ft_pad_7(s);
			else
				ft_pad_12(s);
		}
	}
	else
		ft_order4(s);
}

void		ft_order4(t_printf *s)
{
	if (s->zero == 1 && s->minus == 0)
	{
		if (s->precision_on == 1 && s->width_on == 0)
			ft_pad_7(s);
		else if (s->precision_on == 0 && s->width_on == 1)
		{
			if (s->neg_width == 0)
				ft_pad_12(s);
			else
				ft_pad_2(s);
		}
		else if (s->neg_precision == 0)
		{
			if (s->neg_width == 0 && s->width > s->precision)
				ft_pad_11(s);
			else
				ft_pad_6(s);
		}
		else
			ft_order6(s);
	}
	else
		ft_order5(s);
	return ;
}

void		ft_order5(t_printf *s)
{
	if (s->minus == 1)
	{
		if (s->precision_on == 1 && s->width_on == 0)
			ft_pad_7(s);
		else if (s->precision_on == 0 && s->width_on == 1)
			ft_pad_2(s);
		else if (s->neg_precision == 0)
		{
			if (s->precision == 0 && s->neg_width == 0)
				ft_pad_13(s);
			else
				ft_pad_6(s);
		}
		else if (s->neg_precision == 1)
		{
			if (s->neg_width == 1)
				ft_pad_2(s);
			else
				ft_pad_5(s);
		}
	}
	return ;
}

void		ft_order6(t_printf *s)
{
	if (s->zero == 1 && s->minus == 0)
	{
		if (s->neg_precision == 1)
		{
			if (s->neg_width == 1)
				ft_pad_2(s);
			else
				ft_pad_12(s);
		}
	}
	else
		ft_order5(s);
	return ;
}

void		ft_write_sign(t_printf *s)
{
	if (s->sign == 1)
	{
		write(1, "-", 1);
		s->michel++;
	}
	else if (s->space == 1 && s->positive == 0 && s->sign == 0)
	{
		write(1, " ", 1);
		s->michel++;
	}
	else if (s->positive == 1 && s->sign == 0)
	{
		write(1, "+", 1);
		s->michel++;
	}
	else if (s->p == 1)
	{
		write(1, "0x", 2);
		s->michel += 2;
	}
	return ;
}
