#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/11 05:27:36 by greyrol           #+#    #+#              #
#    Updated: 2014/01/18 18:01:16 by greyrol          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

LIB_EXT = a

LIBFT_NAME = libft
LIBFT_TARGET = $(LIBFT_NAME).$(LIB_EXT)
LIBFT_DIR = ./$(LIBFT_NAME)
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT_TARGET)

INC_DIR = inc -I $(LIBFT_DIR)/inc
SRC_DIR = ./src
OBJ_DIR = ./obj

UNITS = main.c ft_hook.c ft_render.c ft_action.c ft_drw.c ft_env.c \
		ft_map.c

UNITS_O = $(UNITS:.c=.o)
SRCS = $(patsubst %,$(SRC_DIR)/%,$(UNITS))
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(UNITS_O))
FLAGS = -Wall -Wextra -Werror -std=c89 -ansi -pedantic -Qunused-arguments
CFLAGS = $(FLAGS) -g
LDFLAGS = $(LIBFT_LIB) -L/usr/X11/lib -lXext -lX11 -lmlx -lm
CC = clang $(CFLAGS)
LD = $(CC) -o $(NAME)
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(LIBOPT_LIB) 
	@$(LD) $^  $(LDFLAGS)
	@printf 'Building binary : %s\n' "$(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c -I$(INC_DIR) -o $@ $<

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)
	@printf 'Building library : libft.a\n'

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean fclean all re
