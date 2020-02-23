/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:27:32 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/23 15:28:11 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void		ft_pad_5(t_printf *s)
{
	ft_write_sign(s);
	ft_write_preci(s);
	ft_write_arg(s);
	ft_write_width(s);
	return ;
}

void		ft_pad_6(t_printf *s)
{
	ft_write_sign(s);
	ft_write_preci(s);
	ft_write_arg(s);
	ft_write_width(s);
	return ;
}

void		ft_pad_7(t_printf *s)
{
	ft_write_sign(s);
	ft_write_preci(s);
	ft_write_arg(s);
	return ;
}

void		ft_pad_8(t_printf *s)
{
	ft_write_sign(s);
	ft_write_arg(s);
	return ;
}

void		ft_pad_10(t_printf *s)
{
	write(1, " ", 1);
	s->michel++;
	return ;
}
