# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 22:19:01 by mbarut            #+#    #+#              #
#    Updated: 2022/01/03 15:48:26 by dmylonas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3D

SRC=src/cub_draw.c			src/cub_init.c			src/texture_init.c		\
	src/cub_render.c		src/cub_exit.c									\
	src/player_init.c		src/cub_key.c			src/img_init.c			\
	src/player_move.c		src/player_rotate.c 							\
	src/cubfile_checkmap.c  src/cubfile_checkspaces.c						\
	src/cubfile_configure.c src/cubfile_error.c  	src/cubfile_fillmap.c	\
	src/cubfile_handle.c	src/cubfile_parsecolor.c						\
	src/cub_args.c			src/cub_boot.c									\
	src/cub_raycast.c

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
	libft/ft_strcmp.c

OBJ=src/cub_draw.o			src/cub_init.o			src/texture_init.o		\
	src/cub_render.o		src/cub_exit.o									\
	src/player_init.o		src/cub_key.o			src/img_init.o			\
	src/player_move.o		src/player_rotate.o 							\
	src/cubfile_checkmap.o  src/cubfile_checkspaces.o						\
	src/cubfile_configure.o src/cubfile_error.o  	src/cubfile_fillmap.o	\
	src/cubfile_handle.o	src/cubfile_parsecolor.o						\
	src/cub_args.o			src/cub_boot.o									\
	src/cub_raycast.o

LIBOBJ=libft/ft_atoi.o		libft/ft_calloc.o		libft/ft_isalpha.o		\
	libft/ft_isdigit.o		libft/ft_isascii.o		libft/ft_itoa_base.o	\
	libft/ft_memchr.o		libft/ft_memcpy.o		libft/ft_memset.o		\
	libft/ft_memdel.o		libft/ft_memmove.o		libft/ft_itoa.o			\
	libft/ft_putendl_fd.o	libft/ft_putstr_fd.o	libft/ft_putchar_fd.o	\
	libft/ft_strchr.o		libft/ft_strjoin.o		libft/ft_strlcpy.o		\
	libft/ft_strnew.o		libft/ft_strdel.o		libft/ft_strsub.o		\
	libft/ft_strmapi.o		libft/ft_strnstr.o		libft/ft_isalnum.o		\
	libft/ft_strtrim.o		libft/ft_tolower.o		libft/ft_bzero.o		\
	libft/ft_isprint.o		libft/ft_memccpy.o		libft/ft_memcmp.o		\
	libft/ft_putnbr_fd.o	libft/ft_split.o		libft/ft_strdup.o		\
	libft/ft_strlcat.o		libft/ft_strlen.o		libft/ft_strncmp.o		\
	libft/ft_strrchr.o		libft/ft_substr.o		libft/ft_toupper.o		\
	libft/ft_strcmp.o

GNL=gnl/get_next_line.c

GNLOBJ=gnl/get_next_line.o

DRIVER=driver/main.c

OS := $(shell uname)

CC=cc

CFLAGS_LINUX= -Wall -Wextra -Werror minilibx/libmlx.a -lXext -lX11 -lm -lz -o

CFLAGS_MACOS= -Wall -Wextra -Werror minilibx/libmlx.a -L/usr/X11/lib -lXext -lX11 -lm -lz -o

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
	@rm -f $(GNLOBJ) $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBDIR)
	@rm -rf ./cub3d.dSYM
	@make clean -C $(MINILIBX_DIR)

re: fclean all

fast:
	$(CC) -g $(DRIVER) $(SRC) $(GNL) $(LIBFT) $(CFLAGS) $(NAME)

norm:
	norminette $(SRC) $(LIBSRC) $(GNL) $(DRIVER) src/cub.h libft/libft.h gnl/get_next_line.h

memcheck: $(NAME)
	valgrind --leak-check=full ./fdf maps/42.fdf

test: $(NAME)
	./cub3D maps/map.cub
