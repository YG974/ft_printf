/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:23:42 by ygeslin           #+#    #+#             */
/*   Updated: 2019/12/03 18:04:38 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	va_list		par;
}				t_printf;

int		ft_printf(const char *format, ...);
void	ft_get_flags(t_printf *ptr);
void	ft_init_flags(t_printf *ptr);
int		ft_char_is_flag(t_printf *ptr);
void	ft_get_type(t_printf *ptr);
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
