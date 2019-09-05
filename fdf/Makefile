# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbirov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/13 10:31:14 by rbirov            #+#    #+#              #
#    Updated: 2019/05/31 11:25:09 by rbirov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBS = -lmlx -lm -lft -L$(LFT_DIR) -L$(MLX_DIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEAD_DIR) -I$(LFT_HEAD) -I$(MLX_HEAD)

LFT = $(LFT_DIR)libft.a
LFT_DIR = ./libft/
LFT_HEAD = $(LFT_DIR)includes/

MLX = $(MLX_DIR)libmlx.a
MLX_DIR = ./minilibx_macos/
MLX_HEAD = $(MLX_DIR)

HEAD_NAME = fdf.h

HEAD_DIR = ./includes/
HEADS = $(addprefix $(HEAD_DIR), $(HEAD_NAME))

SRC_DIR = ./sources/
SRC_NAME = main.c\
	read_map.c\
	initialize.c\
	draw_pic.c\
	projection.c\
	key_setup.c\
	key_util.c\
	new_point.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_DIR = objects/
OBJ_NAME = $(patsubst %.c, %.o, $(SRC_NAME))
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(LFT) $(MLX) $(OBJ_DIR) $(OBJS)
	$(CC) $(FLAGS) $(LIBS) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LFT):
	$(MAKE) -sC $(LFT_DIR)

$(MLX):
	$(MAKE) -sC $(MLX_DIR)

clean:
	$(MAKE) -sC $(LFT_DIR) clean
	$(MAKE) -sC $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(MLX)
	rm -f $(LFT)
	rm -f $(NAME)

re: fclean all
