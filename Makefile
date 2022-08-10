# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 10:32:35 by jschneid          #+#    #+#              #
#    Updated: 2022/08/10 13:46:56 by jschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FLAGS = -Wall -Werror -Wextra -Imlx -c $< -o $@

MANDATORY = main.c player.c map.c get_next_line.c get_next_line_utils.c window.c collectible.c wall.c exit.c

CC = cc

OBJ = $(MANDATORY:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	@echo "make done"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@/bin/rm -f $(OBJ) $(OBJB)
	@echo "make clean done"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "make fclean done"

re: fclean all
	@echo "make re done"

.PHONY:			all bonus clean fclean re
