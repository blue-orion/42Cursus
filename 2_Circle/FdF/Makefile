# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 20:37:35 by takwak            #+#    #+#              #
#    Updated: 2025/02/09 19:49:22 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror -g

NAME = fdf

MAIN = fdf.c

SRC_PATH = srcs
SRCS = bresenham.c			\
	   close_program.c		\
	   debugging.c			\
	   event_hook.c			\
	   init.c				\
	   projection_conic.c	\
	   projection_isometric.c\
	   put_info_string.c	\
	   read_file.c			\
	   rendering.c			\
	   rendering_bresenham.c\
	   rotate.c				\
	   rotate_inverse.c		\
	   rotate_matrix.c		\
	   scale_matrix.c		\
	   translate.c			\
	   translate_matrix.c	\
	   utils.c				\
	   utils_matrix.c		\
	   utils_mlx.c			\
	   utils_vector.c		\
	   validate_name.c		\
	   view_matrix.c		\
	   zoom_in_and_out.c	
SRC = $(MAIN) $(addprefix $(SRC_PATH)/, $(SRCS))

OBJS_PATH = objs
OBJS = $(MAIN:.c=.o) $(SRCS:.c=.o)
OBJ = $(addprefix $(OBJS_PATH)/, $(OBJS))

# MLX_PATH
MLX = srcs/minilibx-linux
# MLX_INCLUDE
MLX_IN = -lmlx -lXext -lX11 -lm -lz

# LIBFT_PATH
LIBFT = srcs/libft

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(MLX)
	make -C $(LIBFT)
	$(CC) $(FLAGS) $^ -L$(MLX) $(MLX_IN) -L$(LIBFT) -lft -o $(NAME)

$(OBJS_PATH)/%.o : $(SRC_PATH)/%.c | $(OBJS_PATH)
	$(CC) $(FLAGS) -I$(MLX) -I$(LIBFT) -c $< -o $@

$(OBJS_PATH) :
	mkdir -p objs

clean :
	rm -rf $(OBJS_PATH)
	make fclean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
