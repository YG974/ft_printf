/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:15:52 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/09 17:37:14 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"

int main(void)
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
	int		nb = 34;
	int 	t1 = 10;
	int 	t2 = 118;

	a = 3;
	ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c);
/*	a = -2;
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

	}*/
	return (0);
}
