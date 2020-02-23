/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:21:46 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/23 18:13:21 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_padding_precision(t_printf *s)
{
	char	*pad;
	int		l;

	l = 0;
	pad = NULL;
	if (s->dot == 0 && s->precision == 0)
	{
		s->precision = -1;
	}
	if ((s->precision > l - s->sign && s->dot == 1 && s->neg_precision == 0))
	{
		l = ft_strlen(s->tmp);
		l = (l > s->precision ? s->precision : l);
		if (!(pad = (char *)ft_calloc((s->precision - l + 1), sizeof(char))))
			return ;
		pad = ft_memset(pad, '0', s->precision - l);
		s->tmp = ft_strjoin2(pad, s->tmp);
		free(pad);
	}
	ft_padding_precision2(s);
	return ;
}

void		ft_padding_precision2(t_printf *s)
{
	char	*pad;
	int		l;

	pad = NULL;
	if ((s->zero == 1 && s->width > 0 && s->precision != 0) &&
	((s->neg_width == 0 && s->dot == 1) && (s->neg_precision == 1)))
	{
		l = ft_strlen(s->tmp) + s->sign;
		l = (l > s->width ? s->width : l);
		if (!(pad = (char *)ft_calloc((s->width - l + 1), sizeof(char))))
			return ;
		pad = ft_memset(pad, '0', s->width - l);
		s->tmp = ft_strjoin2(pad, s->tmp);
		free(pad);
	}
	if ((s->zero == 1 && s->width > 0 && s->dot == 0 && s->neg_width == 0
		&& s->minus == 0))
	{
		l = ft_strlen(s->tmp) + s->sign;
		l = (l > s->width ? s->width : l);
		if (!(pad = (char *)ft_calloc((s->width - l + 1), sizeof(char))))
			return ;
		pad = ft_memset(pad, '0', s->width - l);
		s->tmp = ft_strjoin2(pad, s->tmp);
		free(pad);
	}
	return ;
}

void		ft_padding2(t_printf *s)
{
	char	*pad;
	int		l;

	l = ft_strlen(s->tmp) + s->sign;
	pad = NULL;
	if (s->precision > l - s->sign || s->neg_width == 1 || s->zero == 1)
		ft_padding_precision(s);
	s->tmp_len = (ft_strlen(s->tmp) + s->sign > s->width ?
					s->width : ft_strlen(s->tmp) + s->sign);
	if (!(pad = (char *)ft_calloc((s->width - s->tmp_len + 1), sizeof(char))))
		return ;
	if (s->width <= s->precision && s->dot == 1
		&& (s->zero == 1 || s->pstar == 1))
		pad = ft_memset(pad, '0', ((s->precision - l > 0 ?
		s->precision - ft_strlen(s->tmp) : 0)));
	if ((s->width > 0 && s->width > s->precision && s->precision >= 0)
		|| s->wstar == 1)
	{
		if (s->sign == 1)
		{
			s->tmp = ft_strjoin2("-", s->tmp);
			s->sign = 0;
		}
		pad = ft_memset(pad, ' ', s->width - s->tmp_len - s->sign);
	}
	if ((s->minus == 1 || s->neg_width == 1))
		s->tmp = ft_strjoin(s->tmp, pad);
	else
		s->tmp = ft_strjoin2(pad, s->tmp);
	if (s->sign == 1)
		s->tmp = ft_strjoin2("-", s->tmp);
	s->str = ft_strjoin(s->str, s->tmp);
	if (pad)
		free(pad);
	return ;
}

void		ft_precision2(t_printf *s)
{
	char *pad;

	pad = NULL;
	if (!(pad = (char *)ft_calloc(1, sizeof(char))))
		return ;
	if (s->precision < 0)
	{
		s->precision = 1;
		s->pstar = 1;
	}
	if (s->pdot == 1)
		s->tmp = ft_strjoin_n(pad, s->tmp, s->precision);
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:17:07 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/14 10:52:43 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_parsing(t_printf *s)
{
	ft_get_flags(s);
	ft_get_precision(s);
	ft_get_width(s);
	ft_get_type(s);
	return ;
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
			ft_star(s);
		s->fmt += 1;
	}
	if (s->fmt[0] == '.' && s->star > 0)
		ft_preci_star(s);
	return ;
}

void		ft_star(t_printf *s)
{
	s->width = (int)va_arg(s->par, int);
	s->wstar = 1;
	if (s->width < 0)
	{
		s->width = -s->width;
		s->neg_width = 1;
	}
	return ;
}

