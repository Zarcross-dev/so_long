# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 16:01:00 by beboccas          #+#    #+#              #
#    Updated: 2024/09/21 03:36:40 by beboccas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	gcc
MAKEFLAGS += --silent
CFLAGS	=	-Wall -Werror -Wextra -Imlx_linux -g
LDFLAGS =	-Lmlx_linux -L/usr/lib -lXext -lX11 -lm -lz 

SRC		=	srcs/so_long.c \
			srcs/error_handler.c \
			srcs/exit_handler.c \
			srcs/exit_handler_utils.c \
			srcs/input_handler.c \
			srcs/moves_handler.c \
			srcs/moves_handler_utils.c \
			srcs/map_utils.c \
			srcs/player_utils.c \
			srcs/draw_map.c \
			srcs/draw_map_utils.c \
			srcs/init.c \
			srcs/init_map.c \
			srcs/init_utils.c \
			srcs/path_finding.c \
			srcs/path_finding_utils.c \
			srcs/init_assets.c
			
SRC		+=	libs/gnl/get_next_line.c \
			libs/gnl/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

MINILIBX_LIB_PATH = libs/minilibx-linux/
LIBFT_LIB_PATH = libs/libft/
FT_PRINTF_LIB_PATH = libs/ft_printf/

MINILIBX_LIB := libs/minilibx-linux/libmlx.a
LIBFT_LIB = libs/libft/libft.a
FT_PRINTF_LIB = libs/ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(MINILIBX_LIB) $(LIBFT_LIB) $(FT_PRINTF_LIB) 
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Compilation de $@" "\033[32mOK\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)
	@echo "Compilation de $@" "\033[32mOK\033[0m"

$(LIBFT_LIB):
	@echo "$$LIB_HEADER"
	@make -C $(LIBFT_LIB_PATH) all bonus --no-print-directory

$(FT_PRINTF_LIB):
	@echo "$$LIB_HEADER"
	@make -C $(FT_PRINTF_LIB_PATH) all --no-print-directory

$(MINILIBX_LIB):
	@echo "$$LIB_HEADER"
	@make -C $(MINILIBX_LIB_PATH) all > /dev/null 2>&1

clean:
	rm -f $(OBJ)
	@make -C $(LIBFT_LIB_PATH) clean
	@make -C $(FT_PRINTF_LIB_PATH) clean
	@make -C $(MINILIBX_LIB_PATH) clean

fclean: clean
	@make -C $(LIBFT_LIB_PATH) fclean
	@make -C $(FT_PRINTF_LIB_PATH) fclean
	@make -C $(MINILIBX_LIB_PATH) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
