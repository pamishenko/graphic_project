# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/02 09:37:51 by pavel             #+#    #+#              #
#    Updated: 2022/04/02 11:19:21 by ttanja           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_get_next_line_utils.c \
		ft_get_next_line.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isnum.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c 

OBJ		= $(SRC:.c=.o)
DEPS	= ${SRC:.c=.d}

HEADER	=	./includes/
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I $(HEADER) -MMD -MP -g
ARRC	=	ar rc
REMOVE	=	rm -f
RANLIB	=	ranlib

all:	$(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(ARRC) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

-include $(DEPS)

clean:
	$(REMOVE) $(OBJ) $(DEPS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: clean fclean all re