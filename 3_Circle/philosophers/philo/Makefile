# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 15:57:39 by takwak            #+#    #+#              #
#    Updated: 2025/01/15 15:33:18 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -g

SRC_DIR = srcs/
OBJ_DIR = objs/
INCLUDES = includes/

SRCS = philosophers.c	\
	   end_process.c	\
	   get_time.c		\
	   monitoring.c		\
	   philo_act.c		\
	   philo_routine.c	\
	   philo_utils.c	\
	   print_log.c		\
	   set_init_state.c	\
	   util_atoi.c		\
	   util_destory.c

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -I$(INCLUDES) -o $@


$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -I$(INCLUDES) -o $@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: NAME all clean fclean re
