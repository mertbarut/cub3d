# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 22:19:01 by mbarut            #+#    #+#              #
#    Updated: 2021/12/30 18:59:51 by dmylonas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3d

SRC=src/cub_draw.c			src/cub_init.c			src/texture_init.c		\
	src/cub_read.c			src/cub_render.c		src/cub_exit.c			\
	src/cub_file.c			src/pixel_put.c									\
	src/player_init.c		src/cub_key.c			src/img_init.c			\
	src/player_move.c		src/player_rotate.c 							\
	src/parsing/parse.c		src/parsing/for_map.c							\
	src/parsing/for_settings.c						src/parsing/extra.c		\
	src/parsing/parsing_color.c

LIBSRC=libft/ft_atoi.c		libft/ft_calloc.c		libft/ft_isalpha.c		\
	libft/ft_isdigit.c		libft/ft_isascii.c		libft/ft_itoa_base.c	\
	libft/ft_memchr.c		libft/ft_memcpy.c		libft/ft_memset.c		\
	libft/ft_memdel.c		libft/ft_memmove.c		libft/ft_itoa.c			\
	libft/ft_putendl_fd.c	libft/ft_putstr_fd.c	libft/ft_putchar_fd.c	\
	libft/ft_strchr.c		libft/ft_strjoin.c		libft/ft_strlcpy.c		\
	libft/ft_strnew.c		libft/ft_strdel.c		libft/ft_strsub.c		\
	libft/ft_strmapi.c		libft/ft_strnstr.c		libft/ft_isalnum.c		\
	libft/ft_strtrim.c		libft/ft_tolower.c		libft/ft_bzero.c		\
	libft/ft_isprint.c		libft/ft_memccpy.c		libft/ft_memcmp.c		\
	libft/ft_putnbr_fd.c	libft/ft_split.c		libft/ft_strdup.c		\
	libft/ft_strlcat.c		libft/ft_strlen.c		libft/ft_strncmp.c		\
	libft/ft_strrchr.c		libft/ft_substr.c		libft/ft_toupper.c		\
	libft/ft_lstadd_back.c	libft/ft_lstadd_front.c	libft/ft_lstclear.c		\
	libft/ft_lstdelone.c	libft/ft_lstiter.c		libft/ft_lstsize.c		\
	libft/ft_lstlast.c		libft/ft_lstmap.c		libft/ft_lstnew.c

GNL=gnl/get_next_line.c

DRIVER=driver/main.c

OS := $(shell uname)

CC=gcc

CFLAGS_LINUX= minilibx/libmlx.a -lXext -lX11 -lm -lz -o

CFLAGS_MACOS= minilibx/libmlx.a -L/usr/X11/lib -lXext -lX11 -lm -lz -o 

ifeq ($(OS), Darwin)
CFLAGS= $(CFLAGS_MACOS)
else
CFLAGS= $(CFLAGS_LINUX)
endif

LIBDIR=./libft

LIBFT=libft/libft.a

GNLDIR=./gnl

MINILIBX_DIR=./minilibx

all: $(NAME)

$(NAME): $(SRC)
	make all -C $(LIBDIR)
	make all -C $(MINILIBX_DIR)
	$(CC) -g $(DRIVER) $(SRC) $(GNL) $(LIBFT) $(CFLAGS) $(NAME)

clean:
	@rm -f ./*.o $(LIBDIR)/*.o $(GNLDIR)/*.o

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBDIR)
	@rm -rf ./cub3d.dSYM
	@make clean -C $(MINILIBX_DIR)

re: fclean all

fast:
	$(CC) -g $(DRIVER) $(SRC) $(GNL) $(LIBFT) $(CFLAGS) $(NAME)

norm:
	norminette $(SRC) $(LIBSRC) $(DRIVER) src/*.h libft/*.h gnl/*.h

memcheck: $(NAME)
	valgrind --leak-check=full ./fdf maps/42.fdf

test: $(NAME)
	./fdf maps/42.fdf
