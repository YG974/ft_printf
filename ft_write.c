/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:06:11 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/19 19:00:43 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void		ft_pad_0(t_printf *s)
{
	ft_write_width(s);
	return ;
}

void		ft_pad_1(t_printf *s)
{
	ft_write_width(s);
	ft_write_sign(s);
	ft_write_arg(s);
	return ;
}

void		ft_pad_2(t_printf *s)
{
	ft_write_sign(s);
	ft_write_arg(s);
	ft_write_width(s);
	return ;
}

void		ft_pad_3(t_printf *s)
{
	ft_write_sign(s);
	ft_write_width(s);
	ft_write_arg(s);
	return ;
}

void		ft_pad_4(t_printf *s)
{
	ft_write_sign(s);
	ft_write_preci(s);
	ft_write_width(s);
	ft_write_arg(s);
	return ;
}

void		ft_pad_5(t_printf *s)
{
	ft_write_sign(s);
	ft_write_preci(s);
	ft_write_arg(s);
	ft_write_width(s);
	return ;
}

void		ft_pad_6(t_printf *s)
{
	ft_write_sign(s);
	ft_write_preci(s);
	ft_write_arg(s);
	ft_write_width(s);
	return ;
}

void		ft_pad_7(t_printf *s)
{
	ft_write_sign(s);
	ft_write_preci(s);
	ft_write_arg(s);
	return ;
}

void		ft_pad_8(t_printf *s)
{
	ft_write_sign(s);
	ft_write_arg(s);
	return ;
}

void		ft_pad_9(t_printf *s)
{
	/*
	ft_write_width(s);
	ft_write_sign(s);
	ft_write_preci(s);
	ft_write_arg(s);
	*/
	if(s->tmp)
		write(1, "A", 1);
	return ;
}

void		ft_pad_10(t_printf *s)
{
	write(1, " ", 1);
	s->michel++;
	return ;
}

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
	else
		ft_order2(s);
	return ;
}

void		ft_order2(t_printf *s)
{
	if(s->minus == 0 && s->zero == 0)
	{
		if (s->precision_on == 1 && s->width_on == 0 && s->neg_precision == 1)
			ft_pad_8(s);
		else if (s->precision_on == 1 && s->width_on == 1)
		{
			if (s->precision == 0 && s->tmp[0] != '0' && s->neg_width == 0)
				ft_pad_11(s);
			else if (s->precision == 0 != s->neg_width && s->tmp[0] != '0')
				ft_pad_2(s);
			else if (s->precision == 0 && s->tmp[0] == '0')
				ft_pad_9(s);
			else if (s->neg_precision == 1 && s->neg_width == 0)
				ft_pad_11(s);
			else if (s->neg_precision == 1 && s->neg_width == 1)
				ft_pad_2(s);
			else if (s->neg_precision == 0 && s->neg_width == 0)
				ft_pad_11(s);
			else
				ft_pad_5(s);
		}
		else
			ft_order3(s);
	}
	else
		ft_order3(s);
	return ;
}

void		ft_order3(t_printf *s)
{
	if (s->minus == 0 && s->zero == 0)
	{
		if (s->precision_on == 1 && s->width_on == 0)
		{
			if (s->precision == 0)
				ft_pad_8(s);
			else
				ft_pad_7(s);
		}
	}
	else if (s->zero == 1 && s->minus == 0)
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
	}
	else if (s->minus == 1)
	{
		if (s->precision_on == 1 && s->width_on == 0)
			ft_pad_7(s);
		else if (s->precision_on == 0 && s->width_on == 1)
		{
			if (s->neg_width == 0)
				ft_pad_2(s);
			else
				ft_pad_2(s);
		}
	}
//	else
//	else
//		ft_order4(s);
	return ;
}

/*
void		ft_order4(t_printf *s)
{
}
*/

void		ft_write_sign(t_printf *s)
{
	if (s->sign == 1)
	{
		write(1, "-", 1);
		s->michel++;
	}
	else if (s->positive == 1 && s->sign == 0)
	{
		write(1, "+", 1);
		s->michel++;
	}
	return ;
}

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
	int	i;
	char c;

	i = 0;
	c = ' ';
	s->tmp_len = s->tmp_len + s->sign;
	if (s->precision > s->tmp_len)
		s->tmp_len = s->precision;
	if (s->tmp_len == 1 && s->precision == 0 && s->precision_on == 1)
			s->tmp_len = s->tmp_len - s->sign;
	while (i < s->width - s->tmp_len)
	{
		write(1, &c, 1);
		i++;
		s->michel++;
	}
	return ;
}

void		ft_write_width_zero(t_printf *s)
{
	int	i;
	char c;

	i = 0;
	c = '0';
	s->tmp_len = s->tmp_len + s->sign;
	while (i < s->width - s->tmp_len)
	{
		write(1, &c, 1);
		i++;
		s->michel++;
	}
	return ;
}

void		ft_write_preci(t_printf *s)
{
	char	c;
	int		i;

	s->tmp_len = ft_strlen(s->tmp);
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
	ft_write_width_str(s);
	return ;
}

void		ft_print_s4(t_printf *s)
{
	ft_write_arg(s);
	ft_write_width_str(s);
	return ;
}

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
		ft_print_s6(s);
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
