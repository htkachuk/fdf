# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/10 14:33:40 by htkachuk          #+#    #+#              #
#    Updated: 2018/03/10 14:33:42 by htkachuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

SRC = src/ft_key.c src/ft_create_img.c src/fdf.c src/ft_picture.c src/ft_zoom.c  \
src/get_next_line.c src/print.c src/read_write_map.c 

INC = fdf.h get_next_line.h

OBJ = fdf.o ft_picture.o ft_zoom.o get_next_line.o print.o read_write_map.o ft_key.o ft_create_img.o

FLAG = -Wall -Werror -Wextra -g

all: $(NAME)


$(NAME): $(OBJ)
	@make -C ./libft all
	gcc -I . -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) libft/libft.a

%.o : src/%.c
	gcc $(FLAG) -c -o $@ $^

clean:
	/bin/rm -f $(OBJ)
	@make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all

.PHONY: re all clean fclean