void		ft_preci_star(t_printf *s)
{
	if (s->fmt[0] == '*')
	{
		s->precision = (int)va_arg(s->par, int);
		s->pdot = 1;
		s->pstar = 1;
		s->fmt++;
	}
	return ;
}

void		ft_init_flags(t_printf *s)
{
	s->minus = 0;
	s->positive = 0;
	s->zero = 0;
	s->space = 0;
	s->sharp = 0;
	s->star = 0;
	s->wstar = 0;
	s->pstar = 0;
	s->pdot = 0;
	s->width = 0;
	s->precision = 0;
	s->dot = 0;
	s->sign = 0;
	s->neg_width = 0;
	s->neg_precision = 0;
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:20:09 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/14 09:43:22 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_char_is_flag(t_printf *s)
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

void		ft_get_width(t_printf *s)
{
	int width;

	width = 0;
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
			s->pdot = 1;
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
		s->pdot = 1;
		if (pres < 0)
		{
			pres = 1;
			s->neg_precision = 1;
		}
		s->precision = pres;
	}
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:21:58 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/14 11:46:22 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_printf	s;

	s.fmt = (char *)format;
	if (!(s.str = (char *)ft_calloc(1, sizeof(char*))))
		return (-1);
	va_start(s.par, format);
	s.michel = 0;
	while (s.fmt[0])
	{
		s.str = ft_strjoin_endl(s.str, s.fmt);
		s.fmt += ft_int_strchr(s.fmt, '%') + 1;
		ft_parsing(&s);
		if (ft_int_strchr(s.fmt, '%') == -1)
		{
			s.str = ft_strjoin(s.str, s.fmt);
			s.fmt += ft_int_strchr(s.fmt, '\0');
		}
		ft_putstr_fd(s.str, 1);
		s.michel += ft_strlen(s.str);
		s.str = 0;
		free(s.str);
	}
	va_end(s.par);
	return (s.michel);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spadding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:46:16 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/14 12:17:08 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_spadding(t_printf *s)
{
	char	*pad;

	s->tmp_len = (ft_strlen(s->tmp) > s->width ? s->width : ft_strlen(s->tmp));
	if (!(pad = (char *)ft_calloc((s->width - s->tmp_len + 1), sizeof(char))))
		return ;
	if ((s->width > 0 && s->precision >= 0) || s->wstar == 1)
		pad = ft_memset(pad, ' ', s->width - s->tmp_len);
	if ((s->minus == 1 || s->neg_width == 1))
		s->tmp = ft_strjoin(s->tmp, pad);
	else
		s->tmp = ft_strjoin(pad, s->tmp);
	s->str = ft_strjoin(s->str, s->tmp);
	free(pad);
	return ;
}

void		ft_sprecision(t_printf *s)
{
	char *pad;

	if (!(pad = (char *)ft_calloc(1, sizeof(char))))
		return ;
	if (s->precision < 0)
	{
		s->precision = 1;
		s->pstar = 1;
	}
	if ((s->pdot == 1 || s->dot == 1 || s->pstar) && s->neg_precision == 0)
		s->tmp = ft_strjoin_n(pad, s->tmp, s->precision);
	return ;
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*str;

	if (!(s2 && s1))
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
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
	str[len1 + len2] = '\0';
	free(s2);
	return (str);
}

char		*ft_strjoin2_n(char *s1, char *s2, int n)
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
	free(s2);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:23:33 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/14 10:58:03 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_get_type(t_printf *s)
{
	if (s->fmt[0] == '.')
		ft_get_precision(s);
	if (s->fmt[0] == 'c')
	{
		ft_c(s);
		s->fmt += 1;
	}
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

void		ft_pourcent(t_printf *s)
{
	char	tmp;

	if (!(s->tmp = (char *)ft_calloc(2, sizeof(char))))
		return ;
	tmp = '%';
	s->tmp[0] = tmp;
	s->str = ft_strjoin(s->str, s->tmp);
	s->fmt += 1;
	return ;
}

void		ft_c(t_printf *s)
{
	char	tmp;
	char	*pad;

	if (s->width == 0)
		s->width = 1;
	if (!(pad = (char *)ft_calloc((s->width + 1), sizeof(char))))
		return ;
	tmp = (char)va_arg(s->par, int);
	ft_putstr_fd(s->str, 1);
	if ((s->width > 0) || s->wstar == 1)
		pad = ft_memset(pad, ' ', s->width - 1);
	if ((s->minus == 1 || s->neg_width == 1))
	{
		write(1, &tmp, 1);
		ft_putstr_fd(pad, 1);
	}
	else
	{
		ft_putstr_fd(pad, 1);
		write(1, &tmp, 1);
	}
	s->michel += ft_strlen(pad) + ft_strlen(s->str) + 1;
	s->str = 0;
	free(pad);
	return ;
}

void		ft_s(t_printf *s)
{
	s->tmp = ((char*)va_arg(s->par, char *));
	if (s->tmp == NULL)
		s->tmp = ft_strjoin("(nul", "l)");
	ft_sprecision(s);
	ft_spadding(s);
	s->fmt += 1;
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:27:45 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/14 09:42:50 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_p(t_printf *s)
{
	long	ptr;

	ptr = (long)va_arg(s->par, long);
	if (ptr == 0)
	{
		if (!(s->tmp = (char *)malloc(2 * sizeof(char))))
			return ;
		s->tmp[0] = '0';
		s->tmp[1] = '\0';
		if (s->dot == 1 && s->precision == 0)
			s->tmp[0] = '\0';
	}
	else
		s->tmp = ft_itoa_base(ptr, "0123456789abcdef");
	s->tmp = ft_strjoin("0x", s->tmp);
	ft_padding2(s);
	ft_precision2(s);
	s->fmt += 1;
	return ;
}

void		ft_d(t_printf *s)
{
	int		d;

	d = (int)va_arg(s->par, int);
	if (d < 0)
	{
		s->sign = 1;
		d = -d;
	}
	if (d == 0)
	{
		if (!(s->tmp = (char *)malloc(2 * sizeof(char))))
			return ;
		s->tmp[0] = '0';
		s->tmp[1] = '\0';
		if (s->dot == 1 && s->precision == 0)
			s->tmp[0] = '\0';
	}
	else
		s->tmp = ft_itoa_base(d, "0123456789");
	ft_padding2(s);
	ft_precision2(s);
	s->fmt += 1;
	return ;
}

void		ft_u(t_printf *s)
{
	unsigned int	u;

	u = (unsigned int)va_arg(s->par, unsigned int);
	if (u == 0)
	{
		if (!(s->tmp = (char *)malloc(2 * sizeof(char))))
			return ;
		s->tmp[0] = '0';
		s->tmp[1] = '\0';
		if (s->dot == 1 && s->precision == 0)
			s->tmp[0] = '\0';
	}
	else
		s->tmp = ft_itoa_base(u, "0123456789");
	ft_padding2(s);
	ft_precision2(s);
	s->fmt += 1;
	return ;
}

void		ft_x(t_printf *s)
{
	unsigned int	l;

	l = (unsigned)va_arg(s->par, unsigned int);
	if (l == 0)
	{
		if (!(s->tmp = (char *)malloc(2 * sizeof(char))))
			return ;
		s->tmp[0] = '0';
		s->tmp[1] = '\0';
		if (s->dot == 1 && s->precision == 0)
			s->tmp[0] = '\0';
	}
	else
		s->tmp = ft_itoa_base(l, "0123456789abcdef");
	ft_padding2(s);
	ft_precision2(s);
	s->fmt += 1;
	return ;
}

void		ft_x_up(t_printf *s)
{
	unsigned int	l;

	l = (unsigned int)va_arg(s->par, unsigned int);
	if (l == 0)
	{
		if (!(s->tmp = (char *)malloc(2 * sizeof(char))))
			return ;
		s->tmp[0] = '0';
		s->tmp[1] = '\0';
		if (s->dot == 1 && s->precision == 0)
			s->tmp[0] = '\0';
	}
	else
		s->tmp = ft_itoa_base(l, "0123456789ABCDEF");
	ft_padding2(s);
	ft_precision2(s);
	s->fmt += 1;
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:14:36 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/14 11:32:50 by ygeslin          ###   ########.fr       */
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

char		*ft_strjoin_endl(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*str;

	len1 = (s1 == NULL ? 0 : ft_strlen(s1));
	len2 = (ft_int_strchr(s2, '%') == -1 ?
	0 : ft_int_strchr(s2, '%'));
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

char		*print_nbr_base(long nb, char *base, int len_base, int len_res)
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:40:07 by mchardin          #+#    #+#             */
/*   Updated: 2020/02/14 11:09:24 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int				ft_ft_printff(const char *str, ...);


int main()
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	ft_printf(" --- Return : %d\n", ft_printf("Simple input test"));
	ft_printf(" --- Return : %d\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2
	ft_printf(" --- Return : %d\n", ft_printf("%0i, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c)); //T3
	ft_printf(" --- Return : %d\n", ft_printf("%1i, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c)); //T4
	ft_printf(" --- Return : %d\n", ft_printf("%2i, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c)); //T5
	ft_printf(" --- Return : %d\n", ft_printf("%3i, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c)); //T6
	ft_printf(" --- Return : %d\n", ft_printf("%4i, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c)); //T7
	ft_printf(" --- Return : %d\n", ft_printf("%5i, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c)); //T8
	ft_printf(" --- Return : %d\n", ft_printf("%6i, %6d, %6d, %6d, %6d, %6d", i, j, k, l, m, c)); //T9
	ft_printf(" --- Return : %d\n", ft_printf("%7i, %7d, %7d, %7d, %7d, %7d", i, j, k, l, m, c)); //T10
	ft_printf(" --- Return : %d\n", ft_printf("%8i, %8d, %8d, %8d, %8d, %8d", i, j, k, l, m, c)); //T11
	ft_printf(" --- Return : %d\n", ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c)); //T12
	ft_printf(" --- Return : %d\n", ft_printf("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d", i, j, k, l, m, c)); //T13
	ft_printf(" --- Return : %d\n", ft_printf("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d", i, j, k, l, m, c)); //T14
	ft_printf(" --- Return : %d\n", ft_printf("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c)); //T15
	ft_printf(" --- Return : %d\n", ft_printf("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c)); //T16
	ft_printf(" --- Return : %d\n", ft_printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c)); //T17
	ft_printf(" --- Return : %d\n", ft_printf("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c)); //T18
	ft_printf(" --- Return : %d\n", ft_printf("%-i, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c)); //T19
	ft_printf(" --- Return : %d\n", ft_printf("%.i, %.d, %.d, %.d, %.d, %.d", i, j, k, l, m, c)); //T20
	ft_printf(" --- Return : %d\n", ft_printf("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d", i, j, k, l, m, c)); //T21
	ft_printf(" --- Return : %d\n", ft_printf("%00i, %00d, %00d, %00d, %00d, %00d", i, j, k, l, m, c)); //T22
	ft_printf(" --- Return : %d\n", ft_printf("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c)); //T23
	ft_printf(" --- Return : %d\n", ft_printf("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d", i, j, k, l, m, c)); //T24
	ft_printf(" --- Return : %d\n", ft_printf("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d", i, j, k, l, m, c)); //T25
	ft_printf(" --- Return : %d\n", ft_printf("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d", i, j, k, l, m, c)); //T26
	ft_printf(" --- Return : %d\n", ft_printf("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d", i, j, k, l, m, c)); //T27
	ft_printf(" --- Return : %d\n", ft_printf("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d", i, j, k, l, m, c)); //T28
	ft_printf(" --- Return : %d\n", ft_printf("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d", i, j, k, l, m, c)); //T29
	ft_printf(" --- Return : %d\n", ft_printf("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c)); //T30
	ft_printf(" --- Return : %d\n", ft_printf("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c)); //T31
	ft_printf(" --- Return : %d\n", ft_printf("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d", i, j, k, l, m, c)); //T32
	ft_printf(" --- Return : %d\n", ft_printf("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d", i, j, k, l, m, c)); //T33
	while (a < 5) //T34-69
	{
		ft_printf(" --- Return : %d\n", ft_printf("%*i, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c));
		ft_printf(" --- Return : %d\n", ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c));
		ft_printf(" --- Return : %d\n", ft_printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c));
		ft_printf(" --- Return : %d\n", ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c));
		a++;
	}
	a = -2;
	while(a < 5) //T70-177
	{
		b = -2;
		while (b < 5)
		{
			ft_printf(" --- Return : %d\n", ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c));
			ft_printf(" --- Return : %d\n", ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c));
			ft_printf(" --- Return : %d\n", ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c));
			b++;
		}
		a++;
	}
	a = 19;
	b = 14;
	ft_printf(" --- Return : %d\n", ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, -42, a, b, 42, -a, -b, -42, -a, -b, 42, -a, b, -42, -a, b, 42, a, -b, -42, a, -b, 42)); //T178
	ft_printf(" --- Return : %d\n", ft_printf("%12.12i, %12.12d", -42, 42)); //T179
	ft_printf(" --- Return : %d\n", ft_printf("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r)); //T180
	ft_printf(" --- Return : %d\n", ft_printf("%2s, %2s, %2s, %2s, %2s", n, o, p, q, r)); //T181
	ft_printf(" --- Return : %d\n", ft_printf("%3s, %3s, %3s, %3s, %3s", n, o, p, q, r)); //T182
	ft_printf(" --- Return : %d\n", ft_printf("%4s, %4s, %4s, %4s, %4s", n, o, p, q, r)); //T183
	ft_printf(" --- Return : %d\n", ft_printf("%15s, %15s, %15s, %15s, %15s", n, o, p, q, r)); //T184
	ft_printf(" --- Return : %d\n", ft_printf("%16s, %16s, %16s, %16s, %16s", n, o, p, q, r)); //T185
	ft_printf(" --- Return : %d\n", ft_printf("%17s, %17s, %17s, %17s, %17s", n, o, p, q, r)); //T186
	ft_printf(" --- Return : %d\n", ft_printf("%.s, %.s, %.s, %.s, %.s", n, o, p, q, r)); //T186
	ft_printf(" --- Return : %d\n", ft_printf("%1.s, %1.s, %1.s, %1.s, %1.s", n, o, p, q, r)); //T186
	a = -4;
	while (a < 5) //T187-213
	{
		ft_printf(" --- Return : %d\n", ft_printf("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		ft_printf(" --- Return : %d\n", ft_printf("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		ft_printf(" --- Return : %d\n", ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		a++;
	}
	a = -2;
	while(a < 5) //T70-177
	{
		b = -2;
		while (b < 5)
		{
			ft_printf(" --- Return : %d\n", ft_printf("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
			ft_printf(" --- Return : %d\n", ft_printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
			b++;
		}
		a++;
	}

	ft_printf(" --- Return : %d\n", ft_printf("%u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X", i, i, i, j, j, j, k, k, k, l, l, l, m, m, m, c, c, c, d, d, d, e, e, e)); //T214
	a = -1;
	while (a < 5) //T214-256
	{
		ft_printf(" --- Return : %d\n", ft_printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		ft_printf(" --- Return : %d\n", ft_printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		ft_printf(" --- Return : %d\n", ft_printf("%-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		ft_printf(" --- Return : %d\n", ft_printf("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		a++;
	}
	a = -1;
	while(a < 5) //T257-346
	{
		b = -1;
		while (b < 5)
		{
			ft_printf(" --- Return : %d\n", ft_printf("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			ft_printf(" --- Return : %d\n", ft_printf("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			ft_printf(" --- Return : %d\n", ft_printf("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			b++;
		}
		a++;
	}
	ft_printf(" --- Return : %d\n", ft_printf("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0)); //T347
	a = 8;
	while (a < 12) //
	{
		ft_printf(" --- Return : %d\n", ft_printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
		ft_printf(" --- Return : %d\n", ft_printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
		a++;
	}
	a = f;
	b = g;
	ft_printf(" --- Return : %d\n", ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c));
	ft_printf(" --- Return : %d\n", ft_printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
	ft_printf(" --- Return : %d\n", ft_printf("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
	ft_printf(" --- Return : %d\n", ft_printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));

	a = 12;
	b = 18;
	ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c));
	ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], -a, p[0], -a, q[0], -a, r[0], -a, c));
	ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], q[0], a, q[0], a, p[0], a, p[0], a, c));
	ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c", -12, -1, -255, a, -12, a, -1, a, -255));
	ft_printf(" --- Return : %d\n", ft_printf("%%, \t, \\, \", \', +"));
	ft_printf(" --- Return : %d\n", ft_printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i));
	ft_printf(" --- Return : %d\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i));
	ft_printf(" --- Return : %d\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j));
	ft_printf(" --- Return : %d\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l));
	ft_printf(" --- Return : %d\n", ft_printf("%i, %d, %d, %d, %d, %d, %u, %x, %X", 0, 0, 0, 0, 0, 0, 0, 0, 0));
	ft_printf(" --- Return : %d\n", ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %*x, %*X", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0));
	ft_printf(" --- Return : %d\n", ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
	ft_printf(" --- Return : %d\n", ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
	// ^ Theoriquement un comportement indefini mais testé par la moulinette
    ft_printf(" --- Return : %d\n", ft_printf("(null)"));
	ft_printf(" --- Return : %d\n", ft_printf(""));

	sleep(5000);
	return (0);
}
