/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:15:52 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/13 15:14:47 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	/*
	char c = 'z';
	char *s = "Melimelow";
	char *p = s;
	int d = 12945;
	int i = 8001;
	unsigned int u = 14654;
	int x = 2397;
	int X = x;
//	int len;

//	ft_printf("%c", c);
	ft_printf("%d", ft_printf("\nma string :%0*sok%d", 14, s, d));
//	ft_printf("\n%p", p);
//	ft_printf("\n%d", d);
//	ft_printf("\n%i", i);
///	ft_printf("\n%u", u);
//	ft_printf("\n%x", x);
//	ft_printf("\n%X", X);
	printf("\n----------------------------------------\n");
//	printf("%c", c);
	printf("%d", printf("\nma string :%0*sok%d", 14, s, d));
//	printf("\n%p", p);
//	printf("\n%d", d);
//	printf("\n%i", i);
//	printf("\n%u", u);
//	printf("\n%x", x);
//	printf("\n%X\n", X);
*/
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

		a = -2;
		b = 2;
ft_printf(" --- Return : %d\n", ft_printf("%i, %d, %d, %d, %d, %s, %-c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j));
	return (0);
}
