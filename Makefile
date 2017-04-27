# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwithmor <iwithmor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 11:31:16 by iwithmor          #+#    #+#              #
#    Updated: 2017/04/10 04:49:55 by iwithmor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIB = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

SRC = main.c
SRC += new.c
SRC += new_fractals.c
SRC += start.c
SRC += draw.c
SRC += get_iteration.c
SRC += move.c
SRC += zoom.c
SRC += keys.c
SRC += mouse.c
SRC += enhance.c
SRC += color.c

OBJ = $(SRC:.c=.o)
ADD = -L./libft -lft -L./minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(ADD)

$(OBJ): $(LIB)
	gcc $(FLAGS) -I libft/ -I./minilibx/ -c $(SRC)

$(LIB):
	make -C libft/

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
