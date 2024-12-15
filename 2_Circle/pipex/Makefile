# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 18:41:57 by takwak            #+#    #+#              #
#    Updated: 2024/12/15 22:37:27 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wextra -Wall -g

INCLUDES = includes
SRC_DIR = srcs/
OBJ_DIR = objs/

LIBFT = srcs/libft

NAME = pipex

SRC_MAIN = pipex.c
SRCS = command_exec_bonus.c		\
	   command_split_bonus.c	\
	   find_paths_bonus.c		\
	   here_doc_bonus.c			\
	   process_bonus.c			\
	   utils_bonus.c			\
	   utils_free_bonus.c	

OBJS = $(addprefix $(OBJ_DIR), $(SRC_MAIN:.c=.o) $(SRCS:.c=.o))

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
