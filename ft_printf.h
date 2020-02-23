/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:23:42 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/23 18:35:47 by ygeslin          ###   ########.fr       */
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
	char		*tmp;
	int			michel;
	int			tmp_len;
	int			sign;
	int			p;
	int			null;
	int			minus;
	int			positive;
	int			zero;
	int			space;
	int			sharp;
	int			star;
	int			width;
	int			neg_width;
	int			neg_precision;
	int			dot;
	int			precision_on;
	int			width_on;
	int			precision;
	va_list		par;
}				t_printf;

int				ft_printf(const char *format, ...);
void			ft_get_flags(t_printf *ptr);
void			ft_init_flags(t_printf *ptr);
int				ft_char_is_flag(t_printf *ptr);
void			ft_get_type(t_printf *ptr);
void			ft_get_width(t_printf *ptr);
void			ft_get_precision(t_printf *s);
void			ft_get_precision2(t_printf *s);
void			ft_parsing(t_printf *s);
void			ft_no_arg(t_printf *s);
void			ft_star(t_printf *s);
void			ft_preci_star(t_printf *s);
int				ft_int_strchr(const char *s, int c);
char			*ft_itoa_base(long	nbr, char *base);
char			*ft_strjoin_endl(char *s1, char *s2);
char			*ft_strjoin_n(char *s1, char *s2, int n);
char			*ft_strjoin2_n(char *s1, char *s2, int n);
char			*ft_strjoin1(char *s1, char *s2);
char			*ft_strjoin2(char *s1, char *s2);
char			*ft_strjoin3(char *s1, char *s2);
void			ft_c(t_printf *ptr);
void			ft_s(t_printf *ptr);
void			ft_s2(t_printf *ptr);
void			ft_s3(t_printf *ptr);
void			ft_p(t_printf *ptr);
void			ft_d(t_printf *ptr);
void			ft_i(t_printf *ptr);
void			ft_u(t_printf *ptr);
void			ft_x(t_printf *ptr);
void			ft_x_up(t_printf *ptr);
void			ft_x(t_printf *ptr);
void			ft_n(t_printf *ptr);
void			ft_precision(t_printf *ptr);
void			ft_precision2(t_printf *ptr);
void			ft_pourcent(t_printf *ptr);
void			ft_order(t_printf *ptr);
void			ft_order2(t_printf *ptr);
void			ft_order3(t_printf *ptr);
void			ft_order4(t_printf *ptr);
void			ft_order5(t_printf *ptr);
void			ft_order6(t_printf *ptr);
void			ft_write_arg(t_printf *ptr);
void			ft_write_preci(t_printf *ptr);
void			ft_write_preci_zero(t_printf *ptr);
void			ft_write_width(t_printf *ptr);
void			ft_write_width2(t_printf *ptr);
void			ft_write_width3(t_printf *ptr);
void			ft_write_width_zero(t_printf *ptr);
void			ft_write_width_zero2(t_printf *ptr);
void			ft_write_sign(t_printf *ptr);
void			ft_write_width_str(t_printf *ptr);
void			ft_write_width_str2(t_printf *ptr);
void			ft_write_width_str3(t_printf *ptr);
void			ft_write_preci_str(t_printf *ptr);
void			ft_write_str(t_printf *ptr);
void			ft_write_str2(t_printf *ptr);
void			ft_print_s(t_printf *s);
void			ft_print_s2(t_printf *s);
void			ft_print_s3(t_printf *s);
void			ft_print_s4(t_printf *s);
void			ft_print_s5(t_printf *s);
void			ft_print_s6(t_printf *s);
void			ft_pad_1(t_printf *s);
void			ft_pad_2(t_printf *s);
void			ft_pad_3(t_printf *s);
void			ft_pad_4(t_printf *s);
void			ft_pad_5(t_printf *s);
void			ft_pad_6(t_printf *s);
void			ft_pad_7(t_printf *s);
void			ft_pad_8(t_printf *s);
void			ft_pad_9(t_printf *s);
void			ft_pad_10(t_printf *s);
void			ft_pad_11(t_printf *s);
void			ft_pad_12(t_printf *s);
void			ft_pad_13(t_printf *s);

#endif
