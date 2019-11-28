# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 19:33:02 by ygeslin           #+#    #+#              #
#    Updated: 2019/11/27 15:25:50 by ygeslin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	ft_printf.a
LIBFT=	libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = %.c

test : ${LIBFT}
	${CC} ${CFLAGS} *.c *.h ${LIBFT}
	./a.out
