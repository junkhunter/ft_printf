# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhunders <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 20:45:42 by rhunders          #+#    #+#              #
#    Updated: 2018/11/22 21:54:05 by rhunders         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	ft_printf.c \
		ft_printf_display.c \
		ft_printf_flagfunctions.c \
		ft_printf_flagfunctions_second.c \
		converter_flagfunctions.c

OBJ	=	$(SRC:.c=.o)

NAME	=	ft_printf

all:
	@make re -C libft/
	@gcc -Wall -Wextra -Werror -c $(SRC) libft/libft.a -I libft/include -I include/
	@gcc $(OBJ) -o $(NAME)
	@echo "-COMPILATION DONE-"

$(NAME) : all

clean:
	@rm -f $(OBJ)
	@echo "-CLEANED-"

fclean:	clean
	@rm -f $(NAME)
	@echo "-FCLEANED-"

re:	fclean all
