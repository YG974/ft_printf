#include <stdio.h>
#include "ft_printf.h"

void		ft_order(t_printf *s)
{
	if(s->minus == 1 || s->neg_width == 1)
	{
		//ft_putstr_fd(s->str, 1);
	//	s->michel += ft_strlen(s->str);
		s->tmp_len = ft_strlen(s->tmp);
		ft_write_preci(s);
		ft_write_sign(s);
		ft_write_arg(s);
		ft_write_width(s);
	}
	else
	{
		ft_write_width(s);
		ft_write_sign(s);
		ft_write_arg(s);
		ft_write_preci(s);
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
	if ((s->minus == 1 || s->neg_width == 1))
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
