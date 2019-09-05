# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbirov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/08 14:42:18 by rbirov            #+#    #+#              #
#    Updated: 2019/07/10 16:26:47 by rbirov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visual

FLAGS = -lmlx -framework OpenGL -framework AppKit -lm

SRC = main.c \
    bot_name.c \
    create_map.c \
    start_battle.c \
    make_visual.c \
    ft_itoa.c \
		key_set.c
LIB_DIR = ../libft/
LFT = $(LFT_DIR)libft.a

OBJ = $(SRC:.c=.o)

INCLUDES = ../libft/includes/


all: $(NAME)

$(NAME): $(OBJ)
	gcc	$(FLAGS) $(OBJ) -o $(NAME) -L $(LIB_DIR) -lft

%.o: %.c
	gcc -Wall -Werror -Wextra -o $@ -c $< -I $(INCLUDES)

clean:
	/bin/rm -f $(OBJ)

fclean:	clean
	/bin/rm -f $(NAME)

re:	fclean	all

.PHONY: clean fclean all re



