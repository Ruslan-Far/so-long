# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 14:17:48 by ljaehaer          #+#    #+#              #
#    Updated: 2021/11/17 19:25:15 by ljaehaer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	srcs/ft_printf.c srcs/ft_printf_utils.c srcs/ft_printf_utils_2.c srcs/ft_printf_utils_3.c\
				libft/ft_strlen.c libft/ft_putchar_fd.c libft/ft_putnbr_fd.c libft/ft_putnbr_u_fd.c libft/ft_putstr_fd.c

HEADER		=	incs/ft_printf.h incs/libft.h

OBJS		=	${SRCS:%.c=%.o}

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

.PHONY	:		all clean fclean re bonus

all		:		${NAME}

${NAME}	:		${OBJS}
	ar rcs ${NAME} $?

srcs/%.o :		srcs/%.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

libft/%.o :		libft/%.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean	:		
	${RM} ${OBJS} ${OBJS_B}

fclean	:		clean
	${RM} ${NAME}

re		:		fclean all