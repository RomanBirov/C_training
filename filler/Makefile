# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbirov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/13 10:31:14 by rbirov            #+#    #+#              #
#    Updated: 2019/07/29 14:59:22 by rbirov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rbirov.filler

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBS = -lmlx -lm -lft -L$(LFT_DIR) -L$(MLX_DIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEAD_DIR) -I$(LFT_HEAD) -I$(MLX_HEAD)

VIS = $(VID_DIR)visual
VIS_DIR = ./fill_vis

LFT = $(LFT_DIR)libft.a
LFT_DIR = ./libft/
LFT_HEAD = $(LFT_DIR)includes/

MLX = $(MLX_DIR)libmlx.a
MLX_DIR = ./minilibx_macos/
MLX_HEAD = $(MLX_DIR)

HEAD_NAME = filler.h

HEAD_DIR = ./includes/
HEADS = $(addprefix $(HEAD_DIR), $(HEAD_NAME))

SRC_DIR = ./src/
SRC_NAME = check.c fill_algoritm.c get_position.c main.c place.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_DIR = objects/
OBJ_NAME = $(patsubst %.c, %.o, $(SRC_NAME))
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(LFT) $(MLX) $(VIS) $(OBJ_DIR) $(OBJS)
	$(CC) $(FLAGS) $(LIBS) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(VIS):
	$(MAKE) -sC $(VIS_DIR)

$(LFT):
	$(MAKE) -sC $(LFT_DIR)

$(MLX):
	$(MAKE) -sC $(MLX_DIR)

clean:
	$(MAKE) -sC $(LFT_DIR) clean
	$(MAKE) -sC $(MLX_DIR) clean
	$(MAKE) -sC $(VIS_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(MLX)
	rm -f $(LFT)
	rm -f $(VIS)
	rm -f $(NAME)

re: fclean all
