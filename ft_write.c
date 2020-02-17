#include <stdio.h>
#include "ft_printf.h"


void		ft_pad_1(t_printf *s)
{
		ft_write_sign(s);
		ft_write_arg(s);
	return ;
}

void		ft_pad_2(t_printf *s)
{
		ft_write_width(s);
		ft_write_sign(s);
		ft_write_arg(s);
	return ;
}

void		ft_pad_3(t_printf *s)
{
		ft_write_sign(s);
		ft_write_arg(s);
		ft_write_width(s);
	return ;
}

void		ft_pad_4(t_printf *s)
{
		ft_write_sign(s);
		ft_write_arg(s);
		ft_write_width(s);
	return ;
}

void		ft_pad_5(t_printf *s)
{
		ft_write_sign(s);
		ft_write_arg(s);
		ft_write_width(s);
	return ;
}

void		ft_pad_6(t_printf *s)
{
		ft_write_width(s);
		ft_write_sign(s);
		ft_write_arg(s);
	return ;
}

void		ft_order(t_printf *s)
{
	s->tmp_len = ft_strlen(s->tmp);
	if ((s->minus == 1) && s->zero == 1)
		s->zero = 0;
	if (s->precision_on == 0 && s->width_on == 0 && s->zero == 0)	
		ft_pad_1(s);
	else if (s->precision_on == 0 && s->width_on == 1 && s->zero == 1 &&
			s->neg_width == 0)	
		ft_pad_6(s);
	else if (s->precision_on == 0 && s->neg_width == 1 && s->zero == 1)	
		ft_pad_5(s);
	else if (s->neg_width == 0 && s->minus == 1)
		ft_pad_5(s);
	else if (s->precision_on == 0 && s->width_on == 1 && s->neg_width == 0
		&& s->zero == 0)
		ft_pad_2(s);
	else if (s->neg_width == 1 && s->zero == 0)
		ft_pad_3(s);
	else if (s->neg_width == 1 && s->zero == 1)
		ft_pad_4(s);
	else
		//((s->neg_width == 1) || (s->zero == 1 && s->tmp_len < s->precision))
	{
		ft_write_sign(s);
		ft_write_preci(s);
		ft_write_arg(s);
		ft_write_width(s);
	}
	free(s->tmp);
	return ;
}
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
		return;
}

void		ft_write_width(t_printf *s)
{
	char	c;
	int		i;
	int		j;

	if (s->zero == 1 && s->neg_width == 0)
		c = '0';
	else
		c = ' ';
	j = (s->precision > s->tmp_len + s->sign ? 
			s->precision : s->tmp_len + s->sign);
	i = s->width;		
	while (i > j)
	{
		write(1, &c, 1);
		s->michel ++;
		i--;
	}
	return ;
}

void		ft_write_preci(t_printf *s)
{
	char	c;
	int		i;

	i = (s->precision > s->tmp_len ? 
			s->precision : s->tmp_len);
	if ((s->minus == 1 || s->neg_width == 1 || s->zero == 1))
		c = '0';
	else
		c = ' ';
	while (i > s->tmp_len)
	{
		write(1, &c, 1);
		s->michel++;
		i--;
	}
	return ;
}
