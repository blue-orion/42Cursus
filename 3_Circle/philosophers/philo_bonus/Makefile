# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 18:04:19 by takwak            #+#    #+#              #
#    Updated: 2025/03/17 21:06:05 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc -Wall -Werror -Wextra
FLAGS = -g

SRCS = ft_philo_atoi_bonus.c	\
	   main_bonus.c				\
	   make_common_bonus.c		\
	   make_philos_bonus.c		\
	   monitoring_bonus.c		\
	   philo_act_bonus.c		\
	   philo_routine_bonus.c	\
	   save_info_bonus.c		\
	   semaphore_bonus.c		\
	   utils_bonus.c

OBJ_DIR = objs/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME)

$(OBJ_DIR)%.o : %.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $^ -o $@

$(OBJ_DIR) :
	mkdir $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all
