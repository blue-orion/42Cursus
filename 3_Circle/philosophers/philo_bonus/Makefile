# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 01:56:33 by takwak            #+#    #+#              #
#    Updated: 2024/12/29 04:43:12 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAG = -g

SRC_DIR = srcs/
OBJ_DIR = objs/
INCLUDE = includes/

MAIN = philosophers_bonus.c
SRCS = exit_bonus.c 				\
	   free_resources_bonus.c		\
       get_time_bonus.c				\
       monitoring_bonus.c			\
       philo_behavior_bonus.c		\
       philo_libft_bonus.c			\
       philo_main_bonus.c			\
       print_log_bonus.c			\
       set_initial_state_bonus.c	\
	   utils_bonus.c				\
	   utils_philo_bonus.c			\
	   wait_childs_bonus.c

OBJS = $(addprefix $(OBJ_DIR), $(MAIN:.c=.o) $(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $^ -I$(INCLUDE) -o $@

$(OBJ_DIR)%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAG) -I$(INCLUDE) -c $^ -o $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAG) -c $^ -I$(INCLUDE) -o $@

$(OBJ_DIR) :
	mkdir -p $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: NAME all clean fclean re
