/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:21:58 by ygeslin           #+#    #+#             */
/*   Updated: 2019/12/03 18:27:44 by ygeslin          ###   ########.fr       */
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
	if (s->fmt[0] == 'c')
		ft_c(s);
	if (s->fmt[0] == 's')
		ft_s(s);
	if (s->fmt[0] == 'p')
		ft_p(s);
	if (s->fmt[0] == 'd')
		ft_d(s);
	if (s->fmt[0] == 'i')
		ft_i(s);
	if (s->fmt[0] == 'u')
		ft_u(s);
	if (s->fmt[0] == 'x')
		ft_x(s);
	if (s->fmt[0] == 'X')
		ft_x_up(s);
/*
	if (s->fmt[0] == 'n')
		ft_n(s);
	if (s->fmt[0] == 'e')
		ft_e(s);
	if (s->fmt[0] == 'g')
		ft_g(s);
*/
	return ;
}

/*
*******************************************************************************
**									DISPLAY
*******************************************************************************
*/

void		ft_c(t_printf *s)
{
	char tmp[2];

	tmp[0] = (char)va_arg(s->par, int);
	s->str = ft_strjoin(s->str, &tmp[0]);
	tmp[1] = '\0';
	s->fmt += 1;
	return ;
}

void		ft_s(t_printf *s)
{
	s->str = ft_strjoin(s->str, (char*)va_arg(s->par, char *));
	s->fmt += 1;
	return ;
}

void		ft_p(t_printf *s)
{
	long ptr;
	char *tmp;

	ptr = (long)va_arg(s->par, long);
	tmp = ft_itoa_base(ptr, "0123456789abcdef");
	s->str = ft_strjoin(s->str, "0x");
	s->str = ft_strjoin(s->str, tmp);
	s->fmt += 1;
	return ;
}

void		ft_d(t_printf *s)
{
	int		d;
	char	*tmp;

	d = (int)va_arg(s->par, int);
	tmp = ft_itoa_base(d, "0123456789");
	s->str = ft_strjoin(s->str, tmp);
	s->fmt += 1;
	return ;
}

void		ft_i(t_printf *s)
{
	int		i;
	char	*tmp;

	i = (int)va_arg(s->par, int);
	tmp = ft_itoa_base(i, "0123456789");
	s->str = ft_strjoin(s->str, tmp);
	s->fmt += 1;
	return ;
}

void		ft_u(t_printf *s)
{
	unsigned int	u;
	char			*tmp;

	u = (unsigned int)va_arg(s->par, unsigned int);
	tmp = ft_itoa_base(u, "0123456789");
	s->str = ft_strjoin(s->str, tmp);
	s->fmt += 1;
	return ;
}

void		ft_x(t_printf *s)
{
	long l;
	char *tmp;

	l = (long)va_arg(s->par, long);
	tmp = ft_itoa_base(l, "0123456789abcdef");
	s->str = ft_strjoin(s->str, tmp);
	s->fmt += 1;
	return ;
}

void		ft_x_up(t_printf *s)
{
	long l;
	char *tmp;

	l = (long)va_arg(s->par, long);
	tmp = ft_itoa_base(l, "0123456789ABCDEF");
	s->str = ft_strjoin(s->str, tmp);
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
		if(s->fmt[0] == '-')
			s->minus = 1;
		if(s->fmt[0] == '+')
			s->positive = 1;
		if(s->fmt[0] == '0')
			s->zero = 1;
		if(s->fmt[0] == ' ')
			s->space = 1;
		if(s->fmt[0] == '#')
			s->sharp = 1;
		if(s->fmt[0] == '*')
			s->star = 1;
		s->fmt += 1;
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
	while (s.fmt[0] != '\0')
	{
		s.str = ft_strjoin_endl(s.str, s.fmt);
		s.fmt += ft_int_strchr(s.fmt, '%') + 1;
		ft_get_flags(&s);
//		ft_get_width(&s);
//		ft_get_precision(&s);
//		ft_get_size(&s);
		ft_get_type(&s);
	}
	ft_putstr_fd(s.str, 1);
	return (1);
}
