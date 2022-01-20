# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 22:53:26 by ttanja            #+#    #+#              #
#    Updated: 2022/01/19 18:51:53 by ttanja           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3d

LIBFT_PATH		=	./libft/
LIBFT_LIB		=	$(LIBFT_PATH)libft.a

MLX_PATH		=	./minilibx_opengl/
MLX_LIB			=	$(MLX_PATH)libmlx.*

HEADER_FOLDER	=	./includes/

HEADER_FILES	=	\
					${HEADER_FOLDER}cub3d.h 

SRC				=	\
					./src/cub3d.c 

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

OBJ				= ${SRC:.c=.o}

%.o: %.c ${HEADER_FILES}
	$(CC) $(CFLAGS) -I $(HEADER_FOLDER) -Imlx -Ift -c $< -o $@ 


all:		$(NAME) $(LIBFT_LIB)

$(NAME): $(OBJ) ${HEADER_FILES}
	make -C $(MLX_PATH)
	make -C $(LIBFT_PATH)
	cp $(MLX_LIB) ./
	cp $(LIBFT_LIB) ./
	$(CC) $(CFLAGS) -I ${HEADER_FOLDER} $(OBJ) -L ./ -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			make -C ${LIBFT_PATH} clean
			make -C ${MLX_PATH} clean
			${RM} ${OBJ}

fclean:		clean
			rm -f libmlx.*
			rm -f libft.a
			${RM} ${NAME} ${LIBFT_LIB} $(MLX_LIB)

re:			fclean all

.PHONY:		all clean fclean re
