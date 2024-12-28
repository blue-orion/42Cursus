# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 22:11:52 by takwak            #+#    #+#              #
#    Updated: 2024/12/29 01:37:54 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = clang
CFLAGS = -g

INCLUDES = includes
SRC_DIR = srcs/
OBJ_DIR = objs/

MAIN = philosophers_bonus.c
SRCS = ft_atoi_bonus.c				\
	   get_time_bonus.c				\
	   make_common_source_bonus.c	\
	   monitoring_bonus.c			\
	   philo_act_bonus.c			\
	   philo_behavior_bonus.c		\
	   print_log_bonus.c			\
	   save_info_bonus.c			\
	   set_initial_state_bonus.c	\
	   utils_bonus.c				\
	   exit_bonus.c	

OBJS = $(addprefix $(OBJ_DIR), $(MAIN:.c=.o) $(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

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

.PHONY: NAME all clean fclean re compile_commands.json
compile_commands.json:
	-$(MAKE) --always-make --keep-going all
	(echo '[' && cat $(OBJ_DIR)*.part.json && echo ']') > $@

