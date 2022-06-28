# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 00:10:08 by ljaehaer          #+#    #+#              #
#    Updated: 2022/02/14 11:33:48 by ljaehaer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRC			=	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
				src/so_long.c src/builds.c src/read_map.c src/funcs_check_error/funcs_check_error.c\
				src/funcs_check_error/funcs_check_error2.c src/funcs_check_error/funcs_check_error3.c\
				src/utils/utils.c src/utils/utils2.c src/utils/utils3.c src/utils/utils4.c\
				src/closes.c

HEADER		=	inc/so_long.h

OBJ			=	${SRC:%.c=%.o}

LIBFT_DIR	=	libft
FT_PRINTF_DIR	=	ft_printf
MLX_DIR		=	minilibx-linux

CC			=	gcc
SYS_LIBS	=	-lXext -lX11 -lm -lbsd
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

.PHONY	:		all clean fclean re bonus

all		:		${NAME}
	
${NAME}	:		${OBJ}
	make -C ${LIBFT_DIR}
	make -C ${FT_PRINTF_DIR}
	make -C ${MLX_DIR}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} -L./${LIBFT_DIR} -lft -L./${FT_PRINTF_DIR} -lftprintf -L./minilibx-linux -lmlx ${SYS_LIBS}

%.o		:		%.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean	:		
	${RM} ${OBJ}

fclean	:		clean
	make -C ${LIBFT_DIR} fclean
	make -C ${FT_PRINTF_DIR} fclean
	make -C ${MLX_DIR} clean
	${RM} ${NAME}

re		:		fclean all
