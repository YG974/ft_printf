/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:21:58 by ygeslin           #+#    #+#             */
/*   Updated: 2019/11/28 18:19:24 by ygeslin          ###   ########.fr       */
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

void		ft_get_type(t_printf *s)
{
	if (s->fmt[0] == 'c')
		ft_c(s);
	if (s->fmt[0] == 's')
		ft_s(s);
/*
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
	if (s->fmt[0] == 'n')
		ft_n(s);
	if (s->fmt[0] == 'e')
		ft_e(s);
	if (s->fmt[0] == 'g')
		ft_g(s);
*/
	return ;
}

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
//		ft_get_flags();
//		ft_get_width();
//		ft_get_precision();
//		ft_get_size();
		ft_get_type(&s);
	}
	ft_putstr_fd(s.str, 1);
	return (1);
}
