/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:29:57 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/23 18:01:38 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_printf	s;

	s.fmt = (char *)format;
	s.michel = 0;
	va_start(s.par, format);
	while (s.fmt[0])
	{
		while (s.fmt[0] != '%' && s.fmt[0] != 0)
		{
			write(1, &s.fmt[0], 1);
			s.michel++;
			s.fmt++;
		}

		if (s.fmt[0] == '%')
		{
			s.fmt++;
			ft_parsing(&s);
			s.fmt++;
		}
	}
	va_end(s.par);
	return (s.michel);
}
