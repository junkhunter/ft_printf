# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhunders <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 20:45:42 by rhunders          #+#    #+#              #
#    Updated: 2019/01/11 11:30:40 by rhunders         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c  ft_memcpy.c ft_memdel.c ft_memmove.c \
		ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
		ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c \
		ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
		ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
		ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
		ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
		ft_toupper.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
		ft_lstiter.c ft_lstmap.c ft_convert_base.c ft_count_word.c \
		ft_atoi_base.c ft_lstadd_back.c ft_lst_read.c ft_itoa_base.c \
		ft_tabclear.c ft_lstclear.c

LIBFT = $(addprefix libft/, $(LIBFT_SRC))

SRC	=	ft_printf.c \
		ft_select_arg.c \
		outil.c \
		outil_2.c \
		outil_3.c \
		print_diu.c \
		print_f.c \
		print_ox.c \
		print_sbc.c \
		print_percent.c \
		invalid_conv.c

OBJ	= $(SRC:.c=.o) $(LIBFT_SRC:.c=.o)

NAME = libftprintf.a

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC) $(LIBFT) -I libft/include/ -I include/
	@ar rcs libftprintf.a $(OBJ)
	@echo "-COMPILATION DONE-"

all : $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C libft/
	@echo "-CLEANED-"

fclean:	clean
	@rm -f $(NAME) $(OBJ)
	@make fclean -C libft/
	@echo "-FCLEANED-"

re:	fclean all
