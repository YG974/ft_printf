/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:15:52 by ygeslin           #+#    #+#             */
/*   Updated: 2019/12/04 16:55:36 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char c = 'z';
	char *s = "Melimelow";
	char *p = s;
	int d = -12945;
	int i = 8001;
	unsigned int u = 14654;
	int x = 2397;
	int X = x;
//	int len;

	ft_printf("\n%-9c", c);
	ft_printf("\n%-4s", s);
	ft_printf("\n%p", p);
	ft_printf("\n%+9d", d);
	ft_printf("\n%+9i", i);
	ft_printf("\n%9u", u);
	ft_printf("\n%9x", x);
	ft_printf("\n%9X", X);
	printf("\n----------------------------------------\n");
	printf("%-9c", c);
	printf("\n%-4s", s);
	printf("\n%p", p);
	printf("\n%+9d",d);
	printf("\n%+9i", i);
	printf("\n%9u", u);
	printf("\n%9x", x);
	printf("\n%9X\n", X);

/*
	printf("c = %c\n", c);
	printf("s = %s\n", s);
	printf("p = %p\n", p);
	printf("d = %15d\n", d);
	printf("i = %i\n", i);
	printf("u = %u\n", u);
	printf("x = %x\n", x);
	printf("X = %X\n", X);
	len = printf("%% = %s\n", "%");
	printf("s = %.5s\n", s);
	printf("s = %.*s\n",4, s);
	printf("d = %.8d\n", d);
	printf("d = %.*d\n",3, d);
	printf("s = %-.5s\n", s);
	printf("s = %-.*s\n",4, s);
	printf("u = %-.8d\n", u);
	printf("u = %-.*d\n",3, u);
	printf("d = %+d\n", d);
	printf("d = %+d\n", d);
	printf("u = %d\n", u);
	printf("u = % *d\n",9, u);
	printf("printf : len = %d\n", len);
*/
	return (0);
}
