/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:21:58 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/11 14:50:33 by ygeslin          ###   ########.fr       */
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
	while (s.fmt[0])
	{
		s.str = ft_strjoin_endl(s.str, s.fmt);
		s.fmt += ft_int_strchr(s.fmt, '%') + 1;
		ft_parsing(&s);
		ft_get_precision(&s);
		ft_get_width(&s);
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





