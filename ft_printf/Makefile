# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbirov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/13 10:31:14 by rbirov            #+#    #+#              #
#    Updated: 2019/05/28 13:43:34 by rbirov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CCFLAGS = gcc -Wall -Wextra -Werror

INC_DIR = includes/
INC = -I $(LFT_DIR)includes/ -I includes/

LFT_DIR = libft/

SRC_DIR = srcs/
SRC_NAME = ft_printf.c  utils.c parse_flag.c parse_format.c parse_mod.c convert_float.c set_print.c set_int_uint.c set_str.c
SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_DIR = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_DIR)
	cp $(LFT_DIR)/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC)
	mkdir -p $(OBJ_DIR)
	$(CCFLAGS) $(INC) -c $^
	mv -f *.o $(OBJ_DIR)

clean:
	make -C $(LFT_DIR) clean
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LFT_DIR) fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)