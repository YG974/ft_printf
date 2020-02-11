# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 19:33:02 by ygeslin           #+#    #+#              #
#    Updated: 2020/02/11 15:07:22 by ygeslin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
SRCS    =	libft/ft_isascii.c \
			libft/ft_strlcpy.c \
			libft/ft_memcpy.c \
			libft/ft_toupper.c \
			libft/ft_atoi.c \
			libft/ft_isdigit.c \
			libft/ft_memmove.c \
			libft/ft_strlen.c \
			libft/ft_bzero.c \
			libft/ft_isprint.c \
			libft/ft_memset.c \
			libft/ft_strncmp.c \
			libft/ft_calloc.c \
			libft/ft_memccpy.c \
			libft/ft_strchr.c \
			libft/ft_strnstr.c \
			libft/ft_isalnum.c \
			libft/ft_memchr.c \
			libft/ft_strdup.c \
			libft/ft_strrchr.c \
			libft/ft_isalpha.c \
			libft/ft_memcmp.c \
			libft/ft_strlcat.c \
			libft/ft_tolower.c \
			libft/ft_substr.c \
			libft/ft_strjoin.c \
			libft/ft_strtrim.c \
			libft/ft_split.c \
			libft/ft_itoa.c \
			libft/ft_strmapi.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_lstnew_bonus.c \
			libft/ft_lstadd_front_bonus.c \
			libft/ft_lstsize_bonus.c \
			libft/ft_lstlast_bonus.c \
			libft/ft_lstadd_back_bonus.c \
			libft/ft_lstdelone_bonus.c \
			libft/ft_lstclear_bonus.c \
			libft/ft_lstiter_bonus.c \
			libft/ft_lstmap_bonus.c \
			ft_printf.c \
			ft_utils.c \
			ft_parsing.c \
			ft_parsing2.c \
			ft_padding.c \
			ft_type.c \
			ft_type2.c \

SRCDIR    = ./
CC        = gcc
FLAGS    = -Wall -Wextra -Werror
OBJ        = $(addprefix $(SRCDIR), $(SRCS:.c=.o))

$(SRCDIR)%.o:    $(SRCDIR)%.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME):         $(OBJ)
	ar rc $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:         clean
	rm -f $(NAME)

re:             fclean all

test:	${NAME}
	gcc ${NAME} main.c 
	./a.out
.PHONY:            all clean fclean re

