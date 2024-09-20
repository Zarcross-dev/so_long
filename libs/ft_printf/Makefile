# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 16:52:35 by beboccas          #+#    #+#              #
#    Updated: 2023/10/22 16:52:35 by beboccas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re out
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	srcs/ft_printf_utils \
		srcs/ft_printf \
		srcs/ft_print_char \
		srcs/ft_print_str \
		srcs/ft_print_int \
		srcs/ft_put_digit \
		srcs/ft_put_upper_digit \
		srcs/ft_print_pointer \
		srcs/ft_print_unsigned_int

CFILES= $(SRCS:%=%.c)
OFILES= $(CFILES:.c=.o)

LIBFT = libft.a
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OFILES)
	ar -rc $(NAME) $(OFILES)	

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)
	@echo "FT_PRINTF: Objects files deleted."


fclean: clean
	rm -f $(NAME)
	@echo "FT_PRINTF: The ${NAME} deleted."


re: fclean all

out : 
	gcc srcs/*.c -Wall -Wextra -Werror -g -fsanitize=leak