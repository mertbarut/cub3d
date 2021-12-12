# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 22:19:01 by mbarut            #+#    #+#              #
#    Updated: 2021/12/12 14:16:55 by mbarut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

SRC=src/fdf_init.c			src/fdf_read.c			src/fdf_map.c			\
	src/fdf_close.c															\
	src/map_init.c			src/map_draw.c			src/map_move.c			\
	src/map_reset.c															\
	src/pixel_new.c			src/pixel_put.c			src/pixels_free.c		\
	src/gnl_column_count.c													\
	src/map_render.c	

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

CC=gcc

CFLAGS= -lmlx -lXext -lX11 -lm -lz -o

LIBDIR=./libft

LIBFT=libft/libft.a

GNLDIR=./gnl

all: $(NAME)

$(NAME):
	make all -C $(LIBDIR)
	$(CC) -L/usr/local/lib -I/usr/local/include -g $(DRIVER) $(SRC) $(GNL) $(LIBFT) $(CFLAGS) $(NAME)

clean:
	@rm -f ./*.o $(LIBDIR)/*.o $(GNLDIR)/*.o

fclean: clean
	@rm -f $(NAME) $(LIBFT)

re: fclean all

norm:
	norminette $(SRC) $(LIBSRC) $(DRIVER) src/*.h libft/*.h gnl/*.h

memcheck: $(NAME)
	valgrind --leak-check=full ./fdf maps/42.fdf

test: $(NAME)
	./fdf maps/42.fdf
