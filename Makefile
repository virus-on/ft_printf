# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 14:47:29 by mpaziuk           #+#    #+#              #
#    Updated: 2018/05/23 18:10:09 by mpaziuk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I includes/

FILES = ft_printf.c\
		ft_printf_two.c\
		ft_character.c\
		ft_color.c\
		ft_decimal.c\
		ft_etc.c\
		ft_flags.c\
		ft_flags_detail.c\
		ft_itoa.c\
		ft_length.c\
		ft_llitoa_base.c\
		ft_pointer.c\
		ft_unsigned.c\
		ft_string.c\
		ft_wide_str.c\
		ft_wide_char.c

LIBFILES =	ft_atoi.c \
			ft_bzero.c \
			ft_integerlen.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_iswhite.c \
			ft_itoa_base.c \
			ft_llinterlen.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstnew.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_wordcount.c \
			ft_wordlen.c \
			get_next_line.c 

PRINTFSRCS = $(addprefix src/, $(FILES))
LIBSRCS = $(addprefix src/libft/, $(LIBFILES))

OBJ = $(PRINTFSRCS:.c=.o)
LIBOBJ = $(LIBSRCS:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
	gcc -c $(CFLAGS) $< -o $@

$(LIBOBJ): %.o: %.c
	gcc -c $(CFLAGS) $< -o $@

$(NAME): $(LIBOBJ) $(OBJ)
	ar rcs $(NAME) $(OBJ) $(LIBOBJ)

clean:
	rm -rf $(OBJ) $(LIBOBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY = all clean fclean re
