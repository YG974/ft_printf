/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:23:42 by ygeslin           #+#    #+#             */
/*   Updated: 2019/12/04 16:41:52 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define ENDL '\n'
# define END '\0'
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_struct
{
	char		*fmt;
	char		*str;
	int			minus;
	int			positive;
	int			zero;
	int			space;
	int			sharp;
	int			star;
	int			width;
	int			precision;
	va_list		par;
}				t_printf;

int		ft_printf(const char *format, ...);
void	ft_get_flags(t_printf *ptr);
void	ft_init_flags(t_printf *ptr);
int		ft_char_is_flag(t_printf *ptr);
void	ft_get_type(t_printf *ptr);
void	ft_get_precision(t_printf *s);
char	*ft_itoa_base(long	nbr, char *base);
void	ft_c(t_printf *ptr);
void	ft_s(t_printf *ptr);
void	ft_p(t_printf *ptr);
void	ft_d(t_printf *ptr);
void	ft_i(t_printf *ptr);
void	ft_u(t_printf *ptr);
void	ft_x(t_printf *ptr);
void	ft_x_up(t_printf *ptr);
void	ft_x(t_printf *ptr);
void	ft_n(t_printf *ptr);
void	ft_f(t_printf *ptr);
void	ft_e(t_printf *ptr);
void	ft_g(t_printf *ptr);

#endif
