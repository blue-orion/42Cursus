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
SRC_MAIN_BONUS = main_bonus.c

SRC_DIR = srcs/
SRCS = process.c		\
	   utils.c			\
	   utils_free.c		\
	   cmd_exe.c		\
	   cmd_list.c		\
	   cmd_parse.c		\
	   debugging.c		\
	   find_path_env.c	

SRCS_BONUS = command_exec_bonus.c	\
			 command_split_bonus.c	\
			 find_paths_bonus.c		\
			 here_doc_bonus.c		\
			 process_bonus.c		\
			 utils_bonus.c			\
			 utils_free_bonus.c	

INCLUDES = includes
OBJ_DIR = objs/

ifdef WITH_BONUS
	OBJS = $(addprefix $(OBJ_DIR), $(SRC_MAIN_BONUS:.c=.o) $(SRCS_BONUS:.c=.o))
else
	OBJS = $(addprefix $(OBJ_DIR), $(SRC_MAIN:.c=.o) $(SRCS:.c=.o))
endif

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

bonus : fclean
	make WITH_BONUS=1 all
