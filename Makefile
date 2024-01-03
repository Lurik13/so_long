# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lribette <lribette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 18:24:32 by lribette          #+#    #+#              #
#    Updated: 2024/01/03 21:31:27 by lribette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = core/get_next_line/get_next_line.c \
			core/get_next_line/get_next_line_utils.c \
			core/error.c core/main.c

OBJECTS = $(SOURCES:.c=.o)
MLX = ./mlx_linux/libmlx.a
PRINTF = ./core/ft_printf/libftprintf.a

CC = cc
CMLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJECTS) $(MLX) $(PRINTF)
	$(CC) $(OBJECTS) $(MLX) $(PRINTF) $(CMLX) -o $(NAME)

$(MLX):
	make -C ./mlx_linux

$(PRINTF):
	make -C ./core/ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	make clean -C ./mlx_linux
	make clean -C ./core/ft_printf

fclean: clean
	$(RM) $(NAME) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re