/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:21:58 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/04 23:15:30 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_int_strchr(const char *s, int c)
{
	int i;

	i = 0;
	c = (char)c;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

char		*ft_strjoin_n(char *s1, char *s2, int n)
{
	int		len1;
	int		len2;
	int		i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len1 = 0;
	len2 = (n > ft_strlen(s2) ? ft_strlen(s2) : n);
	i = 0;
	if (!(str = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (i < len1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len1 + len2 && s2[i] != '\0')
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char		*ft_strjoin_endl(char *s1, const char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*str;
	len1 = (s1 == NULL ? 0 : ft_strlen(s1));
	len2 = (ft_int_strchr(s2, '%') == -1 ?
	ft_strlen(s2) : ft_int_strchr(s2, '%'));
	i = 0;
	if (!(str = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*print_nbr_base(long nb, char *base, int len_base, int len_res)
{
	char	*res;
	int		sign;

	sign = 0;
	if (nb < 0)
	{
		nb = -nb;
		sign = 1;
	}
	if (!(res = (char *)malloc(sizeof(char) * (len_res + sign))))
		return (NULL);
	res[len_res + sign - 1] = '\0';
	while (len_res > sign)
	{
		res[len_res - 2 + sign] = base[nb % len_base];
		nb = nb / len_base;
		len_res--;
	}
	if (sign == 1)
		res[0] = '-';
	return (res);
}

char		*ft_itoa_base(long nbr, char *base)
{
	char	*res;
	long	nb;
	int		len_base;
	int		len_res;

	if (!nbr || !base)
		return (NULL);
	nb = nbr;
	len_base = ft_strlen(base);
	len_res = 2;
	if (nb < 0)
		nb = -nb;
	while (nb / len_base > 0)
	{
		len_res++;
		nb = nb / len_base;
	}
	nb = nbr;
	res = print_nbr_base(nb, base, len_base, len_res);
	return (res);
}

void		ft_get_type(t_printf *s)
{
	if (s->fmt[0] == '.')
		ft_get_precision(s);
	if (s->fmt[0] == 'c')
		ft_c(s);
	if (s->fmt[0] == 's')
		ft_s(s);
	if (s->fmt[0] == 'p')
		ft_p(s);
	if (s->fmt[0] == 'd' || s->fmt[0] == 'i')
		ft_d(s);
	if (s->fmt[0] == 'u')
		ft_u(s);
	if (s->fmt[0] == 'x')
		ft_x(s);
	if (s->fmt[0] == 'X')
		ft_x_up(s);
	if (s->fmt[0] == '%')
		ft_pourcent(s);
	return ;
}

/*
*******************************************************************************
**									DISPLAY
*******************************************************************************
*/

void		ft_padding(t_printf *s)
{
	char *pad;
	
	s->tmp_len = ft_strlen(s->tmp);
	s->tmp_len = (s->tmp_len > s->width ? s->width : s->tmp_len);
	if (!(pad = (char *)ft_calloc((s->width - s->tmp_len + 1), sizeof(char))))
		return ;
	if (s->zero == 1 && s->star != 2)
		pad = ft_memset(pad, '0', s->width - s->tmp_len);
	else if (s->width > 0 )
		pad = ft_memset(pad, ' ', s->width - s->tmp_len);
	if (s->minus == 1 || s->star == 2)
		s->tmp = ft_strjoin(s->tmp, pad);
	else 
		s->tmp = ft_strjoin(pad, s->tmp);
	s->str = ft_strjoin(s->str, s->tmp);
	return ;
}

void		ft_precision(t_printf *s)
{
	char *pad;

	ft_get_precision(s);
	if (!(pad = (char *)ft_calloc(1 , sizeof(char))))
		return ;
	if (s->precision < 0)
		s->precision = 0;
	s->tmp = ft_strjoin_n(pad, s->tmp, s->precision);
	return ;
}
		
void		ft_pourcent(t_printf *s)
{
	char tmp[2];
	char *pad;

	tmp[0] = '%';
	tmp[1] = '\0';
	if (!(pad = (char *)ft_calloc((s->width - s->tmp_len), sizeof(char))))
		return ;
	else if (s->width > 0)
		pad = ft_memset(pad, ' ', s->width - s->tmp_len - 1);
	if (s->minus == 1)
		s->str = ft_strjoin(tmp, pad);
	else
		s->str = ft_strjoin(pad, tmp);
	s->fmt += 1;
	return ;

}

void		ft_c(t_printf *s)
{
	char *pad;

	if (!(s->tmp = (char *)malloc(2 * sizeof(char))))
		return ;
	s->tmp[0] = (char)va_arg(s->par, int);
	s->tmp[1] = '\0';	
	if (!(pad = (char *)ft_calloc((s->width - s->tmp_len), sizeof(char))))
		return ;
	if (s->zero == 1)
		pad = ft_memset(pad, '0', s->width - s->tmp_len - 1);
	else if(s->width > 0)
		pad = ft_memset(pad, ' ', s->width - s->tmp_len - 1);
	if (s->minus == 1 || s->star == 2)
		s->tmp = ft_strjoin(s->tmp, pad);
	else
		s->tmp = ft_strjoin(pad, s->tmp);
	s->str = ft_strjoin(s->str, s->tmp);
	s->fmt += 1;
	return ;
}

void		ft_s(t_printf *s)
{
	s->tmp = ((char*)va_arg(s->par, char *));
	ft_padding(s);
	ft_precision(s);
	s->fmt += 1;
	return ;
}

void		ft_p(t_printf *s)
{
	long	ptr;
	char	*tmp;
	char	*pad;
	int		len;

	ptr = (long)va_arg(s->par, long);
	tmp = ft_itoa_base(ptr, "0123456789abcdef");
	len = ft_strlen(tmp) + 2;
	len = (len > s->width ? 0 : s->width - len);
	if (!(pad = (char *)malloc(len * sizeof(char))))
		return ;
	if(s->width > 0)
		pad = ft_memset(pad, ' ', s->width - len);
	tmp = ft_strjoin("0x", tmp);
	if (s->minus == 1)
		tmp = ft_strjoin(tmp, pad);
	else 
		tmp = ft_strjoin(pad, tmp);
	s->str = ft_strjoin(s->str, tmp);
	s->fmt += 1;
	return ;
}

void		ft_d(t_printf *s)
{
	int		d;

	d = (int)va_arg(s->par, int);
	if (d == 0)
	{
		if (!(s->tmp = (char *)malloc(2 * sizeof(char))))
			return ;
		s->tmp[0] = '0';	
		s->tmp[1] = '\0';	
		if(s->dot == 1 && s->precision == 0)
			s->tmp[0] = '\0';	
	}
	else 
		s->tmp = ft_itoa_base(d, "0123456789");
	ft_padding(s);
	ft_precision(s);
	s->fmt += 1;
	return ;
}

void		ft_u(t_printf *s)
{
	unsigned int	u;

	u = (unsigned int)va_arg(s->par, unsigned int);
	s->tmp = ft_itoa_base(u, "0123456789");
	ft_padding(s);
	ft_precision(s);
	s->fmt += 1;
	return ;
}

void		ft_x(t_printf *s)
{
	unsigned int	l;

	l = (unsigned int)va_arg(s->par, unsigned int);
	s->tmp = ft_itoa_base(l, "0123456789abcdef");
	ft_padding(s);
	ft_precision(s);
	s->fmt += 1;
	return ;
}

void		ft_x_up(t_printf *s)
{
	unsigned int	l;

	l = (unsigned int)va_arg(s->par, unsigned int);
	s->tmp = ft_itoa_base(l, "0123456789ABCDEF");
	ft_padding(s);
	ft_precision(s);
	s->fmt += 1;
	return ;
}

/*
*******************************************************************************
**									DISPLAY
*******************************************************************************
*/

void		ft_init_flags(t_printf *s)
{
	s->minus = 0;
	s->positive = 0;
	s->zero = 0;
	s->space = 0;
	s->sharp = 0;
	s->star = 0;
	s->width = 0;
	s->precision = 0;
	s->dot = 0;
	return ;
}

int		ft_char_is_flag(t_printf *s)
{
	char	*flags;
	int		i;

	flags = "-+0 #*";
	i = 0;
	while (i < 6)
	{
		if (s->fmt[0] == flags[i])
			return (1);
		i++;
	}
	return (0);
}

void		ft_get_flags(t_printf *s)
{
	ft_init_flags(s);
	while (ft_char_is_flag(s) > 0)
	{
		if (s->fmt[0] == '-')
			s->minus = 1;
		if (s->fmt[0] == '+')
			s->positive = 1;
		if (s->fmt[0] == '0')
			s->zero = 1;
		if (s->fmt[0] == ' ')
			s->space = 1;
		if (s->fmt[0] == '#')
			s->sharp = 1;
		if (s->fmt[0] == '*')
			s->star = 1;
		s->fmt += 1;
	}
	return ;
}

void		ft_get_width(t_printf *s)
{
	int width;

	width = 0;
	if (s->star == 1 && s->dot == 0)
	{
		s->width = (int)va_arg(s->par, int);
		if (s->width < 0)
		{
			s->width = -s->width;
			s->star = 2;
		return ;	
		}
	}
	if (s->width == 0 && s->dot == 0)
	{
		while (s->fmt[0] >= '0' && s->fmt[0] <= '9')
		{
			width = (width * 10) + (s->fmt[0] - '0');
			s->fmt++;
		}
		s->width = width;
	}
	return ;
}

void		ft_get_precision(t_printf *s)
{
	int pres;

	pres = 0;
	if (s->fmt[0] == '.')
	{
		s->dot = 1;
		s->fmt += 1;
	}
	if (s->dot == 1)
	{
		while (s->fmt[0] >= '0' && s->fmt[0] <= '9')
		{
			pres = (pres * 10) + (s->fmt[0] - '0');
			s->fmt++;
		}
		s->precision = pres;
	}
	ft_get_precision2(s);
	return ;
}

void		ft_get_precision2(t_printf *s)
{
	int pres;

	pres = 0;
	if (s->fmt[0] == '*' && s->dot == 1)
	{
		s->star = 1;
		s->fmt++;
		pres = (int)va_arg(s->par, int);
		if (pres < 0)
			pres = -pres;
		s->precision = pres;	
	}	
	return ;
}

int			ft_printf(const char *format, ...)
{
	t_printf	s;

	s.fmt = (char *)format;
	if (!(s.str = (char *)ft_calloc(1, sizeof(char*))))
		return (-1);
	va_start(s.par, format);
	while (s.fmt[0])
	{
	//	s.str = ft_strjoin_n(s.str, s.fmt, ft_int_strchr(s.fmt, '%'));
		s.str = ft_strjoin_endl(s.str, s.fmt);
		s.fmt += ft_int_strchr(s.fmt, '%') + 1;
		ft_get_flags(&s);
		ft_get_precision(&s);
		ft_get_width(&s);
//		ft_get_size(&s);
		ft_get_type(&s);
		if (ft_int_strchr(s.fmt, '%') == -1)
		{
			s.str = ft_strjoin(s.str, s.fmt);
			s.fmt += ft_int_strchr(s.fmt, '\0');
		}
	}
	va_end(s.par);
	ft_putstr_fd(s.str, 1);
	return (ft_strlen(s.str));
}
