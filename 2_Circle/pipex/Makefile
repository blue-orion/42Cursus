# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 18:41:57 by takwak            #+#    #+#              #
#    Updated: 2024/12/12 00:44:57 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wextra -Wall -g

NAME = pipex

SRC_MAIN = main.c
SRC_DIR = srcs/
SRCS = process.c		\
	   utils.c			\
	   utils_free.c		\
	   cmd_exe.c		\
	   cmd_list.c		\
	   cmd_parse.c		\
	   debugging.c		\
	   find_path_env.c	

INCLUDES = includes
OBJ_DIR = objs/
OBJS = $(addprefix $(OBJ_DIR), main.o $(SRCS:.c=.o))

LIBFT = srcs/libft

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $^ -I$(INCLUDES) -L$(LIBFT) -lft -o $@

$(OBJ_DIR)%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -I$(INCLUDES) -o $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -I$(INCLUDES) -o $@

$(OBJ_DIR) :
	mkdir -p $@

clean :
	make -C $(LIBFT) clean
	rm -rf objs

fclean : clean
	make -C $(LIBFT) fclean
	rm -rf $(NAME)

re : fclean all
