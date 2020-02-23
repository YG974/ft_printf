/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:26:39 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/23 15:34:51 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void		ft_pad_0(t_printf *s)
{
	ft_write_width(s);
	return ;
}

void		ft_pad_1(t_printf *s)
{
	ft_write_width(s);
	ft_write_sign(s);
	ft_write_arg(s);
	return ;
}

void		ft_pad_2(t_printf *s)
{
	ft_write_sign(s);
	ft_write_arg(s);
	ft_write_width(s);
	return ;
}

void		ft_pad_3(t_printf *s)
{
	ft_write_sign(s);
	ft_write_width(s);
	ft_write_arg(s);
	return ;
}

void		ft_pad_4(t_printf *s)
{
	ft_write_sign(s);
	ft_write_preci(s);
	ft_write_width(s);
	ft_write_arg(s);
	return ;
}
