# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 10:32:35 by jschneid          #+#    #+#              #
#    Updated: 2022/08/18 21:33:24 by jschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

FLAGS = -Wall -Werror -Wextra -Imlx -c $< -o $@

MANDATORY = main.c player_utils.c player.c map.c map_utils.c window.c collectible.c wall.c exit.c

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
