# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 22:53:26 by ttanja            #+#    #+#              #
#    Updated: 2022/04/03 14:16:38 by ttanja           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

LIBS_PATH		=	./lib
LIBFT_PATH		=	$(LIBS_PATH)/libft/
LIBFT_LIB		=	$(LIBFT_PATH)libft.a

# MLX_PATH		=	$(LIBS_PATH)/minilibx_mms/
MLX_PATH		=	$(LIBS_PATH)/minilibx_opengl/
MLX_LIB			=	$(MLX_PATH)libmlx.*

HEADER_FOLDER	=	./includes/

HEADER_FILES	=	\
					${HEADER_FOLDER}mlx.h \
					${HEADER_FOLDER}libft.h \
					${HEADER_FOLDER}cub3d.h \
					${HEADER_FOLDER}defines.h

SRC_DIR			= src/
SRC				=	\
					drawrays_utils.c \
					drawrays.c \
					engine.c \
					errors.c \
					key_control.c \
					main.c \
					player.c \
					readcolor.c \
					readconfig.c \
					render.c \
					setwinsize.c \
					utils_math.c \
					utils_textures.c \
					utils.c 
					
					
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g

RM				=	rm -f

OBJS_DIR 	= 	objects/
OBJ 		= 	$(SRC:.c=.o)
OBJS 		= 	$(addprefix $(OBJS_DIR), $(OBJ))

$(OBJS_DIR)%.o :	$(SRC_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -L ./ -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -c $< -o $@

all:		$(NAME) $(LIBFT_LIB)

p:	re
	./cub3d map/lvl00.cub

$(NAME): $(OBJS) ${HEADER_FILES}
	make -C $(MLX_PATH)
	make -C $(LIBFT_PATH)
	cp $(MLX_LIB) ./ 
	cp $(LIBFT_LIB) ./
	cp $(MLX_PATH)mlx.h $(HEADER_FOLDER)
	cp $(LIBFT_PATH)includes/libft.h $(HEADER_FOLDER)
	$(CC) $(CFLAGS) -I ${HEADER_FOLDER} $(OBJS) -L ./ -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			make -C ${LIBFT_PATH} clean
			make -C ${MLX_PATH} clean
			${RM} -r ${OBJS_DIR}

fclean:		clean
			rm -f libmlx.*
			rm -f libft.a
			${RM} ${NAME} ${LIBFT_LIB} $(MLX_LIB)

re:			fclean all

.PHONY:		all clean fclean re
