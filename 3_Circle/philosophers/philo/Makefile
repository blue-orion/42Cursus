# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 22:11:52 by takwak            #+#    #+#              #
#    Updated: 2024/12/21 23:00:05 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = clang
CFLAGS = -g

INCLUDES = includes
SRC_DIR = srcs/
OBJ_DIR = objs/

MAIN = philosophers.c
SRCS = monitoring.c		\
	   timestamp.c	\
	   ft_atoi.c	\
	   make_thread.c	\
	   behavior.c			\
	   fork.c			\
	   save_info.c
OBJS = $(addprefix $(OBJ_DIR), $(MAIN:.c=.o) $(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	export ASAN_OPTIONS=detect_leaks=1 
	$(CC) $(CFLAGS) $^ -o $@ -MJ $@.part.json

$(OBJ_DIR)%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -I$(INCLUDES) -o $@ -MJ $@.part.json


$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -I$(INCLUDES) -o $@ -MJ $@.part.json


$(OBJ_DIR) :
	mkdir -p $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)
re : fclean all

compile_commands.json :
	-$(MAKE) --always-make --keep-going all
	(echo '[' && cat $(OBJ_DIR)*.part.json && echo ']') > $@

.PHONY: compile_commands.json
