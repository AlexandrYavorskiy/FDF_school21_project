# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Student <Student@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/18 22:15:01 by Student           #+#    #+#              #
#    Updated: 2020/07/20 09:42:56 by Student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = src/default_param.c \
		src/draw.c \
		src/fdf.c \
		src/menu.c \
		src/read.c \
		src/utills.c


FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -o $(NAME) $(FLAGS) $(OBJ) -framework OpenGL -framework AppKit libft/libft.a minilibx_macos/libmlx.a
	echo "Fdf done"

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all