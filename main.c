/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:15:52 by ygeslin           #+#    #+#             */
/*   Updated: 2019/12/03 16:51:17 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
** 					% [flags][width][.precision][size][type]
** [FLAGS] = '-' / '+' / '0' / ' ' / '#'
** [WIDTH] = unsigned integer indicates the minimum width 
** [PRECISION] = unsigned integer indicate the precision after the '.'
** [SIZE] = converts the argument type in an other type ( l / ll / h / hh )
** [TYPE] = c / s / p / d / i / u / x / X / n / f / e / g 
**-----------------------------------------------------------------------------
**							Regular conversions
**-----------------------------------------------------------------------------
**	1) c = character 				| 2) s = string  
**	3) p = pointer(hex) 			| 4) d = decimal signed integer 
**	5) i = decimal signed integer	| 6) u = unsigned integer 
**	7) x = hexadecimal integer		| 8) X = uppercase hexadecimal integer
**-----------------------------------------------------------------------------
**								Regular flags
**-----------------------------------------------------------------------------
**	1) '-' = left justify			| 2) '0' = padding with '0'
**	3) '.' = precision 				| 4) '*' = padding or precision (arg+1) 
**-----------------------------------------------------------------------------
**									BONUS
**-----------------------------------------------------------------------------
**								Bonus conversions
**-----------------------------------------------------------------------------
**	1) n = Number of characters written by this printf
**	2) f = float : The argument is printed in the style `[-]ddd.ddd'
**	3) e = The argument is printed in the style e `[-d.ddd+-dd] scientific form
**	4) g = argument is printed style f or e -> full precision in minimum space.
**-----------------------------------------------------------------------------
**							Bonus lenght flags
**-----------------------------------------------------------------------------
**	1) 'h'  = converts an integer from a short to an int.
**	2) 'hh' = converts an integer from a char to an int.  
**	3) 'l'  = converts an integer into a long.
**	4) 'll' = converts an interger into a long long.
**-----------------------------------------------------------------------------
**							Bonus conversions flags
**-----------------------------------------------------------------------------
**	1) ''' = 
**	2) '#' = value should be printed in an alternate form(prefix, precision)
**	3) ' ' = Positive values begin with a blank.
**	4) '+' = Prefix the output value with a sign (+ or -) if signed type.
**-----------------------------------------------------------------------------
*/

#include "ft_printf.h"

int main(void)
{
	char c = 'z';
	char *s = "Melimelow";
	char *p = s;
	int d = -12945;
	int i = -8001;
	unsigned int u = 14654;
	int x = 2397;
	int X = x;
//	int len;

	ft_printf("%c", c);
	ft_printf("\n%s", s);
	ft_printf("\n%p", p);
	ft_printf("\n%d", d);
	ft_printf("\n%i", i);
	ft_printf("\n%u", u);
	ft_printf("\n%x", x);
	ft_printf("\n%X", X);
	printf("\n----------------------------------------\n");
	printf("%c", c);
	printf("\n%s", s);
	printf("\n%p", p);
	printf("\n%+-10d",d);
	printf("\n%+-10i", i);
	printf("\n%-10u", u);
	printf("\n%-10x", x);
	printf("\n%-10X", X);

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
