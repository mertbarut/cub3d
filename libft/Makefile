# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 21:57:20 by mbarut            #+#    #+#              #
#    Updated: 2021/12/12 14:12:41 by mbarut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRC=ft_atoi.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_itoa.c ft_itoa_base.c \
	ft_memchr.c ft_memcpy.c ft_memset.c ft_putendl_fd.c ft_putstr_fd.c \
	ft_strchr.c ft_strjoin.c ft_strlcpy.c ft_strmapi.c ft_strnstr.c \
	ft_strtrim.c ft_tolower.c ft_bzero.c  ft_isalnum.c  ft_isascii.c \
	ft_isprint.c ft_memccpy.c ft_memcmp.c ft_memmove.c ft_putchar_fd.c \
	ft_putnbr_fd.c ft_split.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncmp.c \
	ft_strrchr.c ft_substr.c ft_toupper.c ft_strsub.c ft_strnew.c ft_strdel.c \
	ft_memdel.c ft_split_free.c

SRCBONUS=ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdelone.c ft_lstiter.c ft_lstsize.c \
		ft_lstlast.c ft_lstmap.c ft_lstnew.c \

OBJ=ft_atoi.o ft_calloc.o ft_isalpha.o ft_isdigit.o ft_itoa.o ft_itoa_base.o \
	ft_memchr.o ft_memcpy.o ft_memset.o ft_putendl_fd.o ft_putstr_fd.o \
	ft_strchr.o ft_strjoin.o ft_strlcpy.o ft_strmapi.o ft_strnstr.o \
	ft_strtrim.o ft_tolower.o ft_bzero.o  ft_isalnum.o  ft_isascii.o \
	ft_isprint.o ft_memccpy.o ft_memcmp.o ft_memmove.o ft_putchar_fd.o \
	ft_putnbr_fd.o ft_split.o ft_strdup.o ft_strlcat.o ft_strlen.o ft_strncmp.o \
	ft_strrchr.o ft_substr.o ft_toupper.o ft_strsub.o ft_strnew.o ft_strdel.o \
	ft_memdel.o ft_split_free.o

OBJBONUS=ft_lstadd_back.o ft_lstadd_front.o ft_lstclear.o \
		ft_lstdelone.o ft_lstiter.o ft_lstsize.o \
		ft_lstlast.o ft_lstmap.o ft_lstnew.o \
		
CFLAGS= -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	gcc $(CFLAGS) $(SRC)

$(OBJBONUS): $(SRCBONUS)
	gcc $(CFLAGS) $(SRCBONUS)

clean:
	@rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	@rm -f $(NAME) $(NAMEBONUS)

re: fclean all

bonus: fclean $(OBJ) $(OBJBONUS) 
	@ar rcs $(NAME) $(OBJ) $(OBJBONUS)

norm:
	norminette $(SRC) $(SRCBONUS) *.h
