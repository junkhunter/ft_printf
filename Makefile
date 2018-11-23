# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhunders <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 20:45:42 by rhunders          #+#    #+#              #
#    Updated: 2018/11/23 14:21:29 by rhunders         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
LIBFT = libft/ft_atoi.c libft/ft_bzero.c libft/ft_isalnum.c \
		libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c \
		libft/ft_isprint.c libft/ft_itoa.c libft/ft_memalloc.c \
		libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c \
		libft/ft_memcpy.c libft/ft_memdel.c libft/ft_memmove.c \
		libft/ft_memset.c libft/ft_putchar.c libft/ft_putchar_fd.c \
		libft/ft_putendl.c libft/ft_putendl_fd.c libft/ft_putnbr.c \
		libft/ft_putnbr_fd.c libft/ft_putstr.c libft/ft_putstr_fd.c \
		libft/ft_strcat.c libft/ft_strchr.c libft/ft_strclr.c \
		libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdel.c \
		libft/ft_strdup.c libft/ft_strequ.c libft/ft_striter.c \
		libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c \
		libft/ft_strlen.c libft/ft_strmap.c libft/ft_strmapi.c \
		libft/ft_strncat.c libft/ft_strncmp.c libft/ft_strncpy.c \
		libft/ft_strnequ.c libft/ft_strnew.c libft/ft_strnstr.c \
		libft/ft_strrchr.c libft/ft_strsplit.c libft/ft_strstr.c \
		libft/ft_strsub.c libft/ft_strtrim.c libft/ft_tolower.c \
		libft/ft_toupper.c libft/ft_lstnew.c libft/ft_lstdelone.c \
		libft/ft_lstdel.c libft/ft_lstadd.c libft/ft_lstiter.c \
		libft/ft_lstmap.c libft/ft_convert_base.c libft/ft_count_word.c \
		libft/ft_atoi_base.c libft/ft_lstadd_back.c \
		libft/ft_lst_read.c libft/ft_itoa_base.c \
		libft/ft_tabclear.c libft/ft_lstclear.c

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

SRC	=	ft_printf.c \
		ft_printf_display.c \
		ft_printf_flagfunctions.c \
		ft_printf_flagfunctions_second.c \
		converter_flagfunctions_long.c \
		converter_flagfunctions.c

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
