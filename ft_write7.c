/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write7.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:31:14 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/23 17:41:11 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void		ft_write_preci(t_printf *s)
{
	char	c;
	int		i;

	s->tmp_len = ft_strlen(s->tmp) + s->p * 2;
	i = (s->precision > s->tmp_len ? s->precision : s->tmp_len);
	c = '0';
	while (i > s->tmp_len)
	{
		write(1, &c, 1);
		s->michel++;
		i--;
	}
	return ;
}

void		ft_write_str(t_printf *s)
{
	int		i;

	i = 0;
	if (s->null == 1)
	{
		write(1, "\0", 1);
		s->michel++;
	}
	else
	{
		while (i < s->tmp_len - 1)
		{
			write(1, &s->tmp[i], 1);
			s->michel++;
			i++;
		}
	}
	return ;
}

void		ft_write_width_str(t_printf *s)
{
	int i;

	i = 0;
	if (s->width > s->tmp_len)
	{
		while (i < s->width - s->tmp_len)
		{
			write(1, " ", 1);
			s->michel++;
			i++;
		}
	}
	else if (s->width > s->precision && s->precision_on == 1
		&& s->neg_precision == 0)
	{
		while (i < s->width - s->precision)
		{
			write(1, " ", 1);
			s->michel++;
			i++;
		}
	}
	return ;
}

void		ft_write_width_str2(t_printf *s)
{
	int i;

	i = 0;
	if (s->tmp_len < s->precision)
		s->precision = s->tmp_len;
	if (s->width > s->precision)
	{
		while (i < s->width - s->precision)
		{
			write(1, " ", 1);
			s->michel++;
			i++;
		}
	}
	return ;
}

void		ft_write_width_str3(t_printf *s)
{
	int i;

	i = 0;
	while (i < s->width)
	{
		write(1, " ", 1);
		s->michel++;
		i++;
	}
	return ;
}
