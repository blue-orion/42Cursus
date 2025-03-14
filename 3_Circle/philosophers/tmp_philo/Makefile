# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 18:04:19 by takwak            #+#    #+#              #
#    Updated: 2025/03/14 18:09:31 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
FLAGS = -g

SRCS = free_resources.c	\
	   ft_philo_atoi.c	\
	   ft_usleep.c		\
	   get_runtime.c	\
	   main.c			\
	   make_common_resources.c	\
	   make_philos.c	\
	   philo_act.c	\
	   philo_routine.c	\
	   philo_utils.c	\
	   print_log.c	\
	   save_info.c

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
