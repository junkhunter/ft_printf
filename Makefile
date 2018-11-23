# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhunders <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 20:45:42 by rhunders          #+#    #+#              #
#    Updated: 2018/11/23 01:51:37 by rhunders         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	ft_printf.c \
		ft_printf_display.c \
		ft_printf_flagfunctions.c \
		ft_printf_flagfunctions_second.c \
		converter_flagfunctions_long.c \
		converter_flagfunctions.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libftprintf.a

$(NAME):
	make re -C libft/
	gcc -Wall -Wextra -Werror -c $(SRC) libft/*.c -I libft/include/ -I include/
	ar rc libftprintf.a *.o libft/*.o
	echo "-COMPILATION DONE-"

all : $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft/
	echo "-CLEANED-"

fclean:	clean
	rm -f $(NAME) $(OBJ)
	make fclean -C libft/
	echo "-FCLEANED-"

re:	fclean all
