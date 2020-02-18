
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:21:58 by ygeslin           ##    #+#             */
/*   Updated: 2020/02/18 19:58:42 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_printf	s;

	s.fmt = (char *)format;
	if (!(s.str = (char *)ft_calloc(1, sizeof(char*))))
		return (-1);
	s.michel = 0;
	va_start(s.par, format);
	while (s.fmt[0])
	{
		s.str = ft_strjoin_endl(s.str, s.fmt);
		s.fmt += ft_int_strchr(s.fmt, '%') + 1;
		ft_parsing(&s);
		if (ft_int_strchr(s.fmt, '%') == -1)
		{
			s.str = ft_strjoin(s.str, s.fmt);
			s.fmt += ft_int_strchr(s.fmt, '\0');
			ft_putstr_fd(s.str, 1);
			s.michel += ft_strlen(s.str);
		}
		s.str[0] = '\0';
	}
	va_end(s.par);
	return (s.michel);
}
