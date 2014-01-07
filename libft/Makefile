#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:02:18 by greyrol           #+#    #+#              #
#    Updated: 2013/12/29 13:26:52 by greyrol          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = libft
EXT = a
TARGET = $(NAME).$(EXT)
PLATFORM = $(shell uname -s && uname -m)
INC_DIR = ./inc
SRC_DIR = ./src
OBJ_DIR = ./obj

UNITS = $(shell ls $(SRC_DIR)| grep .c)
UNITS_O = $(UNITS:.c=.o)

SRCS = $(patsubst %,$(SRC_DIR)/%,$(UNITS))
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(UNITS_O))

FLAGS = -Wall -Wextra -Werror -std=c89 -pedantic
CFLAGS = $(FLAGS) -ggdb

CC = clang $(CFLAGS)
LD = ar rcs
RM = /bin/rm -f

all: $(TARGET)

infos:
	@echo "Platform: \c" && echo $(PLATFORM)

$(TARGET): $(OBJS)
	@$(LD) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c -I$(INC_DIR) -o $@ $<


clean:
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(TARGET)

re: fclean all

.PHONY: clean fclean all re infos
