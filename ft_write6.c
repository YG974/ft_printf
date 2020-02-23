/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:30:07 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/23 15:31:06 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void		ft_write_arg(t_printf *s)
{
	char c;

	c = 0;
	if (s->null == 1)
	{
		write(1, &c, 1);
		s->michel++;
	}
	else
	{
		ft_putstr_fd(s->tmp, 1);
		s->michel += ft_strlen(s->tmp);
	}
	return ;
}

void		ft_write_width(t_printf *s)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	s->tmp_len = ft_strlen(s->tmp) + s->p * 2;
	if (s->precision > s->tmp_len && s->neg_precision == 0)
		s->tmp_len = s->precision + s->sign;
	else
		s->tmp_len = s->tmp_len + s->sign;
	if (s->tmp_len == 1 && s->precision == 0 && s->precision_on == 1)
		s->tmp_len = s->tmp_len;
	while (i < s->width - s->tmp_len)
	{
		write(1, &c, 1);
		i++;
		s->michel++;
	}
	return ;
}

void		ft_write_width2(t_printf *s)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	s->tmp_len = ft_strlen(s->tmp) + s->p * 2;
	while (i < s->width - s->tmp_len)
	{
		write(1, &c, 1);
		i++;
		s->michel++;
	}
	return ;
}

void		ft_write_width3(t_printf *s)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	while (i < s->width - 1 - s->p * 2 && s->width_on == 1)
	{
		write(1, &c, 1);
		i++;
		s->michel++;
	}
	return ;
}

void		ft_write_width_zero(t_printf *s)
{
	int		i;
	char	c;

	i = 0;
	c = '0';
	s->tmp_len = s->tmp_len + s->sign + s->p * 2;
	while (i < s->width - s->tmp_len)
	{
		write(1, &c, 1);
		i++;
		s->michel++;
	}
	return ;
}
