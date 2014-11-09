#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:02:18 by greyrol           #+#    #+#              #
#    Updated: 2014/02/28 15:56:51 by greyrol          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
NAME_D = libft_d.a

INC_DIR = ./inc
SRC_DIR = ./src
OBJ_DIR = ./obj
OBJ_DEBUG_DIR = $(OBJ_DIR)/debug
OBJ_RELEASE_DIR = $(OBJ_DIR)/release

UNITS = ft_ftoa.c            ft_atoi.c \
	ft_putchar_fd.c \
	ft_atol.c                ft_putendl.c \
	ft_bzero.c               ft_putendl_fd.c \
	ft_dlist_add_back.c      ft_dlist_dup.c \
	ft_dlist_add_front.c     ft_dlist_init.c \
	ft_dlist_clear.c         ft_dlist_node.c \
	ft_dlist_copy.c          ft_dlist_remove.c \
	ft_dlist_destroy.c       ft_putnbr.c \
	ft_dlist_node.c          ft_putnbr_fd.c \
	ft_dlist_new.c \
	ft_error.c               ft_putstr.c \
	ft_file_access.c         ft_putstr_fd.c \
	ft_readdir.c \
	ft_fprintf.c             ft_realloc.c \
	ft_getline.c \
	ft_isalnum.c             ft_strcat.c \
	ft_isalpha.c             ft_strchr.c \
	ft_isanyof.c             ft_strclr.c \
	ft_isascii.c             ft_strcmp.c \
	ft_isdigit.c             ft_strcpy.c \
	ft_isempty.c             ft_strdel.c \
	ft_islower.c             ft_strdup.c \
	ft_isprint.c             ft_strempty.c \
	ft_isspace.c             ft_strequ.c \
	ft_isupper.c             ft_strfind.c \
	ft_itoa.c                ft_striter.c \
	ft_lstadd.c              ft_striteri.c \
	ft_lstback.c             ft_strjoin.c \
	ft_lstdel.c              ft_strlcat.c \
	ft_lstdelone.c           ft_strlen.c \
	ft_lsteq.c               ft_strmap.c \
	ft_lstfront.c            ft_strmapi.c \
	ft_lstiter.c             ft_strmatch.c \
	ft_lstlast.c             ft_strncat.c \
	ft_lstmap.c              ft_strncmp.c \
	ft_lstneq.c              ft_strncpy.c \
	ft_lstnew.c              ft_strndup.c \
	ft_lstpop_back.c         ft_strnequ.c \
	ft_lstpop_front.c        ft_strnew.c \
	ft_lstpush_back.c        ft_strnstr.c \
	ft_lstpush_front.c       ft_strrchr.c \
	ft_lstsize.c             ft_strrev.c \
	ft_memalloc.c            ft_strsplit.c \
	ft_memccpy.c             ft_strstr.c \
	ft_memchr.c              ft_strsub.c \
	ft_memcmp.c              ft_strtok.c \
	ft_memcpy.c              ft_strtolower.c \
	ft_memdel.c              ft_strtoupper.c \
	ft_memdup.c              ft_strtrim.c \
	ft_strrtrim.c            ft_strltrim.c \
	ft_strrot.c              ft_strfind_any.c \
	ft_memmove.c             ft_swap.c \
	ft_memrealloc.c          ft_tokdel.c \
	ft_memset.c              ft_tolower.c \
	ft_ntoa.c                ft_toupper.c \
	ft_number_length.c       ft_version.c \
	ft_opendir.c             ft_vfprintf.c \
	ft_parse_printf_char.c   ft_vprintf.c \
	ft_printf.c              ft_vsnprintf.c \
	ft_printf_do_bool.c      ft_vsnprintf_char.c \
	ft_printf_do_char.c      ft_vsnprintf_float.c \
	ft_printf_do_int.c       ft_vsnprintf_hexa.c \
	ft_printf_do_numbers.c   ft_vsnprintf_loop.c \
	ft_printf_do_pointers.c  ft_vsnprintf_signed.c \
	ft_printf_do_string.c    ft_vsnprintf_step.c \
	ft_printf_parse_width.c  ft_vsnprintf_string.c \
	ft_putchar.c             ft_vsnprintf_unsigned.c \
	ft_lstswap.c			 ft_lstsort.c

UNITS_O = $(UNITS:.c=.o)

SRCS = $(patsubst %,$(SRC_DIR)/%,$(UNITS))
OBJS = $(patsubst %,$(OBJ_RELEASE_DIR)/%,$(UNITS_O))
OBJS_D = $(patsubst %,$(OBJ_DEBUG_DIR)/%,$(UNITS_O))

include Version.mak

FLAGS = -Wall -Wextra -Werror -std=c89 -pedantic $(VERSION_FLAGS)
CFLAGS = $(FLAGS)
CFLAGS_D = $(FLAGS) -ggdb -D_DEBUG

CC = clang $(CFLAGS)
CC_D = clang $(CFLAGS_D)
LD = ar rcs
RM = /bin/rm -f

all: $(NAME) $(NAME_D)

debug: $(NAME_D)
release: $(NAME)

$(NAME): $(OBJS) $(VERSION_FILE)
	@printf "\r\033[KLinking $@\n"
	@$(LD) $@ $^

$(NAME_D): $(OBJS_D) $(VERSION_FILE)
	@printf "\r\033[KLinking $@\n"
	@$(LD) $@ $^

$(OBJ_DEBUG_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "\r\033[KCompiling $< into $@"
	@$(CC_D) -c -I$(INC_DIR) -o $@ $<

$(OBJ_RELEASE_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "\r\033[KCompiling $< into $@"
	@$(CC) -c -I$(INC_DIR) -o $@ $<


clean:
	@echo Removing objects
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_D)

fclean : clean
	@echo Removing targets
	@$(RM) $(NAME)
	@$(RM) $(NAME_D)

re: fclean all

.PHONY: clean fclean all re debug release
