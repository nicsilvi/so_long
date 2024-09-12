# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smercado <smercado@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 08:09:49 by smercado          #+#    #+#              #
#    Updated: 2024/09/12 14:14:47 by smercado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g 
//-fsanitize=address

MLX_PATH = src/mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -Lmlx -lXext -lX11

LIBFT_PATH = src/libft/



LIBFT_LIB = $(LIBFT_PATH)libft.a

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CFILES = check_path.c chekers.c grafics.c main.c errors.c utils.c gamming.c

OBJECTS = $(CFILES:.c=.o)

all: subsystems $(NAME)

%.o : %.c Makefile
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

subsystems:
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS) so_long.h Makefile
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

clean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	rm -f $(ML_PATH)libmlx.a

re: fclean all

.PHONY: all clean fclean re norm
