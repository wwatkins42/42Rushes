# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 09:09:22 by wwatkins          #+#    #+#              #
#    Updated: 2016/02/27 12:07:09 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./libft/include/
LIB_PATH = ./libft/

NAME = puissance4
CC = gcc
CFLGS = -Werror -Wextra -Wall

SRC_NAME = main.c utils.c core.c check_victory.c
OBJ_NAME = $(SRC_NAME.c=.o)
LIB_NAME = libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)

.PHONY: re all clean fclean cleanlib fcleanlib nolib norme

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH) re
	$(CC) $(CFLGS) -L$(LIB_PATH) $(LIB) $(SRC) $(INC) -o $(NAME) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLGS) $(LIB) $(INC) -o $@ -c $<

nolib:
	$(CC) $(CFLGS) -L$(LIB_PATH) $(LIB) $(SRC) $(INC) -o $(NAME) $(OBJ)

cleanlib:
	make -C $(LIB_PATH) clean

fcleanlib:
	make -C $(LIB_PATH) fclean

clean: cleanlib
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean fcleanlib
	rm -fv $(NAME)

re: fclean all

norme:
	make -C $(LIB_PATH) norme
	norminette $(SRC) ./include/
