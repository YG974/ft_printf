/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:06:11 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/23 17:40:09 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void		ft_print_s5(t_printf *s)
{
	ft_write_width_str(s);
	ft_write_arg(s);
	return ;
}

void		ft_print_s6(t_printf *s)
{
	write(1, " ", 1);
	s->michel++;
	return ;
}

void		ft_print_s7(t_printf *s)
{
	ft_write_preci_str(s);
	ft_write_width_str2(s);
	return ;
}

void		ft_s3(t_printf *s)
{
	if (s->dot == 1 && s->precision_on == 0)
		ft_write_width_str3(s);
	if (s->minus == 1)
	{
		if (s->precision == 0)
			ft_write_width_str3(s);
		else if (s->neg_width == 1 && s->neg_precision == 0)
			ft_print_s3(s);
		else if (s->neg_width == 0 && s->neg_precision == 0
				&& s->width <= s->precision)
			ft_print_s3(s);
		else if (s->neg_precision == 1)
			ft_print_s4(s);
		else if (s->neg_width == 0 && s->neg_precision == 0 &&
				s->width > s->precision)
			ft_print_s7(s);
		else
		{
			ft_write_width_str(s);
			ft_write_preci_str(s);
		}
	}
	return ;
}
