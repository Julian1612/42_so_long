# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 10:32:35 by jschneid          #+#    #+#              #
#    Updated: 2022/08/20 22:47:09 by jschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FLAGS = -Wall -Werror -Wextra -Imlx -c $< -o $@

MANDATORY = main.c player_utils_00.c player_utils_01.c player.c map.c map_utils_00.c map_utils_01.c window.c window_utils_00.c collectible.c wall.c exit.c

CC = gcc

OBJ = $(MANDATORY:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@make -C libft/
	@make -C mlx/
	@mv ./libft/libft.a ./
	@mv ./mlx/libmlx.a ./
	@$(CC) $(OBJ) -L. -lmlx -lft -framework OpenGL -framework AppKit -o $(NAME)
	@echo "make done"

clean:
	@make clean -C libft/
	@make clean -C mlx/
	@/bin/rm -f $(OBJ) $(OBJB)
	@echo "make clean done"

fclean: clean
	@/bin/rm -f libft.a
	@/bin/rm -f libmlx.a
	@/bin/rm -f $(NAME)
	@echo "make fclean done"

re: fclean all
	@echo "make re done"

.PHONY:			all bonus clean fclean re
