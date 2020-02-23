/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write8.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:31:58 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/23 17:40:12 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void		ft_write_preci_str(t_printf *s)
{
	int		i;

	i = 0;
	if (s->precision < s->tmp_len)
	{
		while (i < s->precision)
		{
			write(1, &s->tmp[i], 1);
			s->michel++;
			i++;
		}
	}
	else if (s->precision >= s->tmp_len)
		ft_write_arg(s);
	return ;
}

void		ft_print_s(t_printf *s)
{
	ft_write_width_str(s);
	ft_write_arg(s);
	return ;
}

void		ft_print_s2(t_printf *s)
{
	ft_write_width_str2(s);
	ft_write_preci_str(s);
	return ;
}

void		ft_print_s3(t_printf *s)
{
	ft_write_preci_str(s);
	ft_write_width_str2(s);
	return ;
}

void		ft_print_s4(t_printf *s)
{
	ft_write_arg(s);
	ft_write_width_str(s);
	return ;
}
