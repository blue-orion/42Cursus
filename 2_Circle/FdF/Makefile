# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 20:37:35 by takwak            #+#    #+#              #
#    Updated: 2024/11/13 16:44:17 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror -g

NAME = fdf

MAIN = fdf.c

SRC_PATH = srcs
SRCS = read_file.c			\
	   ft_error.c			\
	   init.c				\
	   debugging.c			\
	   isometric.c			\
	   bresenham.c			\
	   matrix_transition.c 	\
	   optimize_win.c		\
	   utils.c

OBJS_PATH = objs
OBJS = $(MAIN:.c=.o) $(SRCS:.c=.o)

MLX_PATH = srcs/minilibx-linux
MLX_INCLUDE = -lmlx -lXext -lX11 -lm -lz

LIBFT = srcs/libft

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	$(CC) $(FLAGS) $(addprefix $(OBJS_PATH)/, $^) -L$(MLX_PATH) $(MLX_INCLUDE) -L$(LIBFT) -lft -o $(NAME)

$(OBJS) : $(OBJS_PATH)

$(OBJS_PATH) :
	mkdir objs

%.o : %.c
	$(CC) $(FLAGS) -I$(MLX_PATH) -I$(LIBFT) -c $< -o $(OBJS_PATH)/$@

clean :
	rm -rf $(OBJS_PATH)
	make fclean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re


