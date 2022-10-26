# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:13:11 by pjerddee          #+#    #+#              #
#    Updated: 2022/10/26 13:59:03 by pjerddee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Imlx_Linux -Lmlx_Linux -lmlx_Linux -lXext -lX11 -lm -lz

MLX_DIR = mlx_Linux/

SRCS =	src/main.c	\
		src/put.c	\
		src/utils.c	\
		src/map_init.c	\
		src/get_next_line.c	\
		src/get_next_line_utils.c

BUILD_DIR = build

INC_DIR = includes/

INCS = $(INC_DIR)fdf.h

LIBFT_DIR = libft/

INCLUDES = -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -I/usr/include -Iincludes 

LIBS = -L$(LIBFT_DIR) -lft -L/usr/lib

all: $(NAME)

libs:
	@make bonus -C $(LIBFT_DIR)
	@make clean -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

$(OBJS): $(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) libs
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) $(MLX_FLAGS) -o $(NAME)

cclean:
	-@rm -rf $(BUILD_DIR)
	-@rm -f $(NAME)

restart: cclean $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) $(MLX_FLAGS) -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	-@rm -rf $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	-@rm -f $(NAME)

re: fclean all

norm:
	norminette -R ForbiddenSourceHeader $(SRCS)
	norminette -R CheckDefine $(INCS)

.PHONY: all libs cclean restart nflag clean fclean re norm
