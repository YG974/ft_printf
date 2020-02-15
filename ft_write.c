#include <stdio.h>
#include "ft_printf.h"

void		ft_order(t_printf *s)
{
	s->tmp_len = (s->precision > ft_strlen(s->tmp) ? 
								s->precision : ft_strlen(s->tmp));
//	if()
	//{
		ft_write_width(s);
//		ft_write_sign(s);
		ft_write_preci(s);
		ft_write_arg(s);
/*	}
	else
	{
		ft_write_preci(s);
		ft_write_sign(s);
		ft_write_arg(s);
		ft_write_width(s);
	}*/
	free(s->tmp);
	return ;
}
void		ft_wirte_sign(t_printf *s)
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

	c = ' ';
	if (s->width > s->tmp_len)
	{
		write(1, &c, s->width - s->tmp_len);
		s->michel += s->width - s->tmp_len;
	}
	return ;
}

void		ft_write_preci(t_printf *s)
{
	char	c;

	if ((s->zero == 1 || s->neg_width == 1))
		c = '0';
	else
		c = ' ';
	if (s->precision > s->tmp_len)
	{
		write(1, &c, s->precision - s->tmp_len);
		s->michel += s->precision - s->tmp_len;
	}
	return ;
}
