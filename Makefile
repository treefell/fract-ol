# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chuang <chuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/14 17:34:15 by chuang            #+#    #+#              #
#    Updated: 2015/11/26 18:29:01 by chuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Wextra

SRC = complex.c\
	  drawfrac.c\
	  expose.c\
	  init_frac.c\
	  main.c\
	  keyboard.c\
	  mouse.c\
	  mandelbrot.c\
	  julia.c\
	  tree.c\
	  tricorn.c\
	  window.c

OBJS = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	Make -C libft
	Make -C minilibx_macos
	gcc $(OBJS) -I libft -L ./libft -L ./minilibx_macos -framework OpenGL -framework AppKit -lft -lmlx -o $(NAME)

%.o:%.c
	gcc -o $@ -c $< $(CFLAGS) -I./includes -I./libft/includes

clean:
	$(RM) $(OBJS)

fclean: clean
	make -C libft clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
